#include "game.h"
#include <iostream>

Game::Game() : board(std::make_unique<Board>()), ai(std::make_unique<Minimax>(3)) {
    displayInstructions();
}

void Game::play() {
    while (true) {
        board->printBoard();
        playerMove();
        aiMove();
    }
}

void Game::playerMove() {
    int startX, startY, endX, endY;
    std::cout << "Enter your move (startX startY endX endY): ";
    std::cin >> startX >> startY >> endX >> endY;
    board->makeMove(startX, startY, endX, endY);
}

void Game::aiMove() {
    int startX, startY, endX, endY;
    std::tie(startX, startY, endX, endY) = ai->getBestMove(*board);
    board->makeMove(startX, startY, endX, endY);
    std::cout << "AI made its move." << std::endl;
}

void Game::saveGame() {
    board->saveGame("saved_game.txt");
}

void Game::loadGame() {
    board->loadGame("saved_game.txt");
}

void Game::displayInstructions() const {
    std::cout << "Welcome to AIChessMaster!" << std::endl;
    std::cout << "Enter your move in the format: startX startY endX endY" << std::endl;
    std::cout << "Type 'save' to save the game, 'load' to load a saved game." << std::endl;
}
