#ifndef GAME_H
#define GAME_H

class Game {

public:
    Game();
    void simpleRender();
    // TODO void render();

private:
    static const int height = 20;
    static const int width = 10;
    int board[height][width] = {};

    /*
    int nextPiece[4][2]
    int storePiece[4][2]
    */

};

#endif
