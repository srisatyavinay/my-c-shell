#include "headers.h"

void pipe_execution(char *pipecommand)
{
    // printf("-------------\n");
    // return;
    char *pargtoken;
    int pnum_args = 0;
    int ppipes = 0;

    for(int i = 0; i < strlen(pipecommand); i++)
    {
        if(pipecommand[i] == '|')
        {
            ppipes++;
        }
    }

    pargtoken = strtok(pipecommand, "|");
    pargument[pnum_args] = pargtoken;

    while (pargtoken != NULL)
    {

        pnum_args++;
        pargtoken = strtok(NULL, "|");
        pargument[pnum_args] = pargtoken;
    }

    // printf("ppipes: %d\npnum_args: %d", ppipes, pnum_args);
    // return;

    if(pnum_args != ppipes + 1)
    {
        fprintf(stderr, "Syntax error");
        return;
    }

    int fildes[ppipes][2];

    // printf("-----------------------------------------\n");

    for(int i = 0; i < ppipes; i++)
    {
        int x = pipe(fildes[i]);
        // printf("%d\n", x);
        // continue;

        if(x < 0)
        {
            perror("Could not create pipe.");
            return;
        }
        else
        {
            if( i != 0)
            {
                // int outputfile, inputfile;
                // outputfile = dup(STDOUT_FILENO);
                // inputfile = dup(STDIN_FILENO);
                dup2(fildes[i - 1][0], STDIN_FILENO);
                dup2(fildes[i][1], STDOUT_FILENO);
                close(fildes[i - 1][0]);
                close(fildes[i][1]);
                tokenise(pargument[i]);
                // dup2(outputfile, STDOUT_FILENO);
                // dup2(inputfile, STDIN_FILENO);
                // close(inputfile);
                // close(outputfile);
            }
            if(i == 0)
            {
                // int outputfile;
                // outputfile = dup(STDOUT_FILENO);
                dup2(fildes[0][1], STDOUT_FILENO);
                close(fildes[0][1]);
                tokenise(pargument[0]);
                // dup2(outputfile, STDOUT_FILENO);
                // close(outputfile);
            }
        }
    }
    // int inputfile;
    // inputfile = dup(STDIN_FILENO);
    dup2(fildes[ppipes - 1][0], STDIN_FILENO);
    close(fildes[ppipes - 1][0]);
    tokenise(pargument[ppipes]);
    // dup2(inputfile, STDIN_FILENO);
    // close(inputfile);
}