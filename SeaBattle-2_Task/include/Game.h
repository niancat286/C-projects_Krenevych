//
// Created by Yaroslava Krenevych on 23.11.2025.
//

#ifndef C_PROJECTS_KRENEVYCH_GAME_H
#define C_PROJECTS_KRENEVYCH_GAME_H


#pragma once
#include "Player.h"     // basic class
#include "HumanPlayer.h"// for init
#include "RandomBot.h"  // for init
#include "SmartBot.h"
#include <iostream>
#include <string>

class Game {
private:
    Player* player1;
    Player* player2;

    Player* current_player;

    void setupPlayers();
    void placeShips();

    void switchPlayers();

    void handleShot(Player* shooter, Player* target, Point shot);
    void handleMove(Player* player);

public:
    Game() : player1(nullptr), player2(nullptr), current_player(nullptr) {}
    ~Game();

    void runGame();
};


#endif //C_PROJECTS_KRENEVYCH_GAME_H