#include <stdio.h>
#include <TowerOfHanoi.h>

/* ----- Functions for implementing 'moveDisk' ---- */
unsigned int findDisk(const TowerOfHanoi * const th, const unsigned int disk);
bool diskOnTopOfStack(const TowerOfHanoi * const th, const unsigned int disk);
bool overSmallerDisk(const TowerOfHanoi * const th, const unsigned int disk, const unsigned int rodDestination);
/* ---------- */

void initializeTowerOfHanoi(const unsigned int numberOfDisks, const unsigned int numberOfRods, TowerOfHanoi *th)
{
	unsigned int r, d;
	/*
		Missing to check the value of
		'numberOfDisks' and 'numberOfRods'
	*/
	th->numberOfDisks = numberOfDisks;
	th->numberOfRods = numberOfRods;
	th->numberOfMoves = 0u;
	for (d=0 ; d<numberOfDisks ; ++d)
	{
		th->position[d][0] = true;
		for(r=1 ; r<numberOfRods ; ++r)
			th->position[d][r] = false;
	}
	return;
}

bool checkFinishedTowerOfHanoi(const TowerOfHanoi * const th)
{
	bool gameOver = true;
	unsigned int d, r;
	for (d=0 ; d<th->numberOfDisks ; ++d)
	{
		for (r=0 ; r<(th->numberOfRods-1) ; ++r)
			gameOver = gameOver && (th->position[d][r]==false);
		gameOver = gameOver && (th->position[d][th->numberOfRods-1]==true);
	}
	return gameOver;
}

moveError moveDisk(TowerOfHanoi * const th, const unsigned int diskToMove, const unsigned int rodDestination)
{
	unsigned int r;
	moveError returnCode;
	if ( diskToMove > th->numberOfDisks)
		returnCode = invalid_disk_error;
	else if (rodDestination > th->numberOfRods)
		returnCode = invalid_rod_error;
	else if (! diskOnTopOfStack(th, diskToMove))
		returnCode = disk_not_on_top_error;
	else if (overSmallerDisk(th, diskToMove, rodDestination))
		returnCode = over_smaller_disk_error;
	else if (th->position[diskToMove][rodDestination])
		returnCode = no_move_done_error;
	else
	{
		returnCode = valid_move;
		for (r=0 ; r<th->numberOfRods ; ++r)
			th->position[diskToMove][r] = false;
		th->position[diskToMove][rodDestination] = true;
	}
	return returnCode;
}

/* ----- Functions for implementing 'moveDisk' ---- */

unsigned int findDisk(const TowerOfHanoi * const th, const unsigned int disk)
{
	unsigned int rod;
	for (rod=0 ; rod<(th->numberOfRods) ; ++rod)
		if (th->position[disk][rod])
			break;
	return rod;
}

bool diskOnTopOfStack(const TowerOfHanoi * const th, const unsigned int disk)
{
	unsigned int d, rod;
	rod = findDisk(th, disk);
	bool isOnTop = true;
	for (d=0 ; d<disk-1 ; ++d)
		if (th->position[d][rod])
		{
			isOnTop = false;
			break;
		}
	return isOnTop;
}

bool overSmallerDisk(const TowerOfHanoi * const th, const unsigned int disk, const unsigned int rodDestination)
{
	unsigned d;
	bool isThereSmaller = true;
	for (d=0 ; d<disk-1 ; ++d)
		if (th->position[d][rodDestination])
		{
			isThereSmaller = false;
			break;
		}
	return isThereSmaller;
}

/* ---------- */