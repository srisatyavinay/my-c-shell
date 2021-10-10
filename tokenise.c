#include "headers.h"

void tokenise(char *command)
{
    int redirect = 0;
    if (strstr(command, ">") == NULL && strstr(command, "<") != NULL)
    {
        redirect = 1;
    }
    else if (strstr(command, ">") != NULL && strstr(command, "<") == NULL)
    {
        redirect = 2;
    }
    if (strstr(command, ">") != NULL && strstr(command, "<") != NULL)
    {
        redirect = 3;
    }
    char *argtoken;
    int num_args = 0;

    argtoken = strtok(command, " \t\v");
    argument[num_args] = argtoken;

    while (argtoken != NULL)
    {
        num_args++;
        argtoken = strtok(NULL, " \t\v");
        argument[num_args] = argtoken;
    }

    if (redirect != 0)
    {
        int caseerr = redirection(redirect, num_args);
        if (caseerr == 1)
        {
            return;
        }
        if (redirect == 1)
        {
            num_args = num_args - 2;
        }
        if (redirect == 2)
        {
            num_args = num_args - 2;
        }
        if (redirect == 3)
        {
            num_args = num_args - 4;
        }
        if (num_args < 63)
        {
            argument[num_args] = NULL;
        }
    }

    for (int i = 0; i < num_args; i++)
    {
        if (strcmp(argument[i], "<") == 0 || strcmp(argument[i], ">") == 0 || strcmp(argument[i], ">>") == 0)
        {
            fprintf(stderr, "Syntax error");
            return;
        }
    }

    identify_command(argument, num_args);

    dup2(input, STDIN_FILENO);
    dup2(output, STDOUT_FILENO);
}

void identify_command(char **arg, int num)
{
    if (strcmp(arg[0], "echo") == 0)
    {
        echo_execution(arg, num);
    }
    else if (strcmp(arg[0], "cd") == 0)
    {
        cd_execution(arg, num);
    }
    else if (strcmp(arg[0], "pwd") == 0)
    {
        if (num == 1)
        {
            pwd_execution();
        }
        else
        {
            printf("Error: pwd: too many arguments\n");
        }
    }
    else if (strcmp(arg[0], "ls") == 0)
    {
        ls_execution(arg, num);
    }
    else if (strcmp(arg[0], "pinfo") == 0)
    {
        pinfo_execution(arg, num);
    }
    else if (strcmp(arg[0], "repeat") == 0)
    {
        int no_times = atoi(arg[1]);
        for (int i = 0; i < no_times; i++)
        {
            identify_command(arg + 2, num - 2);
        }
    }
    else if (strcmp(arg[0], "exit") == 0)
    {
        exit_execution();
    }
    else if (strcmp(arg[0], "jobs") == 0)
    {
        jobs_execution(arg, num);
    }
    else if (strcmp(arg[0], "sig") == 0)
    {
        sig_execution(arg, num);
    }
    else if (strcmp(arg[0], "fg") == 0)
    {
        fg_execution(arg, num);
    }
    else if (strcmp(arg[0], "bg") == 0)
    {
        bg_execution(arg, num);
    }
    else
    {
        background_execution(arg, num);
    }
}
