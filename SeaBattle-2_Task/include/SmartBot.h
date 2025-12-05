//
// Created by Yaroslava Krenevych on 02.12.2025.
//

#ifndef C_PROJECTS_KRENEVYCH_SMARTBOT_H
#define C_PROJECTS_KRENEVYCH_SMARTBOT_H


#pragma once
#include "Player.h"
#include "Config.h"
#include <vector>
#include <algorithm>
#include <map>



class SmartBot : public Player {
private:
    std::vector<Point> candidatePositions;

    void initializeCandidates();
    void filterCandidates(Point lastShot, int distance);
    void expandCandidates();


public:
    SmartBot(std::string n) : Player(n) {
        initializeCandidates();
    }

    // Успадковані методи
    Point makeShot() override;
    Point chooseMove() override;

    std::vector<Point> getCandidates() {
        return candidatePositions;
    }

    void show_filter(Point lastShot, int distance) {
        filterCandidates(lastShot, distance);
    }

    void show_expand() {
        expandCandidates();
    }
    void show_init() {
        initializeCandidates();
    }

    bool isPointInCandidates(const std::vector<Point>& candidates, Point target);

};







#endif //C_PROJECTS_KRENEVYCH_SMARTBOT_H