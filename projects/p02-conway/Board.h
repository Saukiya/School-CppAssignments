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
    vector<Long> alive;
    Int w;
    Int h;

    /**
     * Construct a board
     *
     * @param w Width
     * @param h Height
     */
    Board(Int w, Int h): w(w), h(h) {}

    /**
     * Asks the user to input the board
     */
    void input(char aliveChar = '1');

    /**
     * Get whether the cell at a position is alive. (Assumes `alive` is sorted)
     *
     * @param x Position X.
     * @param y Position Y.
     * @return Is alive or not.
     */
    bool isAlive(Int x, Int y);
};

#endif //HOMEWORKS_BOARD_H
