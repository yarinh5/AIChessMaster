#ifndef GAME_H
#define GAME_H

#include "board.h"
#include "minimax.h"
#include <memory>

class Game {
public:
    Game();
    void play();
    void saveGame();
    void loadGame();

private:
    std::unique_ptr<Board> board;
    std::unique_ptr<Minimax> ai;

    void playerMove();
    void aiMove();
    void displayInstructions() const;
};

#endif
