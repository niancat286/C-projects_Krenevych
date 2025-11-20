//
// Created by Yaroslava Krenevych on 19.11.2025.
//

#include "../include/Board.h"
#include <iostream>
#include <algorithm> // for std::fill


Board::Board() {
    initializeBoard();
}

void Board::initializeBoard() {
    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            grid[i][j] = CELL_EMPTY;
        }
    }
    // The ship is not placed yet, or we place it at (0,0) as a stub
    shipPosition = {-1, -1};
}

void Board::printBoard(bool showShip) const {
    // cout title and X-coord
    std::cout << "  ";
    for (int j = 0; j < BOARD_SIZE; ++j) {
        std::cout << j << " ";
    }
    std::cout << "\n";

    // with Y-coord
    for (int i = 0; i < BOARD_SIZE; ++i) {
        std::cout << i << " "; // coord Y
        for (int j = 0; j < BOARD_SIZE; ++j) {
            // if host of ship and we need to show it
            if (showShip && i == shipPosition.x && j == shipPosition.y) {
                std::cout << CELL_SHIP << " ";
            }
            // or in other case show just board
            else {
                std::cout << grid[i][j] << " ";
            }
        }
        std::cout << "\n";
    }
}


int Board::receiveShot(Point p) {
    // check if hit
    if (p == shipPosition) {
        grid[p.x][p.y] = CELL_SHOT; // hit
        return -1; // special mark for win/hit
    }

    // miss
    else {
        grid[p.x][p.y] = CELL_MISS; // miss
        // return dist
        return manhattanDistance(p, shipPosition);
    }
}