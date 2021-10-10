#include "headers.h"

void sig_execution(char **arg, int num)
{
    if (num == 3)
    {
        int njob = atoi(arg[1]);
        int sig = atoi(arg[2]);
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
            kill(jpid, sig);
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
