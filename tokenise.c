#include "headers.h"

void tokenise(char* command)
{
    char *argtoken;
    int num_args = 0;
    // printf( "|%s|\n", command );

    argtoken = strtok(command, " \t\v");
    argument[num_args] = argtoken;
    // printf( "|%s|\n", argument[num_args] );
    // return;

    while( argtoken != NULL ) 
    {
        printf( "|%s|\n", argument[num_args] );
        num_args++;
        argtoken = strtok(NULL, " \t\v");
        argument[num_args] = argtoken;
    }
    printf("%d\n", num_args);
    printf("%s\n", argument[0]);
    if(strcmp(argument[0], "echo") == 0)
    {
        echo_execution(argument, num_args);
    }
    if(strcmp(argument[0], "cd") == 0)
    {
        cd_execution(argument, num_args);
    }
    if(strcmp(argument[0], "pwd") == 0)
    {
        // printf("a\n");
        pwd_execution();
    }
    if(strcmp(argument[0], "ls") == 0)
    {
        ls_execution(argument, num_args);
    }
}

