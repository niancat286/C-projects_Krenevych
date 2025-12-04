//
// Created by Yaroslava Krenevych on 20.11.2025.
//

#include <iostream>
#include "include/Board.h" // Включаємо клас Board


// Функція для запуску всіх тестів
void runBoardTests() {
    std::cout << "--- ЗАПУСК ТЕСТІВ КЛАСУ BOARD ---\n";
    Board playerBoard;
    Point initialPos = {5, 5}; // Корабель стоїть у центрі
    playerBoard.setShip(initialPos);

    std::cout << "\n[ТЕСТ 1: Ініціалізація та Розміщення]\n";
    std::cout << "Корабель розміщено у (5, 5).\n";
    playerBoard.printBoard(true); // Показуємо корабель для підтвердження

    // -------------------------------------------------------------------

    std::cout << "\n[ТЕСТ 2: Влучання та Перемога]\n";
    Point hitShot = {5, 5};
    int resultHit = playerBoard.receiveShot(hitShot);

    if (resultHit == -1) {
        std::cout << "Успіх! Постріл у (5, 5) повернув: " << resultHit << " (ВЛУЧАННЯ).\n";
    } else {
        std::cout << "ПОМИЛКА! Влучання не спрацювало.\n";
    }

    // -------------------------------------------------------------------

    std::cout << "\n[ТЕСТ 3: Промах та Манхеттенська відстань]\n";
    Point missShot1 = {5, 7}; // Відстань до (5,5) = |5-5| + |7-5| = 2
    Point missShot2 = {8, 5}; // Відстань до (5,5) = |8-5| + |5-5| = 3

    int dist1 = playerBoard.receiveShot(missShot1);
    int dist2 = playerBoard.receiveShot(missShot2);

    if (dist1 == 2 && dist2 == 3) {
        std::cout << "Успіх! Промах у (5, 7) повернув: " << dist1 << ".\n";
        std::cout << "Успіх! Промах у (8, 5) повернув: " << dist2 << ".\n";
    } else {
        std::cout << "ПОМИЛКА! Невірна Манхеттенська відстань. Очікувані (2, 3), Отримані (" << dist1 << ", " << dist2 << ").\n";
    }

    std::cout << "\nСтан дошки після пострілів (S замінено на X, промахи O):\n";
    playerBoard.printBoard(false); // Тепер показуємо, що бачить ворог

    // -------------------------------------------------------------------

    std::cout << "\n[ТЕСТ 4: Рух Корабля (Перевірка заборон)]\n";

    // А. Спроба руху на обстріляну клітинку (5, 7) - має бути заборонено
    Point blockedPos = {5, 7};
    bool movedBlocked = playerBoard.moveShip(blockedPos);

    if (!movedBlocked) {
        std::cout << "Успіх! Заборона руху в обстріляну (5, 7) спрацювала.\n";
    } else {
        std::cout << "ПОМИЛКА! Корабель перемістився в обстріляну клітинку!\n";
    }

    // Б. Спроба руху на не сусідню клітинку (1, 1) - має бути заборонено
    Point farPos = {1, 1};
    bool movedFar = playerBoard.moveShip(farPos);

    if (!movedFar) {
        std::cout << "Успіх! Заборона руху на далеку (1, 1) спрацювала.\n";
    } else {
        std::cout << "ПОМИЛКА! Корабель перемістився надто далеко!\n";
    }

    // -------------------------------------------------------------------

    std::cout << "\n[ТЕСТ 5: Успішний Рух Корабля]\n";
    Point validMove = {4, 5}; // Сусідня, необстріляна клітинка
    bool movedSuccessfully = playerBoard.moveShip(validMove);

    if (movedSuccessfully && playerBoard.getShipPosition().x == 4 && playerBoard.getShipPosition().y == 5) {
        std::cout << "Успіх! Корабель перемістився з (5, 5) у ("
                  << playerBoard.getShipPosition().x << ", "
                  << playerBoard.getShipPosition().y << ").\n";
    } else {
        std::cout << "ПОМИЛКА! Валідний рух не відбувся або відбувся невірно.\n";
    }

    std::cout << "\n--- ТЕСТИ ЗАВЕРШЕНО ---\n";
}

int main() {
    runBoardTests();
    return 0;
}