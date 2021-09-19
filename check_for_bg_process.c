#include "headers.h"

void check_for_bg_process()
{
    int processid, processstatus;

    for (;;)
    {
        int processid = waitpid(-1, &processstatus, WNOHANG | WUNTRACED);

        if (processid <= 0)
        {
            break;
        }
        if (WIFEXITED(processstatus) || WIFSIGNALED(processstatus))
        {
            struct back *previous;
            struct back *curr;
            previous = present;
            curr = present;

            if (present != NULL)
            {
                if (curr != NULL && curr->backpid == processid)
                {
                    present = present->next;
                    if (WIFEXITED(processstatus))
                    {
                        fprintf(stderr, "%s with pid %d exited normally\n", previous->backname, previous->backpid);
                    }
                    else
                    {
                        fprintf(stderr, "%s with pid %d exited abnormally\n", previous->backname, previous->backpid);
                    }
                    free(curr);
                }
                else
                {
                    while (curr != NULL && curr->backpid != processid)
                    {
                        previous = curr;
                        curr = curr->next;
                    }
                    if (curr != NULL)
                    {
                        previous->next = curr->next;
                        if (WIFEXITED(processstatus))
                        {
                            fprintf(stderr, "%s with pid %d exited normally\n", curr->backname, curr->backpid);
                        }
                        else
                        {
                            fprintf(stderr, "%s with pid %d exited abnormally\n", curr->backname, curr->backpid);
                        }
                        free(curr);
                    }
                }
            }
        }
    }
}