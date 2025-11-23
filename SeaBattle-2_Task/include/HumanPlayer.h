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

        while (true) {
            std::cout << name << ", введи координати пострілу (рядок X, стовпець Y): ";

            // input data
            std::cin >> x >> y;

            // check errors
            if (std::cin.fail()) {
                std::cout << "Помилка вводу. Будь ласка, вводьте лише цілі числа.\n";
                std::cin.clear(); // Скидаємо прапор помилки
                std::cin.ignore(10000, '\n'); // Очищуємо буфер
                continue; // Починаємо цикл спочатку
            }

            // are valid coords
            Point shotPoint = {x, y};

            // isValidCoordinate in EnemyBoard
            if (!EnemyBoard.isValidCoordinate(shotPoint)) {
                std::cout << "Неправильні координати, вони поза межами поля (" << BOARD_SIZE << "x" << BOARD_SIZE << "). Спробуй ще раз.\n";
                continue;
            }

            // check if shot was in this cell
            if (EnemyBoard.isCellShot(shotPoint)) {
                std::cout << "Увага! Ти вже стріляв сюди. Спробуй іншу клітинку.\n";
                continue;
            }

            // success
            return shotPoint;
        }
    }

    Point chooseMove() override {
        int x, y;
        Point current = MyBoard.getShipPosition();
        std::cout << "Твій корабель зараз у (" << current.x << ", " << current.y << ")\n";
        std::cout << name << ", введи нові координати для руху (X Y): ";
        std::cin >> x >> y;
        return {x, y};
    }
};


#endif //C_PROJECTS_KRENEVYCH_HUMANPLAYER_H