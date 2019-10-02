#include <ncurses.h>

#include "game.h"

Game::Game (): tetromino() {
}

void Game::render () {
    // print tetromino test
    mvaddch(1, 2, ACS_ULCORNER);
    for (int i = 0; i < 20; ++i) addch(ACS_HLINE);
    addch(ACS_URCORNER);
    for (int i = 4; i < 24; ++i) {
        mvaddch(i - 2, 2, ACS_VLINE);
        for (int j = 0; j < 10; ++j) {
            attron(COLOR_PAIR(tetromino.getBoard()[i][j]));
            printw("  ");
            attroff(COLOR_PAIR(tetromino.getBoard()[i][j]));
        }
        addch(ACS_VLINE);
    }

    move(22, 2);
    for (int i = 0; i < 22; ++i) addch(ACS_S1);
}

void Game::updateState () {
    // push row down
    tetromino.moveDown();
    // if (completedRows % 10 > 9 && level < 9) level += 1;
}

void Game::trasformTetromino (int key) {
    switch (key) {
        case KEY_UP:
            tetromino.rotate();
            break;
        case KEY_RIGHT:
            tetromino.moveRight();
            break;
        case KEY_LEFT:
            tetromino.moveLeft();    
            break;
        case KEY_DOWN:
            tetromino.moveDown();
            break;
    }
}


/*
void Game::simpleRender() {
    // this member function is just for testing purpose        
    drawBoard();
    for (int i = 0; i <= height; i++) {
        std::cout << gameRender[i] << std::endl;
    }
    
    // previous solution instant std::cout
    for (int i = 0; i < height; i++) {
        std::cout << " │ ";
        for (int j = 0; j < width; j++) {
            std::cout << mainMemory[i][j] << " ";
        }
        std::cout << "│" << std::endl;    
    }   
    std::cout << " └";
    for (int i = 0; i <= height; i++) std::cout << "─";
    std::cout << "┘" << std::endl << std::endl;
}

void Game::drawBoard() {
    std::string row;
    for (int i = 0; i < height; i++) {
        row = " │";
        for (int j = 0; j < width; j++) {
            row += " " + std::to_string(board[i][j]);
        }
        row += " │ ";
        gameRender[i] = row;
    }
    row = " └";
    for (int i = 0; i <= width * 2; i++) row += "─";
    row += "┘ ";
    gameRender[height] = row; 
}
*/
