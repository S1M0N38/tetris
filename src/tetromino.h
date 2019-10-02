#ifndef TETROMINO_H
#define TETROMINO_H

class Tetromino
{
public:
    Tetromino();
    ~Tetromino();
    int** updateBoard();
    bool moveRight();
    bool moveLeft();
    bool moveDown();
    bool rotate();
    int** board;

private:
    int y = 1;
    int x = 3;
    int rotation;
    int type;
    bool collideWithBorder();
};

#endif
