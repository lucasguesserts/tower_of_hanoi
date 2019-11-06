#ifndef TOWER_OF_HANOI_H
#define TOWER_OF_HANOI_H

#include <stdbool.h>

#define MAX_NUMBER_OF_RODS  3u
#define MAX_NUMBER_OF_DISKS 9u
#define MAX_NUMBER_OF_CHARS (2*MAX_NUMBER_OF_RODS + 2) * (MAX_NUMBER_OF_DISKS+1) + 22

typedef struct
{
    unsigned numberOfRods;
    unsigned numberOfDisks;
    unsigned numberOfMoves;
    bool     position[MAX_NUMBER_OF_DISKS][MAX_NUMBER_OF_RODS];
    char     asString[MAX_NUMBER_OF_CHARS];
} TowerOfHanoi;

typedef enum MOVE_ERROR
{
    valid_move,
    invalid_disk_error,
    invalid_rod_error,
    disk_not_on_top_error,
    over_smaller_disk_error,
    no_move_done_error
} MoveError;

void      initializeTowerOfHanoi(TowerOfHanoi * const th, const unsigned numberOfDisks, const unsigned numberOfRods);
bool      gameOverTowerOfHanoi(const TowerOfHanoi * const th);
MoveError moveDisk(TowerOfHanoi * const th, const unsigned diskToMove, const unsigned targetRod);
void      towerOfHanoi2string(TowerOfHanoi * const th);

#endif /* TOWER_OF_HANOI_H */
