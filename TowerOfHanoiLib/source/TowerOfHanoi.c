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
	for (d=0 ; d<numberOfDisks ; ++d)
	{
		th->position[d][0] = true;
		for(r=1 ; r<numberOfRods ; ++r)
			th->position[d][r] = false;
	}
	return;
}