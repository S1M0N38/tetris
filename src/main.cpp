#include <ncurses.h>

#include "game.h"


int main(int argc, char const *argv[]) {
    int input;
    Game game;

    initscr();

    start_color();
    for (int i = 1; i < 8; ++i) init_pair(i, 0, i);
    noecho();
    curs_set(0);
    keypad(stdscr, TRUE);
    halfdelay(1);

    while (true) {
        for (int i = 0; game.level < 10 && i < 10 - game.level; ++i) {
            input = getch();
            game.trasformTetromino(input);
            game.render();
        }
        game.updateState();
    }

    endwin();


}
