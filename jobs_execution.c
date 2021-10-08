#include "headers.h"

void jobs_execution(char **arg, int num)
{
    struct back *point = present;

    while(point != NULL)
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
            // return;
        }
        else
        {
            char *fileline;
            char status[20];
            char y;

            // printf("pid -- %d\n", pinfopid);

            long t = 0, x;

            while (getline(&fileline, &t, process) != -1)
            {
                if (strncmp(fileline, "State", 5) == 0)
                {
                    y = fileline[7];
                    if(y == 'S' || y == 'D' || y == 'R')
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
            printf("[%d] %s %s [%d]\n", bjob, status, point->backname, pinfopid);
        }
        point = point->next;
    }
}