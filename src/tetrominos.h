#ifndef TETROMINOS_H
#define TETROMINOS_H

// Collection of all tetraminios and all possible rotation based on
// Super rotation system https://strategywiki.org/wiki/Tetris/Rotation_systems

//             ┌ type
//             │  ┌ height
//             │  │  ┌ width
//             │  │  │  ┌ rotation 
int tetrominos[1][4][4][4] = {
    {
        {
            {0, 0, 0, 0},
            {6, 6, 6, 6},
            {0, 0, 0, 0},
            {0, 0, 0, 0,}
        },
        {   
            {0, 0, 6, 0},
            {0, 0, 6, 0},
            {0, 0, 6, 0},
            {0, 0, 6, 0}
        },
        {
            {0, 0, 0, 0},
            {0, 0, 0, 0},
            {6, 6, 6, 6},
            {0, 0, 0, 0},
        },
        {
            {0, 6, 0, 0},
            {0, 6, 0, 0},
            {0, 6, 0, 0},
            {0, 6, 0, 0},
        }
    }
};

#endif
