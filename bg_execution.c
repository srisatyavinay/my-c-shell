#include "headers.h"

void bg_execution(char **arg, int num)
{
    if (num == 2)
    {
        int njob = atoi(arg[1]);
        int jpid;

        int found = 0;

        struct back *jobptr = present;

        while (jobptr != NULL)
        {
            if (jobptr->jobnum == njob)
            {
                found = 1;
                jpid = jobptr->backpid;
                break;
            }
        }
        if (found == 1)
        {
            kill(jpid, SIGCONT);
        }
        else
        {
            fprintf(stderr, "Enter valid job number\n");
        }
    }
    else
    {
        fprintf(stderr, "jobs: Incorrect syntax\n");
    }
}
