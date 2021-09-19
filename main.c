#include "headers.h"


int main()
{
    present = NULL;
    getcwd(invokedir, MAX_LENGTH);
    while(1)
    {
        print_prompt();

        char* lineptr = NULL;
        size_t readline;
        size_t len;
        int i = 0;

        readline = getdelim(&lineptr, &len, 10, stdin);

        lineptr[readline - 1] = '\0';

        char* commtoken;
        commtoken = strtok(lineptr, ";");
        comm[i] = commtoken;

        while( commtoken != NULL ) 
        {
            i++;
            commtoken = strtok(NULL, ";");
            comm[i] = commtoken;
        }

        for( int j = 0; j < i; j++)
        {
            tokenise(comm[j]);
        }
            
    }
}