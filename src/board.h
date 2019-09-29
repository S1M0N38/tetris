#ifndef BOARD_H
#define BOARD_H

class Board {

public:
    Board();
    void simpleRender();
    // TODO void render();

private:
    static const int height = 20;
    static const int width = 10;
    int mainMemory[height][width];
    /*
    int nextPiece[4][2]
    int storePiece[4][2]
    */

};

#endif
