#include "board.h"
#include <iostream>
#include <fstream>

Board::Board() {
    setupBoard();
    currentPlayer = Player::WHITE;
}

void Board::setupBoard() {
    board.resize(8, std::vector<Square>(8, Square()));

    for (int i = 0; i < 8; ++i) {
        board[1][i] = Square(Piece::PAWN, Player::WHITE);
        board[6][i] = Square(Piece::PAWN, Player::BLACK);
    }
    board[0][0] = board[0][7] = Square(Piece::ROOK, Player::WHITE);
    board[7][0] = board[7][7] = Square(Piece::ROOK, Player::BLACK);
}

void Board::printBoard() const {
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (board[i][j].player == Player::WHITE) std::cout << "W";
            else if (board[i][j].player == Player::BLACK) std::cout << "B";
            else std::cout << ".";
        }
        std::cout << std::endl;
    }
}

bool Board::isMoveValid(int startX, int startY, int endX, int endY) const {
    // נבנה בהתאם לחוקי המשחק
    return true;
}

void Board::makeMove(int startX, int startY, int endX, int endY) {
    if (isMoveValid(startX, startY, endX, endY)) {
        board[endX][endY] = board[startX][startY];
        board[startX][startY] = Square();
        currentPlayer = (currentPlayer == Player::WHITE) ? Player::BLACK : Player::WHITE;
    }
}

int Board::evaluateBoard() const {
    int score = 0;
    // הערכה מתקדמת לפי ערכים לכלים ומיקומים אסטרטגיים
    for (const auto& row : board) {
        for (const auto& square : row) {
            if (square.piece != Piece::EMPTY) {
                int value = (square.piece == Piece::PAWN) ? 1 :
                    (square.piece == Piece::ROOK) ? 5 :
                    (square.piece == Piece::KNIGHT) ? 3 :
                    (square.piece == Piece::BISHOP) ? 3 :
                    (square.piece == Piece::QUEEN) ? 9 : 0;
                score += (square.player == Player::WHITE) ? value : -value;
            }
        }
    }
    return score;
}

void Board::saveGame(const std::string& filename) const {
    std::ofstream file(filename);
    if (file.is_open()) {
        for (const auto& row : board) {
            for (const auto& square : row) {
                file << static_cast<int>(square.piece) << " " << static_cast<int>(square.player) << " ";
            }
            file << "\n";
        }
        file.close();
    }
}

void Board::loadGame(const std::string& filename) {
    std::ifstream file(filename);
    if (file.is_open()) {
        for (auto& row : board) {
            for (auto& square : row) {
                int piece, player;
                file >> piece >> player;
                square.piece = static_cast<Piece>(piece);
                square.player = static_cast<Player>(player);
            }
        }
        file.close();
    }
}
