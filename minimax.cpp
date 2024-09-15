#include "minimax.h"
#include <algorithm>

Minimax::Minimax(int depth) : maxDepth(depth) {}

std::vector<std::tuple<int, int, int, int>> generateMoves(const Board& board) {
    std::vector<std::tuple<int, int, int, int>> moves;
    // לוגיקה ליצירת מהלכים חוקיים
    return moves;
}

int Minimax::minimax(Board& board, int depth, bool isMaximizingPlayer, int alpha, int beta) {
    if (depth == 0) return board.evaluateBoard();  // הערכת מצב הלוח

    std::vector<std::tuple<int, int, int, int>> possibleMoves = generateMoves(board);

    if (isMaximizingPlayer) {
        int maxEval = -9999;
        for (const auto& move : possibleMoves) {
            Board newBoard = board;
            int startX, startY, endX, endY;
            std::tie(startX, startY, endX, endY) = move;
            newBoard.makeMove(startX, startY, endX, endY);
            int eval = minimax(newBoard, depth - 1, false, alpha, beta);
            maxEval = std::max(maxEval, eval);
            alpha = std::max(alpha, eval);
            if (beta <= alpha) break;  // חיתוך ענף
        }
        return maxEval;
    }
    else {
        int minEval = 9999;
        for (const auto& move : possibleMoves) {
            Board newBoard = board;
            int startX, startY, endX, endY;
            std::tie(startX, startY, endX, endY) = move;
            newBoard.makeMove(startX, startY, endX, endY);
            int eval = minimax(newBoard, depth - 1, true, alpha, beta);
            minEval = std::min(minEval, eval);
            beta = std::min(beta, eval);
            if (beta <= alpha) break;  // חיתוך ענף
        }
        return minEval;
    }
}

std::tuple<int, int, int, int> Minimax::getBestMove(Board& board) {
    int bestMoveScore = -9999;
    std::tuple<int, int, int, int> bestMove;
    std::vector<std::tuple<int, int, int, int>> possibleMoves = generateMoves(board);

    for (const auto& move : possibleMoves) {
        Board newBoard = board;
        int startX, startY, endX, endY;
        std::tie(startX, startY, endX, endY) = move;
        newBoard.makeMove(startX, startY, endX, endY);
        int eval = minimax(newBoard, maxDepth - 1, false, -9999, 9999);
        if (eval > bestMoveScore) {
            bestMoveScore = eval;
            bestMove = move;
        }
    }
    return bestMove;
}
