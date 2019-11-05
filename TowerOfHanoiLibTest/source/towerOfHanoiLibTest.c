#include <CuTest.h>
#include <string.h>
#include <stdio.h>
#include <TowerOfHanoi.h>

#ifndef LOG_OUTPUT
#define LOG_OUTPUT "./"
#endif

CuSuite* StrUtilGetSuite(void);
char logFilePath[400];

/* ---------- Declare here your tests ---------- */
void Test_tower_of_hanoi_structure(CuTest *tc);

int main(void)
{
	CuString *output = CuStringNew();
	CuSuite *suite = CuSuiteNew();
	FILE *logFile;
	strcpy(logFilePath, LOG_OUTPUT);
	strcat(logFilePath, "TowerOfHanoiLibTest.log");
	logFile = fopen(logFilePath, "w");

	CuSuiteAddSuite(suite, StrUtilGetSuite());

	CuSuiteRun(suite);
	CuSuiteSummary(suite, output);
	CuSuiteDetails(suite, output);
	fprintf(logFile, "%s\n", output->buffer);
	fclose(logFile);
	return suite->failCount;
}

CuSuite* StrUtilGetSuite(void)
{
	CuSuite* suite = CuSuiteNew();
	/* --- Add here all your tests --- */
	SUITE_ADD_TEST(suite, Test_tower_of_hanoi_structure);
	return suite;
}

/* ---------- Implement here your tests ---------- */

void Test_tower_of_hanoi_structure(CuTest *tc)
{
	/* Auxiliar variables */
	unsigned int d, r;
	/* Initialize values */
	#define NUMBER_OF_DISKS 5u
	#define NUMBER_OF_RODS  MAX_NUMBER_OF_RODS
	#define NUMBER_OF_MOVES 2u
	bool position[NUMBER_OF_DISKS][NUMBER_OF_RODS] =
	{
		{true,  false, false},
		{false, true,  false},
		{false, false, true },
		{true,  false, false},
		{false, false, true },
	};
	/* Initialize tower of hanoi */
	TowerOfHanoi th;
	th.numberOfRods  = NUMBER_OF_RODS;
	th.numberOfDisks = NUMBER_OF_DISKS;
	for(d=0 ; d<NUMBER_OF_DISKS ; ++d)
		for(r=0 ; r<NUMBER_OF_RODS ; ++r)
			th.position[d][r] = position[d][r];
	th.numberOfMoves = NUMBER_OF_MOVES;
	/* Test */
	CuAssertIntEquals(tc, NUMBER_OF_RODS,  th.numberOfRods);
	CuAssertIntEquals(tc, NUMBER_OF_DISKS, th.numberOfDisks);
	CuAssertIntEquals(tc, NUMBER_OF_MOVES, th.numberOfMoves);
	for(d=0 ; d<NUMBER_OF_DISKS ; ++d)
		for(r=0 ; r<NUMBER_OF_RODS ; ++r)
			CuAssertIntEquals(tc, position[d][r], th.position[d][r]);
	return;
}