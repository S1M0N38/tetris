#include <chrono>
#include <thread>

#include <ncurses.h>

#include "game.h"
#include "tetromino.h"


void printTetro(Tetromino &t) {
    for (int i = 0; i < 24; ++i) {
        for (int j = 0; j < 10; ++j) {
            printw(" %d", t.getBoard()[i][j]);
        }
        printw("\n");
    }
}

void trasformTetronimo (Tetromino &t, int key) {
    switch (key) {
        case KEY_UP:
            t.rotate();
            break;
        case KEY_RIGHT:
            t.moveRight();
            break;
        case KEY_LEFT:
            t.moveLeft();    
            break;
        case KEY_DOWN:
            t.moveDown();
            break;
    }
}

int main(int argc, char const *argv[]) {
    Tetromino t(0, 0);
    int ch;

    initscr();
    noecho();  
    keypad(stdscr, TRUE); 
    halfdelay(1);

    while (true) {
        ch = getch();
        clear();
        trasformTetronimo(t, ch);
        printTetro(t);
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
