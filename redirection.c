#include "headers.h"

int redirection(int redirect, int num_args)
{
    if (redirect == 1 || redirect == 3)
    {
        // printf("1111111111111111111111\n");
        for(int i = 0; i < num_args - 1; i++)
        {
            if(strcmp(argument[i], "<") == 0)
            {
                // printf("abcd\n");
                int x = open(argument[i + 1], O_RDONLY);

                if(x < 0)
                {
                    perror("File error");
                    return 1;
                }
                else
                {
                    // printf("abcdefgh\n");
                    dup2(x, STDIN_FILENO);
                    close(x);
                }
                for(int j = i; j < num_args - 3; j++)
                {
                    strcpy(argument[j], argument[j + 2]);
                }
                num_args = num_args - 2;
                break;
            }
        }
    }
    if (redirect == 2 || redirect == 3)
    {
        // printf("1111111111111111111111\n");
        for(int i = 0; i < num_args - 1; i++)
        {
            if(strcmp(argument[i], ">") == 0)
            {
                int x = open(argument[i + 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);

                if(x < 0)
                {
                    perror("File error");
                    return 1;
                }
                else
                {
                    dup2(x, STDOUT_FILENO);
                    close(x);
                }
                for(int j = i; j < num_args - 3; j++)
                {
                    strcpy(argument[j], argument[j + 2]);
                }
                num_args = num_args - 2;
                break;
            }
            if(strcmp(argument[i], ">>") == 0)
            {
                int x = open(argument[i + 1], O_WRONLY | O_CREAT | O_APPEND, 0644);

                if(x < 0)
                {
                    perror("File error");
                    return 1;
                }
                else
                {
                    dup2(x, STDOUT_FILENO);
                    close(x);
                }
                for(int j = i; j < num_args - 3; j++)
                {
                    strcpy(argument[j], argument[j + 2]);
                }
                num_args = num_args - 2;
                break;
            }
            
        }
    }
    return 0;
}