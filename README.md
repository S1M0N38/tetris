# tetris

A simple terminal tetris
`# TODO`

## Installation

`# TODO`

## Usage

`# TODO`

## Detail of implementation

This version of Tetris meant to be as close as possible to the ordinary ones.
Here are the references that I consult to recreate the game mechanics.

### Tetromino rotation system

> Super Rotation System, or SRS, is the current Tetris Guideline standard for
> how tetrominoes behave, defining where and how the tetrominoes spawn, how
> they rotate, and what wall kicks they may perform. Henk Rogers developed this
> system in order to unify all new Tetris games under the Tetris Guideline.
>
[Strategywiki - Tetris Rotation Systems]("https://strategywiki.org/wiki/Tetris/Rotation_systems")

### Level up and FPS

> In traditional games, a level-up would occur once every ten lines are
> cleared. [...] After a level-up, points awarded are increased and the blocks
> fall slightly faster. For example, NES Tetris operates at 60 frames per
> second. At level 0, a piece falls one step every 48 frames, and at level 19,
> a piece falls one step every 2 frames. Level increments either terminate at
> a certain point (Game Boy Tetris tops off at level 20).
>
 [Wikipedia - Tetris]("https://en.wikipedia.org/wiki/Tetris")

My FPS is limited to ~ 10 FPS by the *<ncurses.h> halfdelay* function (the
minium waiting time for the user input is one tenth of a seconds). So at level
0 I decide to update game status every 10 frames, at level 1 every 9 frames,
at level 2 every 8 frames and so on... When player reach level 9 or above,
level index continue growing but the game cannot update its state faster so
the block doesn't speed up.
