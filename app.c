#include<stdio.h>
#include<stdlib.h>
#include"emlog.h"
#include"test_case.h"

int main(void)
{
    EMLOG(LOG_INFORMATION, "Start");

    const char *test_case_list[] = {
        "testCase1",
        "testCase2",
        "testCase3",
        "testCase4"
    };

    for(int i = 0; i < (sizeof(test_case_list) / sizeof(test_case_list[0])); i++)
    {
        EMLOG(LOG_DEBUG, "%s", test_case_list[i]);
        runTest(test_case_list[i]);
    } 
    
    EMLOG(LOG_INFORMATION, "End");
    return 0;
}