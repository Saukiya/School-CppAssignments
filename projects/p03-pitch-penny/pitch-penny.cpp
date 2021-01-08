//
// Created by Hykilpikonna on 1/7/21.
//

#include "pitch-penny.h"

int main()
{
    srand(time(nullptr)); // NOLINT(cert-msc51-cpp)

    // Init prizes and board
    var prizeNames = List<String>{"Puzzle", "Doll", "Ball", "Game", "Poster"};
    var board = PitchPennyBoard(prizeNames);

    // Toss pennies
    for (int i = 0; i < pennyCount; i++)
    {
        board.printBoard();
        log(endl << "Press any key to toss a penny...");
        cin.ignore();
        val [loc, prize] = board.tossCoin();
        log("You've tossed at (" << loc / w << ", " << loc % w << ")");
    }

    board.printBoard();
    

    return 0;
}

PitchPennyBoard::PitchPennyBoard(List<String>& prizeNames): prizeNames(prizeNames)
{
    // Check if prizeGrid can be allocated to the board
    assert(prizeGrid.size() * 3 <= len);

    // Init arrays
    prizeGrid.reserve(len);
    pennyGrid.reserve(len);
    for (int i = 0; i < len; i++)
    {
        prizeGrid.emplace_back("");
        pennyGrid.emplace_back(false);
    }

    // Throw prizeGrid
    for (val& prize : prizeNames)
    {
        // Each prize should be thrown to 3 locations
        for (int i = 0; i < 3; i++)
        {
            // Random location
            val loc = (int) rand() % len;

            // Already has a prize, try again
            if (!prizeGrid[loc].empty())
            {
                i--;
                continue;
            }

            // Place a prize
            prizeGrid[loc] = prize;
        }
    }
}

tuple<Int, String> PitchPennyBoard::tossCoin()
{
    // Randomize coin location
    val loc = (int) rand() % len;

    // Add location to the coin
    pennyGrid[loc] = true;

    // Return location and prize at that location
    return {loc, prizeGrid[loc]};
}

void PitchPennyBoard::printBoard()
{
    String out = clearScreen;

    // Find how long is the longest prize name
    unsigned long prizeLen = 0;
    for (val& name : prizeNames) prizeLen = max(prizeLen, name.length());
    prizeLen += 2; // Padding
    val separator = string((prizeLen + 1) * w + 1, '-');

    // Loop through the entire grid
    for (int row = 0; row < h; ++row)
    {
        out += separator + "\n|";

        for (int col = 0; col < w; ++col)
        {
            // 2D position to 1D index
            val loc = row * h + col;
            val prize = prizeGrid[loc];
            val spaces = prizeLen - prize.length();
            val leftSpaces = spaces / 2;

            // Put prize in the center between two spaces
            if (pennyGrid[loc]) out += yellowBackground;
            out += string(leftSpaces, ' ') + prize + string(spaces - leftSpaces, ' ') + reset + "|";
        }

        out += "\n";
    }
    out += separator + "\n";
    cout << out;
}