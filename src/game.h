#include "tetromino.h"

#ifndef GAME_H
#define GAME_H

class Game
{
public:
    Game();
    void render();
    void updateState();
    void trasformTetromino(int);
    int level = 0;

private:
    static const int height = 20;
    static const int width = 10;
    int board[height][width] = {};
    int completedRows = 0;
    Tetromino tetromino;
};

#endif
