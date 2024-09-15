#ifndef MINIMAX_H
#define MINIMAX_H

#include "board.h"
#include <tuple>
#include <vector>

class Minimax {
public:
    Minimax(int depth);
    int minimax(Board& board, int depth, bool isMaximizingPlayer, int alpha, int beta);
    std::tuple<int, int, int, int> getBestMove(Board& board);

private:
    int maxDepth;
};

#endif
