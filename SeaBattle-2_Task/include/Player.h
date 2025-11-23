//
// Created by Yaroslava Krenevych on 21.11.2025.
//

#ifndef C_PROJECTS_KRENEVYCH_PLAYER_H
#define C_PROJECTS_KRENEVYCH_PLAYER_H

#pragma once
#include <string>
#include <vector>
#include "../src/Board.cpp"
#include "Config.h"

class Player {
protected:
    std::string name;
public:
    Board MyBoard;
    Board EnemyBoard;

    Player(std::string n) : name(n) {
        MyBoard.initializeBoard();
        EnemyBoard.initializeBoard();
    }

    virtual ~Player() = default;

    virtual Point makeShot() = 0;
    virtual Point chooseMove() = 0;

    std::string getName() const { return name; }

    void updateEnemyView(Point shot, int resultDistance) {
        if (resultDistance == -1) {
            EnemyBoard.makeResult(shot, CELL_SHOT);
            std::cout << "побачив: ВЛУЧАННЯ! (Корабель потоплено)\n";
        } else {
            EnemyBoard.makeResult(shot, CELL_MISS);
            std::cout << name << " побачив: Промах! Дистанція до цілі: " << resultDistance << "\n";

        }
    }

    void showNotes() const {
        std::cout << "\n=== Нотатки гравця " << name << " (enemyView) ===\n";
        EnemyBoard.printBoard(false);
        std::cout << "========================================\n";
    }

    void ShowMyBoard() const {
        std::cout << "\n=== Дошка гравця " << name << " (myBoard) ===\n";
        MyBoard.printBoard(true); // showShip = true, to see youe ship
        std::cout << "=================================\n";

    }
};



#endif //C_PROJECTS_KRENEVYCH_PLAYER_H