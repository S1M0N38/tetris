#ifndef TETROMINO_H
#define TETROMINO_H

class Tetromino
{
public:
    Tetromino();
    ~Tetromino();
    int** updateBoard();
    void moveRight();
    void moveLeft();
    void moveDown();
    void rotate();
    int** board;

private:
    int y = 0;
    int x = 3;
    int rotation;
    int type;
    bool collideWithBorder();
};

#endif
