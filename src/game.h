#include "tetromino.h"

#ifndef GAME_H
#define GAME_H

class Game
{
public:
    Game():tetromino(){};
    void render();
    void updateState();
    void trasformTetromino(int);
    int level = 0;

private:
    bool collideWithTetrominoes();
    bool isRowCompleted(int);
    void deleteRow(int);
    void updateScore();
    int board[20][10] = {};
    int completedRows = 0;
    int score = 0;
    Tetromino tetromino;
    Tetromino nextTetromino;
};

#endif
