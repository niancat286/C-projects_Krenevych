//
// Created by Yaroslava Krenevych on 21.11.2025.
//

#include <iostream>
#include "include/HumanPlayer.h"


int main() {
    HumanPlayer p1("Max");
    p1.MyBoard.setShip({0, 0});

    std::cout << "--- Тест стрільби ---\n";
    Point shot = p1.makeShot();
    std::cout << "Гравець вибрав ціль: " << shot.x << ", " << shot.y << "\n";

    std::cout << "\n--- Тест руху ---\n";
    Point move = p1.chooseMove();

    bool success = p1.MyBoard.moveShip(move);
    if (success) {
        std::cout << "Рух виконано успішно!\n";
    } else {
        std::cout << "Рух неможливий (правила Board заборонили)!\n";
    }

    return 0;
}