#include <iostream>

#include "tetrominos.h"
#include "tetromino.h"

Tetromino::Tetromino(int t, int r, int yPos, int xPos) {
    // todo make random
    y = yPos;
    x = xPos;
    rotation = r;
    type = t;

    // init board
    board = new int* [20 + 4];
    for (int i = 0; i < 20 + 4; ++i) {
        board[i] = new int [10];
    }
}

Tetromino::~Tetromino() {
    // deallocate board memory
    for(int i = 0; i < 20 + 4; ++i) delete[] board[i];
    delete[] board;
}   

int** Tetromino::getBoard() {
    // compute with current x, y, type, rotation
    // and return board
    for (int i = 0; i < 20 + 4; ++i) {
        for (int j = 0; j < 10; ++j) {
            if (i - y < 4 && i - y >= 0 &&
                j - x < 4 && j - x >= 0) {
                board[i][j] = tetrominos[type][rotation][i - y][j - x];
            } else {
                board[i][j] = 0;
            }
        }
    }
    return board;
}
