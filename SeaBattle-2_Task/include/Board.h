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
    bool isValidCoordinate(Point p) const;
    bool isNeighbor(Point current, Point target) const;
    bool isCellShot(Point p) const; // check if the cell has already been checked
public:
    Board();
    void initializeBoard();

    void setShip(Point p){
        if (isValidCoordinate(p)) {
            shipPosition = p;
        } else {
            std::cerr << "Помилка: Координати корабля невалідні!\n";
        }
    }
    Point getShipPosition() const {return shipPosition;}

    void printBoard(bool showShip) const; // View

    int receiveShot(Point p);   // should be )) Model ---> -1 - missed, distance

    bool moveShip(Point newPos);    // movement
};




#endif //C_PROJECTS_KRENEVYCH_BOARD_H