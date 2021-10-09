#include "headers.h"

void pwd_execution()
{
    char workingdir[1024];

    getcwd(workingdir, MAX_LENGTH);

    printf("%s\n", workingdir);
}
