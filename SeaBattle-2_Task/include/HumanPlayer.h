//
// Created by Yaroslava Krenevych on 21.11.2025.
//

#ifndef C_PROJECTS_KRENEVYCH_HUMANPLAYER_H
#define C_PROJECTS_KRENEVYCH_HUMANPLAYER_H


#pragma once
#include "Player.h"
#include "Board.h"
#include "../src/Board.cpp"


class HumanPlayer : public Player {
public:
    HumanPlayer(std::string n) : Player(n) {}

    Point makeShot() override {
        int x, y;

        // Показуємо гравцю його нотатки перед пострілом
        std::cout << "\n=== Ваші нотатки, " << name << " ===\n";
        EnemyBoard.printBoard(false); // Відображаємо карту ворога (без корабля)
        std::cout << "=================================\n";

        while (true) {
            std::cout << name << ", введи координати пострілу (рядок X, стовпець Y): ";

            // --- 1. Введення даних ---
            std::cin >> x >> y;

            // --- 2. Перевірка помилок вводу ---
            if (std::cin.fail()) {
                std::cout << "Помилка вводу. Будь ласка, вводьте лише цілі числа.\n";
                std::cin.clear(); // Скидаємо прапор помилки
                std::cin.ignore(10000, '\n'); // Очищуємо буфер
                continue; // Починаємо цикл спочатку
            }

            // --- 3. Перевірка валідності координат ---
            Point shotPoint = {x, y};

            // Викликаємо метод isValidCoordinate через об'єкт enemyView
            // (Припускаємо, що isValidCoordinate було реалізовано в Board.cpp)
            if (!EnemyBoard.isValidCoordinate(shotPoint)) {
                std::cout << "Неправильні координати, вони поза межами поля (" << BOARD_SIZE << "x" << BOARD_SIZE << "). Спробуй ще раз.\n";
                continue; // Починаємо цикл спочатку
            }

            // --- 4. Перевірка, чи сюди вже стріляли ---
            if (EnemyBoard.isCellShot(shotPoint)) {
                std::cout << "Увага! Ти вже стріляв сюди. Спробуй іншу клітинку.\n";
                continue;
            }

            // --- 5. Успішне введення ---
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