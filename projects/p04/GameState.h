//
// Created by Hykilpikonna on 1/18/21.
//

#ifndef SCHOOL_CPP_GAMESTATE_H
#define SCHOOL_CPP_GAMESTATE_H

#include "constants.h"
#include "macros.h"
#include "utils.h"

/**
 * Player interface
 */
class Player
{
    virtual int move() = 0;
};

/**
 * Class storing the current game state
 */
class GameState
{
public:
    array<int, rows * rows> grid{};
    List<Player> players;
    int currentPlayer = 0;

    /**
     * Constructor
     */
    GameState()
    {
        // Init grid (-1: No one placed anything here yet)
        for (int& n : grid) { n = -1; }
    }
};

#endif //SCHOOL_CPP_GAMESTATE_H