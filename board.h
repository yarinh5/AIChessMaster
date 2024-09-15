#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <string>

enum class Piece { EMPTY, PAWN, ROOK, KNIGHT, BISHOP, QUEEN, KING };
enum class Player { NONE, WHITE, BLACK };

struct Square {
    Piece piece;
    Player player;

    Square(Piece p = Piece::EMPTY, Player pl = Player::NONE) : piece(p), player(pl) {}
};

class Board {
public:
    Board();
    void printBoard() const;
    bool isMoveValid(int startX, int startY, int endX, int endY) const;
    void makeMove(int startX, int startY, int endX, int endY);
    int evaluateBoard() const;  // הערכת לוח מתקדמת
    void saveGame(const std::string& filename) const;  // שמירת המשחק לקובץ
    void loadGame(const std::string& filename);  // טעינת המשחק מקובץ

private:
    std::vector<std::vector<Square>> board;
    Player currentPlayer;
    void setupBoard();
};

#endif
