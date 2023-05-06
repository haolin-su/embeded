#ifndef _TEST_CASE_T_
#define _TEST_CASE_T_

typedef struct
{
    int (*TestCase)(int, int);
}TESTCASE;

static const int test_out_ref[] = {
    3,
    1,
    2,
    2,
};

typedef enum{
    TESTCASE1,
    TESTCASE2,
    TESTCASE3,
    TESTCASE4,
}TESTCASEITEM;

void runTest();

#endif