#include "headers.h"

void background_execution(char **arg, int num)
{
    int backproc = 0;
    // printf("aaaaaaaaaaagggggggggggg\n");
    // printf("%d", num);
    if(strcmp(arg[num - 1], "&") == 0)
    {
        backproc = 1;
        // printf("aaaaaaaaaaaggggggggggggbfjgrgjggew\n");
    }
    int forkret = fork();
    
    if(forkret < 0)
    {
        perror("Error while forking");
    }
    else if(forkret == 0)
    {
        // printf("%d\n", forkret);
        if(backproc == 0)
        {
            setpgid(0, 0);
        }
        int ex;
        // if(strcmp(arg[0], "vi") != 0)
        // {
            ex = execvp(arg[0], arg);
        // }
        // else
        // {
        //     ex = execvp("vi", arg);
        // }
        if (ex < 0)
        {
            fprintf(stderr, "Error occured during the execution of %s command\n", arg[0]);
            perror("");
            exit(1);
        }
    }
    else
    {
        int val;
        if(backproc != 0)
        {
            printf("%d\n", forkret);
            waitpid(forkret, &val, WUNTRACED);
        }
        else
        {
            struct back *newback = malloc(sizeof(struct back));
            strcpy(newback, arg[0]);
            newback->backpid = forkret;
            newback->next = present;
            if(newback->next != NULL)
            {
                first = newback;
            }
            present = newback;
        }
    }
}