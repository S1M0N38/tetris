#include "tetromino.h"

#ifndef GAME_H
#define GAME_H

class Game
{
public:
    Game();
    void render();
    void updateBoard();
    void trasformTetromino(int);

private:
    static const int height = 20;
    static const int width = 10;
    int board[height][width] = {};
    Tetromino tetromino;
};

#endif
