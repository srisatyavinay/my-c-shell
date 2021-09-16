#include "headers.h"


int main()
{

    // char* invokedir = malloc(MAX_LENGTH * sizeof(char));
    // char* workingdir = malloc(MAX_LENGTH * sizeof(char));
    getcwd(invokedir, MAX_LENGTH);
    // printf("%s\n", invokedir);
    // return 0;
    // strcpy(workingdir, invokedir);
    // strcpy(invokedir, "/home/abcd");
    while(1)
    {
        // a = 15;
        print_prompt();
        // printf("%d\n", a);
        // printf("<%s@%s: %s>", username, systemname, workingdir);
        // return 0;
        // read_input();
        char* lineptr = NULL;
        size_t readline;
        size_t len;
        int i = 0;

        readline = getdelim(&lineptr, &len, 10, stdin);
        lineptr[readline - 1] = '\0';
        // printf("%s\n", lineptr);
        char* commtoken;

        commtoken = strtok(lineptr, ";");
        comm[i] = commtoken;
        // printf( "|%s|\n", comm[i] );
        while( commtoken != NULL ) 
        {
            printf( "|%s|\n", commtoken );
            i++;
            commtoken = strtok(NULL, ";");
            comm[i] = commtoken;
        }
        printf("%d\n", i);
        for( int j = 0; j < i; j++)
        {
            tokenise(comm[j]);
        }
            
    }
}