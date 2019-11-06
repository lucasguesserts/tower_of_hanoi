#include <TowerOfHanoi.h>
#include <stdio.h>
#include <stdlib.h>

void moveSubTower(TowerOfHanoi * const th, const unsigned currentRod, const unsigned biggestDisk, const unsigned targetRod);
void displayMessage(moveError moveRet, TowerOfHanoi * const th);

int main(void)
{
	TowerOfHanoi th;
	const unsigned numberOfDisks = 3, numberOfRods = 3;
	char *asString;
	initializeTowerOfHanoi(&th, numberOfDisks, numberOfRods);
	asString = towerOfHanoi2string(&th);
	printf("%s", asString);
	free(asString);
	printf("\n");
	moveSubTower(&th, 0, numberOfDisks-1, numberOfRods-1);
	printf("Congratulations, game finished in %i moves.\n\n", th.numberOfMoves);
	return 0;
}

void moveSubTower(TowerOfHanoi * const th, const unsigned currentRod, const unsigned biggestDisk, const unsigned targetRod)
{
	moveError moveRet;
	if (biggestDisk==0)
	{
		moveRet = moveDisk(th, biggestDisk, targetRod);
		displayMessage(moveRet, th);
	}
	else
	{
		moveSubTower(th, currentRod, biggestDisk-1, 3-currentRod-targetRod);
		moveRet = moveDisk(th, biggestDisk, targetRod);
		displayMessage(moveRet, th);
		moveSubTower(th, 3-currentRod-targetRod, biggestDisk-1, targetRod);
	}
	return;
}

void displayMessage(moveError moveRet, TowerOfHanoi * const th)
{
	char *asString;
	asString = towerOfHanoi2string(th);
	printf("%s", asString);
	free(asString);
	switch (moveRet)
	{
		case invalid_disk_error:
			printf("Invalid disk selected.\n\n");
			break;
		case invalid_rod_error:
			printf("Invalid rod selected.\n\n");
			break;
		case disk_not_on_top_error:
			printf("The selected disk is not on top of the stack.\n\n");
			break;
		case over_smaller_disk_error:
			printf("There is a disk smaller than the one selected on top of it.\n\n");
			break;
		case no_move_done_error:
			printf("Nothing really done...\n\n");
			break;
		case valid_move:
			printf("\n\n");
			break;
	}
	return;
}