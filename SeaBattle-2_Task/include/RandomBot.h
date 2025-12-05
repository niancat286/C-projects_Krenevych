//
// Created by Yaroslava Krenevych on 23.11.2025.
//

#ifndef C_PROJECTS_KRENEVYCH_RANDOMBOT_H
#define C_PROJECTS_KRENEVYCH_RANDOMBOT_H

#pragma once
#include "Player.h"
#include <random> // for generation random numbers

class RandomBot : public Player {
public:
    RandomBot(std::string n) : Player(n) {}

    Point makeShot() override;
    Point chooseMove() override;
};

#endif //C_PROJECTS_KRENEVYCH_RANDOMBOT_H