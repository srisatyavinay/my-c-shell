#include "headers.h"

int main()
{
    backnum = 0;
    present = NULL;
    fprocpid = -1;
    shellpid = getpid();
    getcwd(invokedir, MAX_LENGTH);
    input = dup(STDIN_FILENO);
    output = dup(STDOUT_FILENO);
    fproc = malloc(sizeof(struct fore));
    
    signal(SIGINT, ctrl_c_execution);
    signal(SIGTSTP, ctrl_z_execution);

    while (1)
    {
        fprocpid = -1;

        print_prompt();

        char *lineptr = NULL;
        size_t readline;
        size_t len;
        int i = 0;

        readline = getdelim(&lineptr, &len, 10, stdin);

        if (readline == -1)
        {
            printf("\n");
            exit(1);
        }

        lineptr[readline - 1] = '\0';

        char *commtoken;
        commtoken = strtok(lineptr, ";");
        comm[i] = commtoken;

        while (commtoken != NULL)
        {
            i++;
            commtoken = strtok(NULL, ";");
            comm[i] = commtoken;
        }

        for (int j = 0; j < i; j++)
        {
            if (strstr(comm[j], "|") != NULL)
            {
                pipe_execution(comm[j]);
            }
            else
            {
                tokenise(comm[j]);
            }
        }

        check_for_bg_process();
    }
}
