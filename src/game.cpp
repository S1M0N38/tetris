#include <ncurses.h>

#include "game.h"

Game::Game (): tetromino(0,0) {
}

void Game::render () {
    // print tetromino test
    for (int i = 0; i < 24; ++i) {
        for (int j = 0; j < 10; ++j) {
            // imporve getBoard()
            printw(" %d", tetromino.getBoard()[i][j]);
        }
        printw("\n");
    }
}

void Game::updateBoard () {

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
