//
// Created by Yaroslava Krenevych on 19.11.2025.
//


#include "include/Game.h"
#include <ctime>
#include <cstdlib>

int main() {
    srand(time(NULL));
    std::cout << "Ласкаво просимо у гру МОРСЬКИЙ БІЙ (Мобільний Корабель)!\n";
    std::cout << "Поле: " << BOARD_SIZE << "x" << BOARD_SIZE << "\n";
    std::cout << "Відстань розраховується за Манхеттенською метрикою (L1).\n" << std::endl;

    try {
        Game seaBattle;
        seaBattle.runGame();
    } catch (const std::exception& e) {
        // checking for unexpected errors
        std::cerr << "Критична помилка виконання: " << e.what() << '\n';
        return 1;
    } catch (...) {
        std::cerr << "Виникла невідома помилка виконання.\n";
        return 1;
    }

    return 0;
}