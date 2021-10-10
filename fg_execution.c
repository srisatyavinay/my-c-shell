#include "headers.h"

void fg_execution(char **arg, int num)
{
    if (num == 2)
    {
        int njob = atoi(arg[1]);
        int jpid;
        char jname[1024];

        int found = 0;

        struct back *jobptr = present;

        while (jobptr != NULL)
        {
            if (jobptr->jobnum == njob)
            {
                found = 1;
                jpid = jobptr->backpid;
                strcpy(jname, jobptr->backname);
                break;
            }
        }
        if (found == 1)
        {
            int jval;
            kill(jpid, SIGCONT);
            strcpy(fproc->fname, jname);
            fproc->fpid = jpid;
            struct back *jprev, *jcurr;
            jcurr = present;
            jprev = NULL;
            while (jcurr != NULL)
            {
                if (jcurr->backpid == jpid)
                {
                    if (jprev == NULL)
                    {
                        present = jcurr->next;
                        free(jcurr);
                    }
                    else
                    {
                        jprev->next = jcurr->next;
                        free(jcurr);
                    }
                }
                jprev = jcurr;
                jcurr = jcurr->next;
            }
            waitpid(jpid, &jval, WUNTRACED);
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
