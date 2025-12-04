//
// Created by Yaroslava Krenevych on 04.12.2025.
//


#include "include/SmartBot.h"

#include <ctime>
#include <cstdlib>


size_t countValidCandidates(SmartBot* bot) {
    return bot->getCandidates().size();
}

void runSmartTests() {
    SmartBot SBot("smartic");

    std::cout << "\n[ТЕСТ ФІЛЬТРАЦІЇ]: Постріл у (5, 5), дистанція D=3\n";
    Point shot1 = {5, 5};
    int dist1 = 3;

    // Логіка: На ромбі L1=3 навколо (5, 5) має бути 4 * 3 = 12 клітинок.
    // (5, 8), (8, 5), (5, 2), (2, 5) та проміжні.

    SBot.show_filter(shot1, dist1);

    const size_t EXPECTED_COUNT_D3 = 12;
    size_t actualCount1 = countValidCandidates(&SBot);

    if (actualCount1 == EXPECTED_COUNT_D3) {
        std::cout << "Фільтрація на D=3. Знайдено " << actualCount1 << " кандидатів.\n";
    } else {
        std::cout << "Очікувалося " << EXPECTED_COUNT_D3
                  << " кандидатів, знайдено: " << actualCount1 << ".\n";
    }


    std::cout << "\n[ТЕСТ РОЗМИТТЯ]: Після руху цілі\n";

    SBot.show_expand();

    size_t actualCount2 = countValidCandidates(&SBot);

    if (actualCount2 > EXPECTED_COUNT_D3 && actualCount2 < 100) {
        std::cout << "Нова кількість кандидатів: "
                  << actualCount2 << ".\n";
    } else {
        std::cout << "Кількість кандидатів після розмиття нелогічна: "
                  << actualCount2 << ".\n";
    }


    std::cout << "\n[ТЕСТ ОБМЕЖЕННЯ РУХУ]: Блокування клітинок\n";

    SBot.show_init();

    // Моделюємо постріл по (5, 5) з D=1 (кандидати: (4,5), (6,5), (5,4), (5,6))
    SBot.show_filter({5, 5}, 1);

    Point blockedCell = {4, 5};
    SBot.EnemyBoard.makeResult(blockedCell, CELL_MISS);

    // Викликаємо розмиття
    SBot.show_expand();

    bool isBlockedFound = SBot.isPointInCandidates(SBot.getCandidates(), blockedCell);

    Point validNeighbor = {3, 5};
    bool isValidNeighborFound = SBot.isPointInCandidates(SBot.getCandidates(), validNeighbor);

    if (!isBlockedFound && isValidNeighborFound) {
        std::cout << "Успіх! Обстріляна клітинка (" << blockedCell.x << ", "
                  << blockedCell.y << ") ВИКЛЮЧЕНА зі списку кандидатів.\n";
    } else {
        std::cout << "ПОМИЛКА! Обстріляна клітинка "
                  << (isBlockedFound ? "ЗНАЙДЕНА" : "НЕ ЗНАЙДЕНА (але інші перевірки можуть бути хибними)")
                  << " у списку.\n";
    }
}



int main() {
    std::srand(time(NULL));
    runSmartTests();
    return 0;
}