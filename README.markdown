# Tower of Hanoi {#mainpage}

[![Travis (.org) branch](https://img.shields.io/travis/lucasguesserts/tower_of_hanoi/master?label=Build%20Master)](https://travis-ci.org/lucasguesserts/tower_of_hanoi) [![Documentation](https://codedocs.xyz/lucasguesserts/tower_of_hanoi.svg)](https://codedocs.xyz/lucasguesserts/tower_of_hanoi/) 

Implementation of the Tower of Hanoi in C.


## Game Definition {#game_definition}

It consists of a finite set of **Rods** and **Disks**.
The rods are organized in a line and each disk has a
different diameter.

- **Start:** All the disks are organized in ascending diameter in the first rod.
- **Goal:** Move all the disks to the last rod.
- **Rules:**
  1. Only one disk can be moved at a time.
  2. Only the disks on top of each rod may be moved.
  3. Disks cannot be placed on top of smaller disks.

## How to Use {#how_to_use}

The representation of a Tower of Hanoi game is made
by the structure [TowerOfHanoi](@ref TowerOfHanoi). The first step is
to create an instance of that structure and initialize
it. After that, the movements can be executed and,
at any point, the end of the game can be checked.

All the game manipulation functions are available
in the file [TowerOfHanoi.h](@ref TowerOfHanoi.h).

## Example - Creating and Solving a 3-disk Game {#introductory_example}

```c
#include "TowerOfHanoi.h"

int main(void)
{
    unsigned numberOfDisks, numberOfRods;
    MoveError moveStatus; /* Unused here */
    TowerOfHanoi th;

    /* Initialization */
    numberOfDisks = 3;
    numberOfRods = 3;
    initializeTowerOfHanoi(&th, numberOfDisks, numberOfRods)

    /* Solve Game */
    moveStatus = moveDisk(&th, 0, 2);
    moveStatus = moveDisk(&th, 1, 1);
    moveStatus = moveDisk(&th, 0, 1);
    moveStatus = moveDisk(&th, 2, 2);
    moveStatus = moveDisk(&th, 0, 0);
    moveStatus = moveDisk(&th, 1, 2);
    moveStatus = moveDisk(&th, 0, 2);

    return gameOverTowerOfHanoi(&th);
    /* 0 (true) because the game is over */
}
```

## Interactive Game {#introductory_interactive_game}

It is implemented an interactive game. After building,
execute `build/bin/InteractiveTowerOfHanoi`.

```
  0 1 2
0 X - -
1 X - -
2 X - -
number of moves:   0

Select a disk to move: 0

Select a rod to move it into:
```

Above is exemplified the execution of the app.
You may insert which disk to move and to which
rod it should be moved. The game will change its
state depending on whether a valid move was
inserted or not.

When the game is finished, it prompts a
congratulation message and tells you in how many
moves you completed the game.

```
Congratulations, you have finished the game in 7 moves.
```

## Optimized Algorithm {#optimized_game}

There is also an app which solves the problem
using recursion. First define a sub-tower as
a Tower of Hanoi made of a smaller number of disks.
Then the optimized algorithm used is as follow:

- If the disk to be moved is the smallest, just move it.
- If the disk to be moved is not the smallest:
  -# Move the sub-tower over the selected disk to the
     other rod.
  -# Move the disk to the desired rod.
  -# move the previous sub-tower onto the selected disk.

With such algorithm, the problem is solved requiring to move
the biggest disk to the last rod.

The app shows in the standard output all the steps
to solve the problem with the minimum number of moves.

```
  0 1 2
0 X - -
1 X - -
2 X - -
number of moves:   0

  0 1 2
0 - - X
1 X - -
2 X - -
number of moves:   1


  0 1 2
0 - - X
1 - X -
2 X - -
number of moves:   2


  0 1 2
0 - X -
1 - X -
2 X - -
number of moves:   3


  0 1 2
0 - X -
1 - X -
2 - - X
number of moves:   4


  0 1 2
0 X - -
1 - X -
2 - - X
number of moves:   5


  0 1 2
0 X - -
1 - - X
2 - - X
number of moves:   6


  0 1 2
0 - - X
1 - - X
2 - - X
number of moves:   7


Congratulations, game finished in 7 moves.
```
