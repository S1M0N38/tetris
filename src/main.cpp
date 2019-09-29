#include <chrono>
#include <iostream>
#include <thread>

#include "board.h"

int main(int argc, char const *argv[])
{
    Board board;

    while (true) {
        for (int i = 0; i < 100; i++) std::cout << std::endl; 
        board.simpleRender();
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}
