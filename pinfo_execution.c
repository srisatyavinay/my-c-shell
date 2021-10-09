#include "headers.h"

void pinfo_execution(char **arg, int num)
{
    int pinfopid;
    if (num == 1)
    {
        pinfopid = getpid();
    }
    else
    {
        pinfopid = atoi(arg[1]);
    }

    char processpath[1024];

    sprintf(processpath, "/proc/%d/status", pinfopid);

    FILE *process;

    process = fopen(processpath, "r");

    if (process == NULL)
    {
        perror("Incorrect pid");
    }
    else
    {

        char *fileline;
        char status[1024];
        char size[1024];

        printf("pid -- %d\n", pinfopid);

        long t = 0, x;

        while (getline(&fileline, &t, process) != -1)
        {
            if (strncmp(fileline, "VmSize", 6) == 0)
            {
                int l;
                for (l = 0; fileline[l + 8] != '\0'; l++)
                {
                    size[l] = fileline[l + 8];
                }
                size[l - 1] = '\0';
            }
            if (strncmp(fileline, "State", 5) == 0)
            {
                int l;
                for (l = 0; fileline[l + 7] != '\0'; l++)
                {
                    status[l] = fileline[l + 7];
                }
                status[l - 1] = '\0';
            }
        }

        int backprocess = 0;

        struct back *curr = present;

        if (curr != NULL)
        {
            while (curr->backpid != pinfopid && curr != NULL)
            {
                curr = curr->next;
            }
            if (curr != NULL)
            {
                backprocess = 1;
            }
        }

        if (backprocess == 0)
        {
            printf("Process Status -- %s+\n", status);
        }
        else if (backprocess == 1)
        {
            printf("Process Status -- %s\n", status);
        }
        printf("memory -- %s\n", size);
        fclose(process);

        sprintf(processpath, "/proc/%d/exe", pinfopid);

        char filelines[1024];

        int a = readlink(processpath, filelines, 1024);

        if (a < 0)
        {
            perror("Executable file not found");
        }
        else
        {
            filelines[a] = '\0';
            printf("Executable path -- %s\n", filelines);
        }
    }
}
