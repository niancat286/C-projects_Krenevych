//
// Created by Yaroslava Krenevych on 03.12.2025.
//

#pragma once

#include "../include/SmartBot.h"
#include <set>


bool SmartBot::isPointInCandidates(const std::vector<Point>& candidates, Point target) {
    return std::find(candidates.begin(), candidates.end(), target) != candidates.end();
}

void SmartBot::initializeCandidates() {
    candidatePositions.clear();

    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            candidatePositions.push_back({i,j});
        }
    }
}


Point SmartBot::makeShot() {
    candidatePositions.erase(std::remove_if(candidatePositions.begin(), candidatePositions.end(),
            [this](const Point& p) {
                return this->EnemyBoard.isCellShot(p);
            }),
        candidatePositions.end());

    if (candidatePositions.empty()) {
        return {-1, -1};
    }

    Point target = candidatePositions.front();
    std::cout << name << " (AI) стріляє в (" << target.x << ", " << target.y << ")\n";
    return target;
}


void SmartBot::filterCandidates(Point lastShot, int distance) {
    candidatePositions.erase(
        std::remove_if(candidatePositions.begin(),candidatePositions.end(),
        [lastShot, distance](const Point& candidate) {
            return manhattanDistance(lastShot, candidate) != distance;
        }),
        candidatePositions.end());

    std::cout << name << " звузив пошук. Залишилось " << candidatePositions.size()
              << " можливих позицій.\n";
}


void SmartBot::expandCandidates() {
    std::vector<Point> newCandidates;

    std::set<std::pair<int, int>> uniqueCandidates;

    for (const auto& curr_cand : candidatePositions) {
        for (int dx = -1; dx <= 1; ++dx) {
            for (int dy = -1; dy <= 1; ++dy) {
                Point neighbor = {curr_cand.x + dx, curr_cand.y + dy};

                if (MyBoard.isValidCoordinate(neighbor)) {
                    if (!this->EnemyBoard.isCellShot(neighbor)) {
                        uniqueCandidates.insert({neighbor.x, neighbor.y});
                    }
                }
            }
        }
    }
    candidatePositions.clear();
    for (const auto& p : uniqueCandidates) {
        candidatePositions.push_back({p.first, p.second});
    }
    std::cout << name << " розширив пошук через рух цілі. Новий розмір можливих позицій: "
              << candidatePositions.size() << ".\n";
}


Point SmartBot::chooseMove() {
    Point current = MyBoard.getShipPosition();
    if (current.x == -1 || current.y == -1) {
        Point placementPos = {rand() % BOARD_SIZE, rand() % BOARD_SIZE};
        /*std::cout << name << " (AI) розміщує корабель випадково в ("
                  << placementPos.x << ", " << placementPos.y << ").\n";*/

        std::cout << name << " (AI) розміщує корабель випадково.\n" << std::endl;
        return placementPos;
    }

    std::vector<Point> validMoves;

    for (int dx = -1; dx <= 1; ++dx) {
        for (int dy = -1; dy <= 1; ++dy) {
            if (dx == 0 && dy == 0) continue;

            Point neighbor = {current.x + dx, current.y + dy};

            if (MyBoard.isValidCoordinate(neighbor) && !MyBoard.isCellShot(neighbor)) {
                validMoves.push_back(neighbor);
            }
        }
    }

    if (!validMoves.empty()) {
        int RandNum = rand() % validMoves.size();
        Point chosenMove = validMoves[RandNum];

        /*std::cout << name << " (AI) рухається з (" << current.x << ", " << current.y << ") в ("
                  << chosenMove.x << ", " << chosenMove.y << ")\n";*/

        std::cout << name << " (AI) рухається.\n" << std::endl;
        return chosenMove;
    }
    else {

        /*std::cout << name << " (AI) не може рухатись і залишається в ("
                  << current.x << ", " << current.y << ").\n";*/

        std::cout << name << " (AI) не може рухатись і залишається на позиції" << std::endl;
        return current;
    }

}
