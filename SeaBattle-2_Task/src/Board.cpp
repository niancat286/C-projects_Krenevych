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


bool Board::isValidCoordinate(Point p) const {
    return p.x >= 0 && p.x < BOARD_SIZE && p.y >= 0 && p.y < BOARD_SIZE;
}

bool Board::isCellShot(Point p) const {
    return grid[p.x][p.y] == CELL_MISS || grid[p.x][p.y] == CELL_SHOT;
}

bool Board::isNeighbor(Point current, Point target) const {
    if (!isValidCoordinate(target)) return false;

    int dx = std::abs(target.x - current.x);
    int dy = std::abs(target.y - current.y);

    // here i have chosen N8-model
    if (dx <= 1 && dy <= 1) return (dx != 0 || dy != 0);

    return false;
}


bool Board::moveShip(Point newPos) {
    if (!isNeighbor(shipPosition, newPos)) {
        std::cout << "Помилка: Нова позиція не є сусідньою.\n";
        return false;
    }

    if (isCellShot(newPos)) {
        std::cout << "Помилка: Не можна рухатись у клітинку, по якій вже стріляли.\n";
        return false;
    }

    shipPosition = newPos;
    return true;
}


void Board::makeResult(Point p, char mark) {
    if (isValidCoordinate(p)) {
        grid[p.x][p.y] = mark;
    }
    //we ignore invalid coordinates
}