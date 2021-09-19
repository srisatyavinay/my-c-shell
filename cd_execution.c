#include "headers.h"

void cd_execution(char** arg, int num)
{
    char workingdir[1024];
    getcwd(workingdir, MAX_LENGTH);
    // printf("Before : %s\n", workingdir);
    if(num > 2)
    {
        // printf("1\n");
        printf("Error: cd: too many arguments\n");
        return;
    }
    else if(num == 1)
    {
        // printf("2\n");
        chdir(invokedir);
    }
    else if(strcmp(arg[1], "~") == 0)
    {
        // printf("3\n");
        chdir(invokedir);
    }
    else if(strcmp(arg[1], ".") == 0)
    {
        // printf("4\n");
        return;
    }
    else if(strcmp(arg[1], "-") == 0)
    {
        // printf("5\n");
        chdir(prevdir);
        printf("%s\n", prevdir);
    }
    else if(arg[1][0] == '~')
    {
        // printf("6\n");
        int k = 1;

        char newpath[MAX_LENGTH];

        strcpy(newpath, invokedir);

        newpath[strlen(invokedir)] = '/';

        for(k = 1; k < strlen(arg[1]); k++)
        {
            newpath[strlen(invokedir) + k] = arg[1][k];
        }

        newpath[strlen(invokedir) + k] = '\0';
        chdir(newpath);
    }
    else
    {
        // printf("7\n");
        chdir(arg[1]);
    }
    strcpy(prevdir, workingdir);
    getcwd(workingdir, MAX_LENGTH);
    // printf("After : %s\n", workingdir);
}