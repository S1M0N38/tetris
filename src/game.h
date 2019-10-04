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
    int level = 6; 

private:
    bool collideWithTetrominoes();
    int board[20][10] = {};
    int completedRows = 0;
    Tetromino tetromino;
};

#endif
