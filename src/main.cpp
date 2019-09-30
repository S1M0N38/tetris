#include <chrono>
#include <thread>

#include <ncurses.h>

#include "game.h"


int main(int argc, char const *argv[]) {
    int input;
    Game game;

    initscr();
    noecho();  
    keypad(stdscr, TRUE); 
    halfdelay(1);

    while (true) {
        input = getch();
        clear();
        game.trasformTetromino(input);
        game.render();
        refresh();
        std::this_thread::sleep_for(std::chrono::milliseconds(33));
    }

    endwin();


    /*

    Game game;

    while (true) {
        for (int i = 0; i < 10; i++) {
            char input = getch();

            if (input == '↑') Game.tetromino.rotate();
            else if (input == '⟵' || input = '→' || input == '↓') Game.tetromino.move(input)
            else pass // expected ERR or other char

            Game.render();
            std::this_thread::sleep_for(std::chrono::milliseconds(33));
        }
        Game.updateBoard();
    }
    */
}
