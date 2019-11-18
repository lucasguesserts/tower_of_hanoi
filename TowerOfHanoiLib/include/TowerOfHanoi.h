#ifndef TOWER_OF_HANOI_H
#define TOWER_OF_HANOI_H

/** @file TowerOfHanoi.h
  * @brief All tower of hanoi game functionalities.
  */

#include <stdbool.h>

#define MAX_NUMBER_OF_RODS  3u
#define MAX_NUMBER_OF_DISKS 9u
#define MAX_NUMBER_OF_CHARS (2*MAX_NUMBER_OF_RODS + 2) * (MAX_NUMBER_OF_DISKS+1) + 22

/**
  * @struct TowerOfHanoi TowerOfHanoi.h "TowerOfHanoiLib/TowerOfHanoi.h"
  * @brief Representation of the Tower of Hanoi game.
  *
  * **Rods Representation:**
  * Each rod is represented by a column in the
  * _position_ matrix. The starting Rod is the column
  * zero and the ending Rod is the last one.
  * The number of Rods is set dinamically and can be
  * accessed by the member _numberOfRods_.
  *
  * **Disks Representation:**
  * Each disk is represented by a line in the _position_ matrix.
  * Disks with small diameter are on top.
  * Disks with larger diameters are at the bottom.
  * When the disk _i_ is on the Rod _j_, the value
  * _i,j_ of the _position_ matrix is _true_. It is
  * _false_ if the disk is not there.
  * The number of Disks is set dinamically and can be
  * accessed by the member _numberOfDisks_.
  *
  * **Move Counter:**
  * After each move the member _numberOfMoves_
  * is incremented being, therefore, the counter
  * of moves.
  *
  * **String Representation:**
  * The game may be displayed as a string. In that case,
  * the member _asString_ has to be updated and can be
  * shown using, for example, _printf_ (from stdio.h).
  *
  * @note
  * The implementation uses static allocated data.
  * Its main purpouse is to be played or watched by
  * humans so long games are not that useful.
  * Dinamic memory allocation could be used though
  * (it is not difficult to implement).
  *
  * @sa [Tower of Hanoi wikipedia page](https://en.wikipedia.org/wiki/Tower_of_Hanoi).
  * @sa [Play the game online](https://www.mathsisfun.com/games/towerofhanoi.html).
  */
typedef struct
{
    unsigned numberOfRods;
    unsigned numberOfDisks;
    unsigned numberOfMoves;
    bool     position[MAX_NUMBER_OF_DISKS][MAX_NUMBER_OF_RODS];
    char     asString[MAX_NUMBER_OF_CHARS];
} TowerOfHanoi;

/**
 * @enum MoveError
 * @brief Representation of all possible outputs of a move.
 *
 * There is a defined set of errors when attempting
 * to move a disk. All of them, including a success
 * move, are represented in that _enum_.
 */
typedef enum MOVE_ERROR
{
    valid_move,
    invalid_disk_error,
    invalid_rod_error,
    disk_not_on_top_error,
    over_smaller_disk_error,
    no_move_done_error
} MoveError;

/**
 * @brief Initialize a Tower of Hanoi with all the disks at the beginning.
 *
 * @param[in,out] th Tower of Hanoi structure.
 * @param[in] numberOfDisks
 * @param[in] numberOfRods
 */
void initializeTowerOfHanoi(TowerOfHanoi * const th, const unsigned numberOfDisks, const unsigned numberOfRods);

/**
 * @brief Check whether the game is over or not.
 *
 * @param[in] th Tower of Hanoi game to be checked.
 * @return A bool value indicating if the game is over.
 */
bool gameOverTowerOfHanoi(const TowerOfHanoi * const th);

/**
 * @brief Move a disk in the game if possible. It returns the movement status.
 *
 * @param[in,out] th Tower of Hanoi structure.
 * @param[in] diskToMove The number of the disk to be move.
 * @param[in] targetRod The rod to where the disk will be moved.
 * @return MoveError Status of the move. See @ref MoveError for more details.
 */
MoveError moveDisk(TowerOfHanoi * const th, const unsigned diskToMove, const unsigned targetRod);

/**
 * @brief Update the string representation of the input game.
 *
 * @param th [in,out] th Tower of Hanoi structure.
 */
void towerOfHanoi2string(TowerOfHanoi * const th);

#endif /* TOWER_OF_HANOI_H */
