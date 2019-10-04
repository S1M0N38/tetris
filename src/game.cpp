#include <ncurses.h>

#include "game.h"
#include "tetromino.h"

Game::Game (): tetromino() {
}

void Game::render () {
    tetromino.updateBoard();
    mvaddch(1, 2, ACS_ULCORNER);
    for (int i = 0; i < 20; ++i) addch(ACS_HLINE);
    addch(ACS_URCORNER);
    int colorRendered;
    for (int i = 0; i < 20; ++i) {
        mvaddch(i + 2, 2, ACS_VLINE);
        for (int j = 0; j < 10; ++j) {
            colorRendered = board[i][j] + tetromino.board[i+4][j];
            attron(COLOR_PAIR(colorRendered));
            printw("  ");
            attroff(COLOR_PAIR(colorRendered));
        }
        addch(ACS_VLINE);
    }

    move(22, 2);
    for (int i = 0; i < 22; ++i) addch(ACS_S1);
}

void Game::updateState () {
    // check collisions with the bottom border 
    bool collide = !tetromino.moveDown();
    // check collisions with other tetrominoes
    if (collideWithTetrominoes()) {
        tetromino.moveUp();
        collide = true;
    }

    if (collide){
        tetromino.updateBoard();
        for (int i = 0; i < 20; ++i) {
            for (int j = 0; j < 10; ++j) {
                if (board[i][j] == 0) {
                    board[i][j] = tetromino.board[i+4][j];
                }    
            }    
        }
        tetromino = Tetromino();
    }

    // if (completedRows % 10 > 9 && level < 9) level += 1;
}

bool Game::collideWithTetrominoes() {
    tetromino.updateBoard();
    for (int i = 0; i < 20; ++i) {
        for (int j = 0; j < 10; ++j) {
            if (board[i][j] != 0 && tetromino.board[i+4][j] != 0) {
                return true;
            }
        }
    }
    return false;
}

void Game::trasformTetromino (int key) {
    switch (key) {
        case KEY_UP:
            // add rotation index
            tetromino.rotate();
            break;
        case KEY_RIGHT:
            tetromino.moveRight();
            if (collideWithTetrominoes()) tetromino.moveLeft();
            break;
        case KEY_LEFT:
            tetromino.moveLeft();    
            if (collideWithTetrominoes()) tetromino.moveRight();
            break;
        case KEY_DOWN:
            tetromino.moveDown();
            if (collideWithTetrominoes()) tetromino.moveUp();
            break;
    }
}
