//
// Created by Yaroslava Krenevych on 19.11.2025.
//

#ifndef C_PROJECTS_KRENEVYCH_BOARD_H
#define C_PROJECTS_KRENEVYCH_BOARD_H


#pragma once
#include "Config.h"


class Board {
private:
    char grid[BOARD_SIZE][BOARD_SIZE]; // array for board
    Point shipPosition;                // position of the ship
public:
    Board();
    void initializeBoard();

    void setShip(Point p);
    Point getShipPos() const;

    void printBoard(bool showShip) const; // View

    int receiveShot(Point p);   // should be )) Model ---> -1 - missed, distance

    bool moveShip(Point newPos);    // movement
};




#endif //C_PROJECTS_KRENEVYCH_BOARD_H