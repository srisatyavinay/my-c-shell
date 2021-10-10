#include "headers.h"

void cd_execution(char **arg, int num)
{
    char workingdir[1024];
    getcwd(workingdir, MAX_LENGTH);

    if (num > 2)
    {
        printf("Error: cd: too many arguments\n");
        return;
    }
    else if (num == 1)
    {
        if (chdir(invokedir) < 0)
        {
            perror("Invalid path");
        }
    }
    else if (strcmp(arg[1], "~") == 0)
    {
        if (chdir(invokedir) < 0)
        {
            perror("Invalid path");
        }
    }
    else if (strcmp(arg[1], ".") == 0)
    {
        return;
    }
    else if (strcmp(arg[1], "-") == 0)
    {
        if (chdir(prevdir) < 0)
        {
            perror("Invalid path");
        }
        else
        {
            printf("%s\n", prevdir);
        }
    }
    else if (arg[1][0] == '~')
    {
        int k = 1;

        char newpath[MAX_LENGTH];

        strcpy(newpath, invokedir);

        newpath[strlen(invokedir)] = '/';

        for (k = 1; k < strlen(arg[1]); k++)
        {
            newpath[strlen(invokedir) + k] = arg[1][k];
        }

        newpath[strlen(invokedir) + k] = '\0';
        if (chdir(newpath) < 0)
        {
            perror("Invalid path");
        }
    }
    else
    {
        if (chdir(arg[1]) < 0)
        {
            perror("Invalid path");
        }
    }
    strcpy(prevdir, workingdir);
    getcwd(workingdir, MAX_LENGTH);
}
