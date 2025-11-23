//
// Created by Yaroslava Krenevych on 23.11.2025.
//


#include "../include/RandomBot.h"

std::random_device rd;
std::mt19937 generator(rd());
std::uniform_int_distribution<> distrib(0, BOARD_SIZE - 1); // [0, 9] for 10x10

Point RandomBot::makeShot() {
    Point shotPoint;

    do {
        shotPoint.x = distrib(generator);
        shotPoint.y = distrib(generator);

    } while (EnemyBoard.isCellShot(shotPoint));

    std::cout << name << " стріляє в (" << shotPoint.x << ", " << shotPoint.y << ")\n";
    return shotPoint;
}

Point RandomBot::chooseMove() {
    Point current = MyBoard.getShipPosition();
    std::vector<Point> possibleMoves;

    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            Point target = {i, j};

            if (MyBoard.isNeighbor(current, target) && !MyBoard.isCellShot(target)) {
                possibleMoves.push_back(target);
            }
        }
    }
    if (possibleMoves.empty()) {
        return current;
    }

    std::uniform_int_distribution<> moveDistrib(0, possibleMoves.size() - 1);
    size_t randomIndex = moveDistrib(generator);

    return possibleMoves[randomIndex];


}