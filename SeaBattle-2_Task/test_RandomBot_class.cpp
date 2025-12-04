//
// Created by Yaroslava Krenevych on 23.11.2025.
//

#include <iostream>
#include <vector>
#include "include/RandomBot.h"


void testcase1() {
    std::cout << "testcase1. edge case " << std::endl;
    RandomBot bot = RandomBot("Test Bot 1");

    Point start = {0, 0};
    bot.MyBoard.setShip(start);

    bot.MyBoard.receiveShot({1, 1});

    Point chosen = bot.chooseMove();

    if (bot.MyBoard.isValidCoordinate(chosen) && !bot.MyBoard.isCellShot(chosen)) {
        std::cout << "Успіх. Рух у (" << chosen.x << ", " << chosen.y << ") можливий" << std::endl;
    }
    else {
        std::cout << "Не спрацювало, бот обрав неможливу позицію" << std::endl;
    }

}


void testcase2() {
    std::cout << "testcase2. blockade " << std::endl;

    RandomBot bot = RandomBot("Test Bot 2");
    Point start = {1, 1};
    bot.MyBoard.setShip(start);

    //blockade of all 8 neighbores
    for (int dx = -1; dx <= 1; ++dx) {
        for (int dy = -1; dy <= 1; ++dy) {
            if (dx != 0 || dy != 0) {
                bot.MyBoard.receiveShot({1 + dx, 1 + dy});
            }
        }
    }

    Point chosen = bot.chooseMove();
    bool moveSuccess = bot.MyBoard.moveShip(chosen);

    if (chosen.x == 1 && chosen.y == 1 && !moveSuccess) {
        std::cout << "Успіх! Бот на (1, 1) і рух відхилено\n";
    } else if (moveSuccess) {
        std::cout << "Помилка! рух при заблокованих сусідах\n";
    } else {
        std::cout << "Помилка! Неправильна координата або логіка\n";
    }
}


int main() {
    testcase1();

    testcase2();
    return 0;
}

