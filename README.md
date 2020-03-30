<!-- START doctoc generated TOC please keep comment here to allow auto update -->
<!-- DON'T EDIT THIS SECTION, INSTEAD RE-RUN doctoc TO UPDATE -->
**Table of Contents**  *generated with [DocToc](https://github.com/thlorenz/doctoc)*

- [Tower of Hanoi](#tower-of-hanoi)
- [Game Definition](#game-definition)
- [How to Use](#how-to-use)
  - [Example - Creating and Solving a 3-disk Game](#example---creating-and-solving-a-3-disk-game)
  - [Interactive Game](#interactive-game)
  - [Optimized Algorithm](#optimized-algorithm)
- [About](#about)

<!-- END doctoc generated TOC please keep comment here to allow auto update -->

# Tower of Hanoi

[![Travis (.org) branch](https://img.shields.io/travis/lucasguesserts/tower_of_hanoi/master?label=Build%20Master)](https://travis-ci.org/lucasguesserts/tower_of_hanoi)
[![Documentation](https://codedocs.xyz/lucasguesserts/tower_of_hanoi.svg)](https://codedocs.xyz/lucasguesserts/tower_of_hanoi/)
![codecoverage](https://img.shields.io/badge/coverage-100%25-brightgreen)

Implementation of the [Tower of Hanoi](http://www.towerofhanoi.org/) game in C.

# Game Definition

It consists of a finite set of **Rods** and **Disks**.
The rods are organized in a line and each disk has a
different diameter.

- **Start:** All the disks are organized in ascending diameter in the first rod.
- **Goal:** Move all the disks to the last rod.
- **Rules:**
  1. Only one disk can be moved at a time.
  2. Only the disks on top of each rod may be moved.
  3. Disks cannot be placed on top of smaller disks.

# Building

```shell
git clone git@github.com:lucasguesserts/tower_of_hanoi.git
mkdir build
cd build
cmake ..
make

# Choose an app to run
./bin/InteractiveTowerOfHanoi
./OptimizedAlgorithmTowerOfHanoi
```



# How to Use

The representation of a Tower of Hanoi game is made
by the structure [TowerOfHanoi](./TowerOfHanoiLib/include/TowerOfHanoi.h).
The first step is
to create an instance of that structure and initialize
it. After that, the movements can be executed and,
at any point, the end of the game can be checked.

All the game manipulation functions are available
in the file
[TowerOfHanoi.h](./TowerOfHanoiLib/include/TowerOfHanoi.h).

## Example - Creating and Solving a 3-disk Game

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

## Interactive Game

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

# Documentation

All the information about the project is available in its documentation. The documentation of the latest version is available online in [html](https://codedocs.xyz/lucasguesserts/tower_of_hanoi/index.html) and [pdf](./doc/pdf_releases/latest.pdf) formats.

Older releases have their documentation available only in the pdf format in [this folder](./doc/pdf_releases/).