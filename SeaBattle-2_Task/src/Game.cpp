//
// Created by Yaroslava Krenevych on 23.11.2025.
//
#pragma once
#include <cstdlib>
#include "../include/Game.h"

void clearScreen() {
    // clearing the console before every turn
#ifdef _WIN32
    system("cls"); // Windows
#else
    system("clear"); // Linux, macOS
#endif
}

void clearScreen_ANSI() {
    // ANSI Escape Code для очищення екрана та переміщення курсора у верхній лівий кут
    std::cout << "\033[2J\033[1;1H";
}

void Game::setupPlayers() {
    std::cout << "Оберіть режим гри:\n";
    std::cout << "1: Людина проти Випадкового Бота\n";
    std::cout << "2: Людина проти Людини\n";

    int choice;
    std::cin >> choice;
    if (choice == 1) {
        player1 = new HumanPlayer("Гравець 1 (Людина)");
        player2 = new RandomBot("Гравець 2 (Бот)");
    }
    else if (choice == 2) {
        player1 = new HumanPlayer("Гравець 1 (Людина)");
        player2 = new HumanPlayer("Гравець 2 (Людина)");
    }
    current_player = player1;
}

Game::~Game() {
    delete player1;
    delete player2;
}


void Game::placeShips() {
    std::cout << "\n--- Розміщення корабля 1 " << player1->getName() << " ---\n";
    Point p1Pos = player1->chooseMove();
    player1->MyBoard.setShip(p1Pos);

    // !!! Очищення екрана між гравцями !!!
    if (dynamic_cast<HumanPlayer*>(player2)) {
        clearScreen();
        std::cout << "Гравцю 1, відверніться! Гравцю 2, натисніть ENTER для розміщення.\n";
        std::cin.ignore(1000, '\n');
        std::cin.get();
    }

    std::cout << "\n--- Розміщення корабля 2 " << player2->getName() << " ---\n";
    Point p2Pos = player2->chooseMove();
    player2->MyBoard.setShip(p2Pos);

    std::cout << "Розміщення завершено" << std::endl;
    /*
    if (dynamic_cast<HumanPlayer*>(player1)) {
        player1->ShowMyBoard();
    }
    if (dynamic_cast<HumanPlayer*>(player2)) {
        player2->ShowMyBoard();
    }
    */

}

void Game::switchPlayers() {
    if (current_player == player1) {
        current_player = player2;
    } else {
        current_player = player1;
    }
}


void Game::runGame() {
    setupPlayers();
    placeShips();

    Player* shooter = player1;
    Player* target = player2;

    std::cout << "Гра почалася! Натисність Enter, щоб продовжити" << std::endl;
    std::cin.ignore(1000, '\n');
    std::cin.get();


    while (true) {
        clearScreen();
        std::cout << "\n*** ХІД: " << shooter->getName() << " ***" << std::endl;
        Point shot = shooter->makeShot();
        handleShot(shooter, target, shot);


        if (target->MyBoard.isShipSunk()) {
            std::cout << "\n************************************\n";
            std::cout << "*** ПЕРЕМОГА! Гравець " << shooter->getName() << " виграв! ***" << std::endl;
            std::cout << "************************************\n";
            break;
        }
        handleMove(shooter);
        switchPlayers();

        std::swap(shooter, target);
    }
}

void Game::handleShot(Player* shooter, Player* target, Point shot) {
    int res_dist = target->MyBoard.receiveShot(shot);
    shooter->updateEnemyView(shot, res_dist);
}

void Game::handleMove(Player* player) {
    if (!player->MyBoard.isShipSunk()) {
        std::cout << "\n--- Рух корабля " << player->getName() << " ---" << std::endl;
        Point newPos = player->chooseMove();

        bool success = player->MyBoard.moveShip(newPos);

        if (success) {
            std::cout << player->getName() << " успішно перемістив корабель" << std::endl;
        } else {
            std::cout << player->getName() << " не зміг перемістити корабель" << std::endl;
        }

        /*if (dynamic_cast<HumanPlayer*>(player)) {
            player->ShowMyBoard();
        }*/
    }
}
