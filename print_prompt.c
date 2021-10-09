#include "headers.h"

void print_prompt()
{
    char username[1024];
    char systemname[1024];
    char workingdir[1024];
    char resultdir[1024];

    getlogin_r(username, MAX_LENGTH);
    gethostname(systemname, MAX_LENGTH);
    getcwd(workingdir, MAX_LENGTH);

    if (strncmp(workingdir, invokedir, strlen(invokedir)) == 0)
    {

        for (int i = 0; i < (strlen(workingdir) - strlen(invokedir)); i++)
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
