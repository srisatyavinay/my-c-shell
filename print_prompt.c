#include "headers.h"

void print_prompt()
{
    char username[1024]; // =malloc(MAX_LENGTH * sizeof(char));
    char systemname[1024];// = malloc(MAX_LENGTH * sizeof(char));
    char workingdir[1024];// = malloc(MAX_LENGTH * sizeof(char));
    char resultdir[1024]; //= malloc(MAX_LENGTH * sizeof(char));
    
    
    getlogin_r(username, MAX_LENGTH);
    gethostname(systemname, MAX_LENGTH);
    getcwd(workingdir, MAX_LENGTH);
    // printf("<%s@%s: %s>", username, systemname, workingdir);
    // return;

    // workingdir = "/abcd";
    // printf("%d\n", a);
    // printf("%s\n", invokedir);
    // return;

    if(strncmp(workingdir, invokedir, strlen(invokedir)) == 0)
    {
        // printf("a\n");
        // return;
        for(int i = 0; i < (strlen(workingdir) - strlen(invokedir)); i++)
        {
            resultdir[i] = workingdir[strlen(invokedir) + i];
        }
        resultdir[(strlen(workingdir) - strlen(invokedir))] = '\0';
        printf("<%s@%s:~%s>", username, systemname, resultdir);
    }
    else
    {
        printf("<%s@%s:%s>", username, systemname, workingdir);
    }
}