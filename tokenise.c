#include "headers.h"

void tokenise(char* command)
{
    char *argtoken;
    int num_args = 0;
    // int ret;
    // printf( "|%s|\n", command );

    argtoken = strtok(command, " \t\v");
    argument[num_args] = argtoken;
    // printf( "|%s|\n", argument[num_args] );
    // return;

    while( argtoken != NULL ) 
    {
        // printf( "|%s|\n", argument[num_args] );
        num_args++;
        argtoken = strtok(NULL, " \t\v");
        argument[num_args] = argtoken;
    }
    // printf("%d\n", num_args);
    // printf("%s\n", argument[0]);

    identify_command(argument, num_args);
    // if(strcmp(argument[0], "echo") == 0)
    // {
    //     echo_execution(argument, num_args);
    // }
    // if(strcmp(argument[0], "cd") == 0)
    // {
    //     cd_execution(argument, num_args);
    // }
    // if(strcmp(argument[0], "pwd") == 0)
    // {
    //     // printf("a\n");
    //     pwd_execution();
    // }
    // if(strcmp(argument[0], "ls") == 0)
    // {
    //     ls_execution(argument, num_args);
    // }
}

void identify_command(char** arg, int num)
{
    if(strcmp(arg[0], "echo") == 0)
    {
        echo_execution(arg, num);
    }
    else if(strcmp(arg[0], "cd") == 0)
    {
        cd_execution(arg, num);
    }
    else if(strcmp(arg[0], "pwd") == 0)
    {
        // printf("a\n");
        pwd_execution();
    }
    else if(strcmp(arg[0], "ls") == 0)
    {
        ls_execution(arg, num);
    }
    else if(strcmp(arg[0], "pinfo") == 0)
    {
        pinfo_execution(arg, num);
    }
    else if(strcmp(arg[0], "repeat") == 0)
    {
        int no_times = atoi(arg[1]);
        for(int i = 0; i < no_times; i++)
        {
            identify_command(arg + 2, num - 2);
        }
    }
    // else if(strcmp(arg[0], "history") == 0)
    // {
    //     history_execution(arg, num);
    // }
    else if(strcmp(arg[0], "exit") == 0)
    {
        exit_execution();
    }
    else
    {
        background_execution(arg, num);
    }
}

