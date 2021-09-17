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

            }   
            else
            {
                while ((myfile = readdir(mydir)) != NULL)
                {
                    struct tm filetime;
                    char dateof[100];
                    strcpy(buf, respath);
                    strcat(buf, "/");
                    strcat(buf, myfile->d_name);
                    // sprintf(buf, "%s/%s", respath, myfile->d_name);
                    stat(buf, &reqstat);
                    // printf("%zu", reqstat.st_size);
                    char permissions[11];
                    if( reqstat.st_mode & S_ISDIR(reqstat.st_mode) )
                    {
                        permissions[0] = 'd';
                    }
                    else
                    {
                        permissions[0] = '-';
                    }
                    if( reqstat.st_mode & S_IRUSR )
                    {
                        permissions[1] = 'r';
                    }
                    else
                    {
                        permissions[1] = '-';
                    }
                    if( reqstat.st_mode & S_IWUSR )
                    {
                        permissions[2] = 'w';
                    }
                    else
                    {
                        permissions[2] = '-';
                    }
                    if( reqstat.st_mode & S_IXUSR )
                    {
                        permissions[3] = 'x';
                    }
                    else
                    {
                        permissions[3] = '-';
                    }
                    if( reqstat.st_mode & S_IRGRP )
                    {
                        permissions[4] = 'r';
                    }
                    else
                    {
                        permissions[4] = '-';
                    }
                    if( reqstat.st_mode & S_IWGRP )
                    {
                        permissions[5] = 'w';
                    }
                    else
                    {
                        permissions[5] = '-';
                    }
                    if( reqstat.st_mode & S_IXGRP )
                    {
                        permissions[6] = 'x';
                    }
                    else
                    {
                        permissions[6] = '-';
                    }
                    if( reqstat.st_mode & S_IROTH )
                    {
                        permissions[7] = 'r';
                    }
                    else
                    {
                        permissions[7] = '-';
                    }
                    if( reqstat.st_mode & S_IWOTH )
                    {
                        permissions[8] = 'w';
                    }
                    else
                    {
                        permissions[8] = '-';
                    }
                    if( reqstat.st_mode & S_IXOTH )
                    {
                        permissions[9] = 'x';
                    }
                    else
                    {
                        permissions[9] = '-';
                    }
                    permissions[10] = '\0';
                    struct passwd *passown = getpwuid(reqstat.st_uid);
                    struct group  *grfile = getgrgid(reqstat.st_gid);
                    localtime_r(&reqstat.st_mtime, &filetime);
                    strftime(dateof, sizeof(dateof), "%b %d %Y %H:%M", &filetime);

                    if(myfile->d_name[0] != '.')
                    {
                        printf("%s\t%ld\t%s\t%s\t%ld\t%s\t%s\n",permissions, reqstat.st_nlink, passown->pw_name, grfile->gr_name, reqstat.st_size, dateof, myfile->d_name);
                    }
                }
            }         
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