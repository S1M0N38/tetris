#include <iostream>

#include "board.h"

Board::Board() {
    //
}

void Board::simpleRender() {
    // this member function is just for testing purpose        
    // TODO render with string
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
