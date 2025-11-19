//
// Created by Yaroslava Krenevych on 19.11.2025.
//

//here we need to do all the settings for our board
// like coords and consts of our game

#ifndef C_PROJECTS_KRENEVYCH_CONFIG_H
#define C_PROJECTS_KRENEVYCH_CONFIG_H

#pragma once
#include <iostream>

const int BOARD_SIZE = 10;
const char CELL_EMPTY = '.';
const char CELL_SHIP = 'S';
const char CELL_SHOT = 'X';
const char CELL_MISS = 'O';


struct Point {      /*coordinates struct*/
    int x;
    int y;

    /* here I create a method to compare 2 points */
    bool operator==(const Point& other) const {
        return x == other.x && y == other.y;
    }

};

/*manh. distance method*/
// |x1 - x2| + |y1 - y2|

int manhattanDistance(Point p1, Point p2) {
    return std::abs(p1.x - p2.x) + std::abs(p1.y - p2.y);
}




#endif //C_PROJECTS_KRENEVYCH_CONFIG_H