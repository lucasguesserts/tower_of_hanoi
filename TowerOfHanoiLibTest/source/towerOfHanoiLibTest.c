#include <CuTest.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

#ifndef LOG_OUTPUT
#define LOG_OUTPUT "./"
#endif

CuSuite* StrUtilGetSuite(void);
char logFilePath[400];

/* ---------- Declare here your tests ---------- */
void Test_hello(CuTest *tc);

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
	SUITE_ADD_TEST(suite, Test_hello);
	return suite;
}

/* ---------- Implement here your tests ---------- */

void Test_hello(CuTest *tc)
{
	hello();
	CuAssertTrue(tc, 1);
	return;
}