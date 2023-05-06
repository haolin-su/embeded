#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"test_case.h"
#include"emlog.h"

static int testCase1(int a, int b)
{
    return (a + b);
}

static int testCase2(int a, int b)
{
    return (a - b);
}

static int testCase3(int a, int b)
{
    return (a * b);
}

static int testCase4(int a, int b)
{
    return (a / b);
}

static TESTCASE *addTestCase(int (*TestCase)(int, int))
{
    TESTCASE *test_case_item;
    test_case_item->TestCase = TestCase;
    return test_case_item;
}

void runTest(const char* test_case)
{
    int a = 2;
    int b = 1;
    int output = 0;
    static int test_count = 0;
    TESTCASE *p_test_case;
    
    EMLOG(LOG_DEBUG, "Add %s", test_case);

    if(!strcmp(test_case, "testCase1")){
        p_test_case = addTestCase(testCase1);
    }else if (!strcmp(test_case, "testCase2"))
    {
        p_test_case = addTestCase(testCase2);
    }else if (!strcmp(test_case, "testCase3"))
    {
        p_test_case = addTestCase(testCase3);
    }else if (!strcmp(test_case, "testCase4"))
    {
        p_test_case = addTestCase(testCase4);
    }else{
        p_test_case = NULL;
    }
    
    if(p_test_case == NULL){
        EMLOG(LOG_ERROR, "No matching test case");
        free(p_test_case);
        return;
    }

    EMLOG(LOG_DEBUG, "Run %s", test_case); 
    output = p_test_case->TestCase(a, b);

    EMLOG(LOG_DEBUG, "output = %d,  test_out_ref = %d", output, test_out_ref[test_count]);

    if(output != test_out_ref[test_count]){
        EMLOG(LOG_INFORMATION, "%s failed, %d != %d", test_case, output, test_out_ref[test_count]);
    }
    else
    {
        EMLOG(LOG_INFORMATION, "%s success", test_case);
    }
    test_count++;
}