#include "headers.h"

void ctrl_c_execution(int signum)
{
    int ppid = getpid();
    if (ppid == shellpid)
    {
        if (fprocpid != -1)
        {
            kill(fprocpid, SIGINT);
        }
    }
    else
    {
        return;
    }
    signal(SIGINT, ctrl_c_execution);
}

void ctrl_z_execution(int signum)
{
    int ppid = getpid();
    if (ppid == shellpid)
    {
        if (fprocpid != -1)
        {
            kill(fprocpid, SIGTTIN);
            kill(fprocpid, SIGTSTP);
            struct back *newback = malloc(sizeof(struct back));
            struct back *prev = NULL;
            struct back *curr = present;
            backnum++;
            strcpy(newback->backname, fproc->fname);
            newback->backpid = fprocpid;
            newback->jobnum = backnum;
            if (curr == NULL)
            {
                newback->next = NULL;
                present = newback;
            }
            else
            {
                while (strcmp(fproc->fname, curr->backname) >= 0)
                {
                    prev = curr;
                    curr = curr->next;
                    if (curr == NULL)
                    {
                        break;
                    }
                }
                if (prev != NULL)
                {
                    prev->next = newback;
                    newback->next = curr;
                }
                else
                {
                    newback->next = curr;
                    present = newback;
                }
            }
        }
    }
    else
    {
        return;
    }
    signal(SIGTSTP, ctrl_z_execution);
}
