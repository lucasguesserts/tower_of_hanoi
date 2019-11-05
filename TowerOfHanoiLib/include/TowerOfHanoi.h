#ifndef TOWER_OF_HANOI_H
#define TOWER_OF_HANOI_H

#include <stdbool.h>

#define MAX_NUMBER_OF_RODS 3u
#define MAX_NUMBER_OF_DISKS 10u

typedef struct
{
    unsigned int numberOfRods;
    unsigned int numberOfDisks;
    unsigned int numberOfMoves;
    bool position[MAX_NUMBER_OF_DISKS][MAX_NUMBER_OF_RODS];
} TowerOfHanoi;

void initializeTowerOfHanoi(const unsigned int numberOfDisks, const unsigned int numberOfRods, TowerOfHanoi *th);
bool checkFinishedTowerOfHanoi(const TowerOfHanoi * const th);

#endif /* TOWER_OF_HANOI_H */
