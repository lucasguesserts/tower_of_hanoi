#include <stdio.h>
#include <TowerOfHanoi.h>
#include <stdlib.h>
#include <string.h>

/* ----- Functions for implementing 'moveDisk' ---- */
unsigned findDisk(const TowerOfHanoi * const th, const unsigned disk);
bool diskOnTopOfStack(const TowerOfHanoi * const th, const unsigned disk);
bool overSmallerDisk(const TowerOfHanoi * const th, const unsigned disk, const unsigned targetRod);
/* ---------- */

void initializeTowerOfHanoi(TowerOfHanoi *const th, const unsigned numberOfDisks, const unsigned numberOfRods)
{
	unsigned r, d;
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

bool gameOverTowerOfHanoi(const TowerOfHanoi * const th)
{
	bool gameOver = true;
	unsigned d, r;
	for (d=0 ; d<th->numberOfDisks ; ++d)
	{
		for (r=0 ; r<(th->numberOfRods-1) ; ++r)
			gameOver = gameOver && (th->position[d][r]==false);
		gameOver = gameOver && (th->position[d][th->numberOfRods-1]==true);
	}
	return gameOver;
}

MoveError moveDisk(TowerOfHanoi * const th, const unsigned diskToMove, const unsigned targetRod)
{
	unsigned r;
	MoveError returnCode;
	if ( diskToMove > th->numberOfDisks)
		returnCode = invalid_disk_error;
	else if (targetRod > th->numberOfRods)
		returnCode = invalid_rod_error;
	else if (! diskOnTopOfStack(th, diskToMove))
		returnCode = disk_not_on_top_error;
	else if (overSmallerDisk(th, diskToMove, targetRod))
		returnCode = over_smaller_disk_error;
	else if (th->position[diskToMove][targetRod])
		returnCode = no_move_done_error;
	else
	{
		returnCode = valid_move;
		for (r=0 ; r<th->numberOfRods ; ++r)
			th->position[diskToMove][r] = false;
		th->position[diskToMove][targetRod] = true;
		th->numberOfMoves++;
	}
	return returnCode;
}

/* ----- Functions for implementing 'moveDisk' ---- */

unsigned findDisk(const TowerOfHanoi * const th, const unsigned disk)
{
	unsigned rod;
	for (rod=0 ; rod<(th->numberOfRods) ; ++rod)
		if (th->position[disk][rod])
			break;
	return rod;
}

bool diskOnTopOfStack(const TowerOfHanoi * const th, const unsigned disk)
{
	unsigned d, rod;
	bool isOnTop = true;
	rod = findDisk(th, disk);
	for (d=0 ; d<disk ; ++d)
		if (th->position[d][rod])
		{
			isOnTop = false;
			break;
		}
	return isOnTop;
}

bool overSmallerDisk(const TowerOfHanoi * const th, const unsigned disk, const unsigned targetRod)
{
	unsigned d;
	bool isThereSmaller = false;
	for (d=0 ; d<disk ; ++d)
		if (th->position[d][targetRod])
		{
			isThereSmaller = true;
			break;
		}
	return isThereSmaller;
}

/* ---------- */

void towerOfHanoi2string(TowerOfHanoi * const th)
{
	/*
	  0 1 2\n
	0 X - -\n
	1 X - -\n
	2 X - -\n
	number of moves: %3i\n\0
	*/
	unsigned d, r;
	char buf[5];
	/* Initialize empty */
	for (d=0 ; d<MAX_NUMBER_OF_CHARS ; ++d)
		th->asString[d] = '\0';
	/* Rod's numbers */
	strcat(th->asString, " ");
	for (r=0 ; r<th->numberOfRods ; ++r)
	{
		sprintf(buf," %1i",r);
		strcat(th->asString, buf);
	}
	strcat(th->asString, "\n");
	/* Disk's row */
	for (d=0 ; d<th->numberOfDisks ; ++d)
	{
		sprintf(buf,"%1i",d);
		strcat(th->asString, buf);
		for (r=0 ; r<th->numberOfRods ; ++r)
		{
			if (th->position[d][r])
				strcat(th->asString, " X");
			else
				strcat(th->asString, " -");
		}
		strcat(th->asString, "\n");
	}
	/* Number of move's row */
	strcat(th->asString, "number of moves: ");
	sprintf(buf, "%3i\n", th->numberOfMoves);
	strcat(th->asString, buf);
}