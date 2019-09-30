#ifndef TETROMINO_H
#define TETROMINO_H

class Tetromino
{
public:
    Tetromino(int type, int rotation, int y = 0, int x = 3);
    ~Tetromino();
    int** getBoard();
    void moveRight() {x += 1;};
    void moveLeft() {x -= 1;};
    void moveDown() {y += 1;};
    void rotate() {rotation = (rotation + 1) % 4;};

private:
    int y, x;
    int rotation;
    int type;
    int** board;
};

#endif
