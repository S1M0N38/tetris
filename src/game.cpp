#include <ncurses.h>

#include "game.h"
#include "tetromino.h"

Game::Game (): tetromino() {
}

void Game::render () {
    int colorRendered;

    // render main board
    tetromino.updateBoard();
    WINDOW* gameWindow = newwin(22, 22, 1, 2);
    start_color();
    wborder(gameWindow, ACS_VLINE, ACS_VLINE, ACS_HLINE, ACS_S1,
            ACS_ULCORNER, ACS_URCORNER, ACS_S1, ACS_S1);
    for (int i = 0; i < 20; ++i) {
        for (int j = 0; j < 10; ++j) {
            colorRendered = board[i][j] + tetromino.board[i+4][j];
            wattron(gameWindow, COLOR_PAIR(colorRendered));
            mvwprintw(gameWindow, i + 1, j * 2 + 1, "  ");
            wattroff(gameWindow, COLOR_PAIR(colorRendered));
        }
    }
    wrefresh(gameWindow);

    // render score and level 
    WINDOW* statsWindow = newwin(4, 20, 1, 30);
    box(statsWindow, 0 , 0);
    mvwprintw(statsWindow, 1, 2, "level: %d", level + 1);
    mvwprintw(statsWindow, 2, 2, "score: %d", score);
    wrefresh(statsWindow);

    /*
    // render next tetromino
    mvaddch(6, 30, ACS_ULCORNER); // top line
    hline(ACS_HLINE, 5);
    mvaddch(6, 36, ACS_URCORNER);
    mvaddch(11, 30, ACS_LLCORNER); // bottom line
    hline(ACS_HLINE, 5);
    mvaddch(11, 36, ACS_LRCORNER); 
    mvvline(6, 30, ACS_VLINE, 5); // left line
    mvvline(6, 36, ACS_VLINE, 5); // right line
    for (int i = 1; i < 5; ++i) {
        for (int j = 3; j < 7; ++j) {
            colorRendered = nextTetromino.board[i][j];
            attron(COLOR_PAIR(colorRendered));
            mvprintw(i, 50 + j * 2, "  ");
            attroff(COLOR_PAIR(colorRendered));
        }
    } 
    */
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
        /*
        tetromino = nextTetromino;
        nextTetromino = Tetromino();
        */
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
            tetromino.rotate();
            if (collideWithTetrominoes()) tetromino.rotate(true);
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
