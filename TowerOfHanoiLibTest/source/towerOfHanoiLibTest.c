#include <CuTest.h>
#include <string.h>
#include <hello.h>

/* ---------- Declare here your tests ---------- */
/* Define the implementation of each test at the end fo the file. */
/* Add your test functions in the function 'StrUtilGetSuite' function. */

void Test_CuTest(CuTest *tc);

/* Suite which runs all the tests. */
CuSuite* StrUtilGetSuite(void);
char logFilePath[200];

int main(void)
{
	/* It is ready, it is not necessary to do
	nothing here when more tests are added. */
	CuString *output = CuStringNew();
	CuSuite *suite = CuSuiteNew();
	FILE *logFile;/* LOG_OUTPUT = ${CMAKE_BINARY_DIR}/log/ */
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
	SUITE_ADD_TEST(suite, Test_CuTest);
	return suite;
}

/* ---------- Implement here your tests ---------- */

void Test_CuTest(CuTest *tc)
{
	int actual   = 1;
	int expected = actual;
	CuAssertIntEquals(tc, expected, actual);
}

void Test_hello(CuTest *tc)
{
	hello();
	CuAssertTrue(tc, 0);
}