#ifndef TETROMINO_H
#define TETROMINO_H

class Tetromino
{
public:
    Tetromino();
    void updateBoard();
    bool moveRight();
    bool moveLeft();
    bool moveDown();
    bool moveUp();
    bool rotate(bool=false);
    int board[24][10] = {};

private:
    int y = 1;
    int x = 3;
    int rotation;
    int type;
    bool collideWithBorder();
};

#endif
