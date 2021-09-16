#include "headers.h"

void pwd_execution()
{
    char workingdir[1024];
    // char resultdir[1024];

    getcwd(workingdir, MAX_LENGTH);
    // printf("%s\n", workingdir);
    // printf("%s\n", invokedir);
    // return;

    // if(strncmp(workingdir, invokedir, strlen(invokedir)) == 0)
    // {
        // printf("abcd\n");
        // return;
        // for(int i = 0; i < (strlen(workingdir) - strlen(invokedir)); i++)
        // {
            // resultdir[i] = workingdir[strlen(invokedir) + i];
        // }
        // resultdir[(strlen(workingdir) - strlen(invokedir))] = '\0';
        // printf("~%s\n", resultdir);
    // }
    // else
    // {
        printf("%s\n", workingdir);
    // }
}