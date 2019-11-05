#include <stdio.h>
#include <TowerOfHanoi.h>

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
	for(r=0 ; r<numberOfRods ; ++r)
	{
		th->position[r][0] = true;
		for (d=1 ; d<numberOfDisks ; ++d)
			th->position[r][d] = false;
	}
	return;
}