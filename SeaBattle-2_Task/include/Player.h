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
            // Влучив!
            // У класі Board треба буде дозволити запис вручну,
            // або (простіше) просто виведемо це на екран поки що.
            // Але правильно - мати метод setMark у Board.
            // Для простоти поки пропустимо складну логіку запису в Board,
            // зосередимось на логіці.
        }
        // Тут буде логіка запису на enemyView пізніше
    }
};



#endif //C_PROJECTS_KRENEVYCH_PLAYER_H