#include "headers.h"

void jobs_execution(char **arg, int num)
{
    int jr = 0;
    int js = 0;
    for (int i = 1; i < num; i++)
    {
        if (strcmp(arg[i], "-r") == 0)
        {
            jr = 1;
        }
        else if (strcmp(arg[i], "-s") == 0)
        {
            js = 1;
        }
        else if (strcmp(arg[i], "-rs") == 0 || strcmp(arg[i], "-sr") == 0)
        {
            jr = 1;
            js = 1;
        }
    }

    struct back *point = present;

    while (point != NULL)
    {
        int pinfopid, bjob;
        char processpath[1024];
        pinfopid = point->backpid;
        bjob = point->jobnum;
        strcpy(processpath, point->backname);
        sprintf(processpath, "/proc/%d/status", pinfopid);
        FILE *process;

        process = fopen(processpath, "r");

        if (process == NULL)
        {
            perror("Error");
        }
        else
        {
            char *fileline;
            char status[20];
            char y;

            long t = 0, x;

            while (getline(&fileline, &t, process) != -1)
            {
                if (strncmp(fileline, "State", 5) == 0)
                {
                    y = fileline[7];
                    if (y == 'D' || y == 'S' || y == 'R')
                    {
                        strcpy(status, "Running");
                    }
                    else
                    {
                        strcpy(status, "Stopped");
                    }
                    break;
                }
            }
            fclose(process);
            if ((jr == 1) && (js != 1))
            {
                if (strcmp(status, "Running") == 0)
                {
                    printf("[%d] %s %s [%d]\n", bjob, status, point->backname, pinfopid);
                }
            }
            else if ((jr != 1) && (js == 1))
            {
                if (strcmp(status, "Stopped") == 0)
                {
                    printf("[%d] %s %s [%d]\n", bjob, status, point->backname, pinfopid);
                }
            }
            else
            {
                printf("[%d] %s %s [%d]\n", bjob, status, point->backname, pinfopid);
            }
        }
        point = point->next;
    }
}
