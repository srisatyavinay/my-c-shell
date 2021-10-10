#include "headers.h"

void background_execution(char **arg, int num)
{
    int backproc = 0;

    if (strcmp(arg[num - 1], "&") == 0)
    {
        backproc = 1;
        arg[num - 1] = NULL;
    }

    int forkret = fork();

    if (forkret == 0)
    {

        if (backproc == 1)
        {
            setpgid(0, 0);
        }
        int ex;
        ex = execvp(arg[0], arg);
        if (ex < 0)
        {
            fprintf(stderr, "Error occured during the execution of %s command\n", arg[0]);

            exit(1);
        }
    }
    else if (forkret < 0)
    {
        perror("Error while forking");
    }
    else
    {
        int val;
        if (backproc != 1)
        {
            fprocpid = forkret;
            fproc->fpid = fprocpid;
            strcpy(fproc->fname, arg[0]);
            waitpid(forkret, &val, WUNTRACED);
        }
        else
        {
            printf("%d\n", forkret);
            struct back *newback = malloc(sizeof(struct back));
            struct back *prev = NULL;
            struct back *curr = present;
            backnum++;
            strcpy(newback->backname, arg[0]);
            newback->backpid = forkret;
            newback->jobnum = backnum;
            if (curr == NULL)
            {
                newback->next = NULL;
                present = newback;
            }
            else
            {
                while (strcmp(arg[0], curr->backname) >= 0)
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
}
