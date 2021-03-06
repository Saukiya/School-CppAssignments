//
// Created by Hykilpikonna on 12/7/20.
//

#ifndef HOMEWORKS_BOARD_H
#define HOMEWORKS_BOARD_H

#include "macros.h"
#include "utils.h"

/**
 * A board contains an array of alive points
 */
class Board
{
public:
    List<List<bool>> alive;
    Int w;
    Int h;

    /**
     * Construct a board
     *
     * @param w Width
     * @param h Height
     */
    Board(Int w, Int h);

    /**
     * Asks the user to input the board
     */
    void input(char aliveChar = '1');

    /**
     * Asks the user to input the board
     */
    void input(Int xStart, Int yStart, Int xEnd, Int yEnd, char aliveChar = '1');

    /**
     * Asks the user to input initial alive locations
     */
    void _inputAliveLoc(Int xStart, Int yStart, Int xEnd, Int yEnd);

    /**
     * Asks the user to input a matrix
     */
    void _inputMatrix(Int xStart, Int yStart, Int xEnd, Int yEnd, char aliveChar = '1');

    /**
     * Print the board
     */
    virtual void print();

    /**
     * Get whether the cell at a position is alive. (Assumes `alive` is sorted)
     *
     * @param x Position X.
     * @param y Position Y.
     * @return Is alive or not.
     */
    bool isAlive(Int x, Int y);

    /**
     * Run a tick
     */
    void tick();
};

#endif //HOMEWORKS_BOARD_H
