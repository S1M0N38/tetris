#include <chrono>
#include <iostream>
#include <thread>

#include "game.h"

int main(int argc, char const *argv[])
{
    Game game;

    while (true) {
        for (int i = 0; i < 100; i++) std::cout << std::endl; 
        game.simpleRender();
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}
