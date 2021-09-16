#include "headers.h"

void ls_execution(char **arg, int num)
{
    int lsa = 0;
    int lsl = 0;
    char path[32][1024];
    char respath[1024];
    int num_path = 0;
    for (int i = 1; i < num; i++)
    {
        if (strcmp(arg[i], "-a") == 0)
        {
            lsa = 1;
        }
        else if (strcmp(arg[i], "-l") == 0)
        {
            lsl = 1;
        }
        else if (strcmp(arg[i], "-la") == 0 || strcmp(arg[i], "-al") == 0)
        {
            lsa = 1;
            lsl = 1;
        }
        else
        {
            strcpy(path[num_path], arg[i]);
            num_path++;
        }
    }
    printf("%d %d \n", lsa, lsl);
    for (int n = 0; n < num_path; n++)
    {
        printf("|%s|\n", path[n]);
    }
    
    if(num_path == 0)
    {
        // printf("aaaaaaaaaaaaaaaaaaaaaa\n");
        // return;
        strcpy(path[0], ".");
    }
    printf("-----------------------------------------\n");
    if (num_path < 2)
    {
        if (lsa == 0 && lsl == 0)
        {
            printf("bbaaaaaaaaaaaaaaaaaaaa\n");
            // return;
            DIR *mydir;
            struct stat reqstat;
            struct dirent *myfile;
            strcpy(respath, path[0]);
            char buf[1024];
            if(path[0][0] == '~')
            {
                int h = 1;
                strcpy(respath, invokedir);
                strcat(respath, "/");
                int dist = strlen(respath);
                for(h = 1; h < strlen(path[0]); h++)
                {
                    respath[dist + h - 1] = path[0][h];
                }
                respath[dist + h - 1] = '\0';
                printf("|%s|\n", respath);
                // return;
            }
            mydir = opendir(respath);
            if(mydir == NULL)
            {
                strcpy(buf, respath);
                int x = stat(buf, &reqstat);
                if(x == 0)
                {
                    printf("%s\n", respath);
                }
                else
                {
                    perror("Error");
                }
            }
            else
            {
                while ((myfile = readdir(mydir)) != NULL)
                {
                    strcpy(buf, respath);
                    strcat(buf, "/");
                    strcat(buf, myfile->d_name);
                    // sprintf(buf, "%s/%s", respath, myfile->d_name);
                    stat(buf, &reqstat);
                    // printf("%zu", reqstat.st_size);
                    if(myfile->d_name[0] != '.')
                    {
                        printf("%s\n", myfile->d_name);
                    }
                }
            }
            closedir(mydir);
        }
        if (lsa == 0 && lsl == 1)
        {
            
        }
        if (lsa == 1 && lsl == 0)
        {
            printf("bbaaaaaaaaaaaaaaaaaaaa\n");
            // return;
            DIR *mydir;
            struct stat reqstat;
            struct dirent *myfile;
            strcpy(respath, path[0]);
            char buf[1024];
            if(path[0][0] == '~')
            {
                int h = 1;
                strcpy(respath, invokedir);
                strcat(respath, "/");
                int dist = strlen(respath);
                for(h = 1; h < strlen(path[0]); h++)
                {
                    respath[dist + h - 1] = path[0][h];
                }
                respath[dist + h - 1] = '\0';
                printf("|%s|\n", respath);
                // return;
            }
            mydir = opendir(respath);
            if(mydir == NULL)
            {
                strcpy(buf, respath);
                int x = stat(buf, &reqstat);
                if(x == 0)
                {
                    printf("%s\n", respath);
                }
                else
                {
                    perror("Error");
                }
            }
            else
            {
                while ((myfile = readdir(mydir)) != NULL)
                {
                    strcpy(buf, respath);
                    strcat(buf, "/");
                    strcat(buf, myfile->d_name);
                    // sprintf(buf, "%s/%s", respath, myfile->d_name);
                    stat(buf, &reqstat);
                    // printf("%zu", reqstat.st_size);
                    // if(myfile->d_name[0] != '.')
                    // {
                        printf("%s\n", myfile->d_name);
                    // }
                }
            }
            closedir(mydir);
        }
        if (lsa == 1 && lsl == 1)
        {
        }
    }
}