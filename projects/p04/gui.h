//
// Created by Hykilpikonna on 1/18/21.
//

#ifndef HOMEWORKS_WINDOW_H
#define HOMEWORKS_WINDOW_H

#include "gtkmm.h"
#include "macros.h"
#include "constants.h"

using namespace Gtk;

/**
 * Drawing area for GUI
 */
class MyArea: public DrawingArea
{
public:
    /**
     * Constructor
     */
    MyArea()
    {
        // Set draw callback function
        set_draw_func(sigc::mem_fun(*this, &MyArea::on_draw));
    }
    ~MyArea() override = default;

    /**
     * Draw GUI
     */
    void on_draw(const Cairo::RefPtr<Cairo::Context>& cr, int width, int height)
    {
        // Calculate values
        val xStart = gPadding;
        val yStart = gPadding;
        val fullWidth = gFullCellLen * rows;
        val xEnd = xStart + fullWidth;
        val yEnd = yStart + fullWidth;

        // Draw boarder lines
        cr->set_line_width(gBorderLen);
        cr->set_source_rgb(0.8, 0.0, 0.0);
        for (int row = 0; row < rows + 1; ++row)
        {
            // Draw vertical
            val xPos = xStart + gFullCellLen * row;
            cr->move_to(xPos, yStart);
            cr->line_to(xPos, yEnd);

            // Draw horizontal
            val yPos = yStart + gFullCellLen * row;
            cr->move_to(xStart, yPos);
            cr->line_to(xEnd, yPos);
        }
        cr->stroke();
    }
};

/**
 * GUI Window
 */
class MyWindow: public Window
{
public:
    // Initialize drawing area
    MyArea drawingArea;

    /**
     * Constructor
     */
    MyWindow()
    {
        // Window
        set_title("GUI");
        set_default_size(gWindowLen, gWindowLen);

        // Add drawing area
        set_child(drawingArea);
    }
    ~MyWindow() override = default;
};

#endif //HOMEWORKS_WINDOW_H