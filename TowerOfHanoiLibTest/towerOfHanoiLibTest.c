#include <CuTest.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <TowerOfHanoi.h>
#include <unistd.h>

#ifndef LOG_OUTPUT
#define LOG_OUTPUT "./"
#endif

CuSuite* StrUtilGetSuite(void);
char logFilePath[400];

/* ---------- Declare here your tests ---------- */
void Test_initialize_tower_of_hanoi(CuTest *tc);
void Test_check_game_over(CuTest *tc);
void Test_check_false_game_over(CuTest *tc);
void Test_move_disk(CuTest *tc);
void Test_move_disk_errors(CuTest *tc);
void Test_display_tower_of_hanoi(CuTest *tc);

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
	SUITE_ADD_TEST(suite, Test_initialize_tower_of_hanoi);
	SUITE_ADD_TEST(suite, Test_check_game_over);
	SUITE_ADD_TEST(suite, Test_check_false_game_over);
	SUITE_ADD_TEST(suite, Test_move_disk);
	SUITE_ADD_TEST(suite, Test_move_disk_errors);
	SUITE_ADD_TEST(suite, Test_display_tower_of_hanoi);
	return suite;
}

/* ---------- Implement here your tests ---------- */

#define NUMBER_OF_DISKS 5u
#define NUMBER_OF_RODS  3u

void Test_initialize_tower_of_hanoi(CuTest *tc)
{
	/* Auxiliar variables */
	unsigned d, r;
	/* Initialize values */
	bool position[NUMBER_OF_DISKS][NUMBER_OF_RODS] =
	{
		{true, false, false},
		{true, false, false},
		{true, false, false},
		{true, false, false},
		{true, false, false},
	};
	/* Initialize tower of hanoi */
	TowerOfHanoi th;
	initializeTowerOfHanoi(&th, NUMBER_OF_DISKS, NUMBER_OF_RODS);
	/* Test */
	CuAssertIntEquals(tc, NUMBER_OF_RODS,  th.numberOfRods);
	CuAssertIntEquals(tc, NUMBER_OF_DISKS, th.numberOfDisks);
	CuAssertIntEquals(tc, 0u,              th.numberOfMoves);
	for(d=0 ; d<NUMBER_OF_DISKS ; ++d)
		for(r=0 ; r<NUMBER_OF_RODS ; ++r)
			CuAssertIntEquals(tc, position[d][r], th.position[d][r]);
	return;
}

void Test_check_game_over(CuTest *tc)
{
	/* Auxiliar variables */
	unsigned d, r;
	/* Initialize finished tower of hanoi */
	TowerOfHanoi th;
	initializeTowerOfHanoi(&th, NUMBER_OF_DISKS, NUMBER_OF_RODS);
	for (d=0 ; d<NUMBER_OF_DISKS ; ++d)
	{
		for(r=0 ; r<(NUMBER_OF_RODS-1) ; ++r)
			th.position[d][r] = false;
		th.position[d][NUMBER_OF_RODS-1] = true;
	}
	/* Test */
	CuAssertTrue(tc, gameOverTowerOfHanoi(&th));
	return;
}

void Test_check_false_game_over(CuTest *tc)
{
	/* Auxiliar variables */
	unsigned d, r;
	/* Initialize finished tower of hanoi */
	TowerOfHanoi th, trueOutOfPlace, falseOutOfPlace;
	initializeTowerOfHanoi(&th, NUMBER_OF_DISKS, NUMBER_OF_RODS);
	for (d=0 ; d<NUMBER_OF_DISKS ; ++d)
	{
		for(r=0 ; r<(NUMBER_OF_RODS-1) ; ++r)
			th.position[d][r] = false;
		th.position[d][NUMBER_OF_RODS-1] = true;
	}
	/* Tests */
	/* One true out of place*/
	trueOutOfPlace = th;
	trueOutOfPlace.position[0][0] = true;
	CuAssertTrue(tc, gameOverTowerOfHanoi(&trueOutOfPlace)==false);
	/* One false out of place*/
	falseOutOfPlace = th;
	falseOutOfPlace.position[2][NUMBER_OF_RODS-1] = false;
	CuAssertTrue(tc, gameOverTowerOfHanoi(&falseOutOfPlace)==false);
	return;
}

void Test_move_disk(CuTest *tc)
{
	/* Initialize tower of hanoi */
	TowerOfHanoi th;
	initializeTowerOfHanoi(&th, NUMBER_OF_DISKS, NUMBER_OF_RODS);
	/* Disk 0 from rod 0 to rod 1 */
	moveDisk(&th, 0, 1);
	CuAssertIntEquals(tc, false, th.position[0][0]);
	CuAssertIntEquals(tc, true , th.position[0][1]);
	CuAssertIntEquals(tc, 1,     th.numberOfMoves);
	/* Disk 1 from rod 0 to rod 2 */
	moveDisk(&th, 1, 2);
	CuAssertIntEquals(tc, false, th.position[1][0]);
	CuAssertIntEquals(tc, true , th.position[1][2]);
	CuAssertIntEquals(tc, 2,     th.numberOfMoves);
	/* Disk 0 from rod 1 to rod 2 */
	moveDisk(&th, 0, 2);
	CuAssertIntEquals(tc, false, th.position[0][1]);
	CuAssertIntEquals(tc, true , th.position[0][2]);
	CuAssertIntEquals(tc, 3,     th.numberOfMoves);
	return;
}

void Test_move_disk_errors(CuTest *tc)
{
	/* Initialize tower of hanoi */
	TowerOfHanoi th;
	initializeTowerOfHanoi(&th, NUMBER_OF_DISKS, NUMBER_OF_RODS);
	/* Attempt to move and check errors */
	CuAssertIntEquals(tc, valid_move,              moveDisk(&th, 0, 1));
	CuAssertIntEquals(tc, no_move_done_error,      moveDisk(&th, 0, 1));
	CuAssertIntEquals(tc, disk_not_on_top_error,   moveDisk(&th, 3, 1));
	CuAssertIntEquals(tc, invalid_disk_error,      moveDisk(&th, 9, 1));
	CuAssertIntEquals(tc, invalid_rod_error,       moveDisk(&th, 0, 6));
	CuAssertIntEquals(tc, over_smaller_disk_error, moveDisk(&th, 1, 1));
	CuAssertIntEquals(tc, 1,                       th.numberOfMoves);
	return;
}

void Test_display_tower_of_hanoi(CuTest *tc)
{
	/* Auxiliar */
	char buffer[] = "X - - \nX - - \nX - - \nX - - \nX - - \nnumber of moves:   0\n";
	/* Initialize tower of hanoi */
	TowerOfHanoi th;
	char *asString = NULL;
	initializeTowerOfHanoi(&th, NUMBER_OF_DISKS, NUMBER_OF_RODS);
	/* Check */
	asString = towerOfHanoi2string(&th);
	CuAssertStrEquals(tc, buffer, asString);
	/* Free memory */
	free(asString);
	return;
}