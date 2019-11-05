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

typedef enum MoveError
{
    valid_move,
    invalid_disk_error,
    invalid_rod_error,
    disk_not_there_error,
    disk_not_on_top_error,
    over_smaller_disk_error,
    no_move_done_error
} moveError;

void initializeTowerOfHanoi(const unsigned int numberOfDisks, const unsigned int numberOfRods, TowerOfHanoi *th);
bool checkFinishedTowerOfHanoi(const TowerOfHanoi * const th);
moveError moveDisk(TowerOfHanoi * const th, const unsigned int disk, const unsigned int rod);
char * towerOfHanoi2string(const TowerOfHanoi * const th);

#endif /* TOWER_OF_HANOI_H */
