#include <string>
#include <iostream>

#include "game.h"

Game::Game() {
    //
}

void Game::simpleRender() {
    // this member function is just for testing purpose        
    drawBoard();
    for (int i = 0; i <= height; i++) {
        std::cout << gameRender[i] << std::endl;
    }
    /*
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
    */
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