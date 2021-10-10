#include "headers.h"

int redirection(int redirect, int num_args)
{
    for (int l = 0; l < num_args - 1; l++)
    {
        if (strcmp(argument[l], "<") == 0)
        {
            int x = open(argument[l + 1], O_RDONLY);

            if (x < 0)
            {
                perror("File error");
                return 1;
            }
            else
            {
                dup2(x, STDIN_FILENO);
                close(x);
            }
            for (int j = l; j < num_args - 2; j++)
            {
                strcpy(argument[j], argument[j + 2]);
            }
        }
        if (strcmp(argument[l], ">") == 0)
        {
            int x = open(argument[l + 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);

            if (x < 0)
            {
                perror("File error");
                return 1;
            }
            else
            {
                dup2(x, STDOUT_FILENO);
                close(x);
            }
            for (int j = l; j < num_args - 2; j++)
            {
                strcpy(argument[j], argument[j + 2]);
            }
        }
        if (strcmp(argument[l], ">>") == 0)
        {
            int x = open(argument[l + 1], O_WRONLY | O_CREAT | O_APPEND, 0644);

            if (x < 0)
            {
                perror("File error");
                return 1;
            }
            else
            {
                dup2(x, STDOUT_FILENO);
                close(x);
            }
            for (int j = l; j < num_args - 2; j++)
            {
                strcpy(argument[j], argument[j + 2]);
            }
        }
    }
    return 0;
}
