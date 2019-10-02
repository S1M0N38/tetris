#include <iostream>

#include <stdlib.h>
#include <time.h>

#include "tetrominos.h"
#include "tetromino.h"


Tetromino::Tetromino() {
    srand(time(nullptr));
    // TODO fix, now is not random
    type = rand() % 7;
    rotation = rand() % 4; 

    // init board
    board = new int* [20 + 4];
    for (int i = 0; i < 20 + 4; ++i) {
        board[i] = new int [10];
    }
    updateBoard();
}

Tetromino::~Tetromino() {
    // deallocate board memory
    for(int i = 0; i < 20 + 4; ++i) delete[] board[i];
    delete[] board;
}   

int** Tetromino::updateBoard() {
    // compute with current x, y, type and rotation
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

bool Tetromino::collideWithBorder() {
    updateBoard();
    int block = 0;
    for (int i = 0; i < 20 + 4; ++i) {
        for (int j = 0; j < 10; ++j) {
            if (board[i][j] != 0) block += 1;
        }
    }
    if (block < 4) return true;
    return false;
}

bool Tetromino::moveRight() {
    x += 1;
    if (collideWithBorder()) {
         x -= 1;
        return false;
    }
    return true;
}

bool Tetromino::moveLeft() {
    x -= 1;
    if (collideWithBorder()) {
        x += 1;
        return false;
    } 
    return true;
}

bool Tetromino::moveDown() {
    y += 1;
    if (collideWithBorder()) {
        y -= 1;
        return false;
    }
    return true;
}

bool Tetromino::rotate() {
    rotation = (rotation + 1) % 4;
    if (collideWithBorder()) {
        rotation = (rotation + 3) % 4;
        return false;
    }
    return true;
}
