# Tetris

This project is a simple c++ implementation of the famous *Tetris*. It run in the
terminal (aka command prompt) and use [Extended ASCII](https://en.wikipedia.org/wiki/Extended_ASCII)
(a widespread character encodings) to recreate a simple user interface.

## Installation

1. clone this repo `git clone https://github.com/S1M0N38/tetris.git`
2. navigate to cloned repo `cd tetris`
3. complie files `g++ -lncurses src/main.cpp src/tetromino.cpp src/game.cpp -o tetris`

## Usage

1. navigate to cloned repo `cd tetris`
2. start tetris game `./tetris`
3. exit tetris game with `ctrl-C`

## Detail of implementation

This version of Tetris meant to be as close as possible to the ordinary ones.
Here are the references that I consult to recreate the game mechanics and some
brief explanations of the design choices.

### Tetrominoes definition

Tetrominoes are literally the building blocks of Tetris. From a mathematical
point of view **a tetromino is a geometric shape composed of four squares,
connected orthogonally [(Wikipedia)](https://en.wikipedia.org/wiki/Tetromino).**
In this game, the tetrominoes definition are stored in *tetrominoes.h* under the
*tetrominoes* 4D array. This array include all tetrominoes of classical
Tetris (seven) and their possible rotations (four each). A single rotation of a
specific tetromino is store as a 4 x 4 array filled with zero except for the
position occupied by the squares of the tetromino. The non-zeros value are
some special int value. These number are the same ones that appear in the
colors escaping sequnces: a special sequence of characters able to generate
colors in (pretty much) every terminal. So chosing the right number is
important in order to generate the desiderable color. I try to stick to the
original tetromino-color combination, but there is no orange so the
L-tetromino will be white.

### Tetrominoes rotation system

> Super Rotation System, or SRS, is the current Tetris Guideline standard for
> how tetrominoes behave, defining where and how the tetrominoes spawn, how
> they rotate, and what wall kicks they may perform. Henk Rogers developed this
> system in order to unify all new Tetris games under the Tetris Guideline.
>
[Strategywiki - Tetris Rotation Systems](https://strategywiki.org/wiki/Tetris/Rotation_systems)

### Level up and FPS

> In traditional games, a level-up would occur once every ten lines are
> cleared. [...] After a level-up, points awarded are increased and the blocks
> fall slightly faster. For example, NES Tetris operates at 60 frames per
> second. At level 0, a piece falls one step every 48 frames, and at level 19,
> a piece falls one step every 2 frames. Level increments either terminate at
> a certain point (Game Boy Tetris tops off at level 20).
>
[Wikipedia - Tetris](https://en.wikipedia.org/wiki/Tetris)

My FPS is limited to ~ 10 FPS by the *<ncurses.h> halfdelay* function (the
minium waiting time for the user input is one tenth of a seconds). So at level
0 I decide to update game status every 10 frames, at level 1 every 9 frames,
at level 2 every 8 frames and so on... When player reach level 9 or above,
level index continue growing but the game cannot update its state faster so
the block doesn't speed up.

### Game graphics

`# TODO`
