#include <TowerOfHanoi.h>
#include <stdio.h>
#include <stdlib.h>

int getInt(char message[]);

int main(void)
{
	TowerOfHanoi th;
	const unsigned numberOfDisks = 3, numberOfRods = 3;
	unsigned diskToMove, rodDestination;
	moveError moveRet;
	char *asString;
	initializeTowerOfHanoi(numberOfDisks, numberOfRods, &th);
	system("clear");

	while(!checkFinishedTowerOfHanoi(&th))
	{
		asString = towerOfHanoi2string(&th);
		printf("%s", asString);
		free(asString);
		diskToMove = getInt("Select a disk to move");
		rodDestination = getInt("Select a rod to move it into");
		moveRet = moveDisk(&th, diskToMove, rodDestination);
		system("clear");
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
				break;
		}
	}

	system("clear");
	printf("Congratulations, you have finished the game in %i moves.\n\n", th.numberOfMoves);
	return 0;
}

int getInt(char message[])
{
	int input, ret=EOF;
	while(ret==EOF)
	{
		printf("\n%s: ", message);
		ret = scanf("%i", &input);
	}
	return input;
}