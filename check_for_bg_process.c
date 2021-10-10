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
        else
        {
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
                        int exitstatus = WIFEXITED(processstatus);
                        present = present->next;
                        if (exitstatus)
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
                        for (; curr != NULL && curr->backpid != processid;)
                        {
                            previous = curr;
                            curr = curr->next;
                        }
                        if (curr != NULL)
                        {
                            int exitstatus = WIFEXITED(processstatus);
                            previous->next = curr->next;
                            if (exitstatus)
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
                else
                {
                    return;
                }
            }
        }
    }
}
