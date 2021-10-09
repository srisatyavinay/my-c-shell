#include "headers.h"

void echo_execution(char **arg, int num)
{
    for (int i = 1; i < num; i++)
    {
        printf("%s ", arg[i]);
    }
    printf("\n");
}
