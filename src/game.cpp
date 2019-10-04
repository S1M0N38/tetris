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
    mvprintw(23, 2, "level: %d", level + 1);
    mvprintw(24, 2, "score: %d", score);
}

void Game::updateState () {
    // check collisions with the bottom border 
    bool collide = !tetromino.moveDown();
    // check collisions with other tetrominoes
    if (collideWithTetrominoes()) {
        tetromino.moveUp();
        collide = true;
    }

    // fix tetromino, update score and spawn a new tetromino 
    if (collide){
        tetromino.updateBoard();
        for (int i = 0; i < 20; ++i) {
            for (int j = 0; j < 10; ++j) {
                if (board[i][j] == 0) {
                    board[i][j] = tetromino.board[i+4][j];
                }    
            }    
        }
        updateScore();
        tetromino = Tetromino();
    }
}

void Game::updateScore() {
    int rowCleared = 0;
    for (int i = 0; i < 20; ++i) {
        if (isRowCompleted(i)) {
            deleteRow(i);
            rowCleared += 1;
        }
    }

    // Original Nintendo scoring system
    switch (rowCleared) {
        case 1:
            score += 40 * (level + 1);
            break;
        case 2:
            score += 100 * (level + 1);
            break;
        case 3:
            score += 300 * (level + 1);
            break;
        case 4:
            score += 1200 * (level + 1);
            break;    
    };

    // level up
    if (completedRows % 10 > 9 && level < 9) level += 1;
}

bool Game::isRowCompleted(int row) {
    for (int j = 0; j < 10; ++j) {
        if (board[row][j] ==  0) return false;
    }
    completedRows += 1;
    return true;
}

void Game::deleteRow(int row) {
    for (int i = row; i > 0; --i) {
        for (int j = 0; j < 10; ++j) {
           board[i][j] = board[i - 1][j];
        }
    }
    for (int j = 0; j < 10; ++j) {
        board[0][j] = 0;
    }
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
