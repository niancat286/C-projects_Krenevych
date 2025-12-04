//
// Created by Yaroslava Krenevych on 21.11.2025.
//

#ifndef C_PROJECTS_KRENEVYCH_HUMANPLAYER_H
#define C_PROJECTS_KRENEVYCH_HUMANPLAYER_H


#pragma once
#include "Player.h"
#include "../src/Board.cpp"


class HumanPlayer : public Player {
public:
    HumanPlayer(std::string n) : Player(n) {}

    Point makeShot() override {
        int x, y;

        // show player their notes before shot
        std::cout << "\n=== Ваші нотатки, " << name << " ===\n";
        EnemyBoard.printBoard(false); // show map of enemy without their ship
        std::cout << "=================================\n";

        for (int attempt = 1; attempt <= MAX_ATTEMPTS; ++attempt) {
            std::cout << name << ", введи координати пострілу (X Y). Спроба "
                      << attempt << "/" << MAX_ATTEMPTS << ": ";

            if (!(std::cin >> x >> y)) {
                std::cout << "ПОМИЛКА: Вводьте лише числа. \n";
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                continue;
            }

            Point shotPoint = {x, y};

            if (!EnemyBoard.isValidCoordinate(shotPoint)) {
                std::cout << "ПОМИЛКА: Координати поза межами поля.\n";
                continue;
            }

            if (EnemyBoard.isCellShot(shotPoint)) {
                std::cout << "ПОМИЛКА: Ти вже стріляв сюди.\n";
                continue;
            }

            return shotPoint;
        }

        // Якщо всі спроби вичерпано
        std::cerr << "\nКРИТИЧНА ПОМИЛКА: Вичерпано " << MAX_ATTEMPTS
                  << " спроб для вводу. Гравець " << name << " пропускає хід стрільби.\n";
        return {-1, -1};
    }

    Point chooseMove() override {

        ShowMyBoard();

        int x, y;
        Point current = MyBoard.getShipPosition();
        for (int attempt = 1; attempt <= MAX_ATTEMPTS; ++attempt) {

            std::cout << "\nТвій корабель зараз у (" << current.x << ", " << current.y << ")\n";
            std::cout << name << ", введи нові координати для руху (X Y). Спроба "
                      << attempt << "/" << MAX_ATTEMPTS << ": ";

            if (!(std::cin >> x >> y)) {
                std::cout << "ПОМИЛКА: Вводьте лише числа. \n";
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                continue;
            }

            Point newPos = {x, y};

            if (!MyBoard.isValidCoordinate(newPos)) {
                std::cout << "ПОМИЛКА: Координати поза межами поля.\n";
                continue;
            }


            if (current.x >= 0 && current.y >= 0) {
                if (!MyBoard.isNeighbor(current, newPos)) {
                    std::cout << "ПОМИЛКА: Рух можливий лише на сусідню клітинку (N8).\n";
                    continue;
                }
            }
            if (MyBoard.isCellShot(newPos)) {
                std::cout << "ПОМИЛКА: Не можна рухатись у клітинку, по якій стріляли.\n";
                continue;
            }

            return newPos;
        }

        std::cerr << "\nКРИТИЧНА ПОМИЛКА: Вичерпано " << MAX_ATTEMPTS
                  << " спроб для вводу руху. Корабель " << name << " залишається на місці.\n";

        return current;
    }
};


#endif //C_PROJECTS_KRENEVYCH_HUMANPLAYER_H