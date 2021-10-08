#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <dirent.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/dir.h>
#include <sys/wait.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <locale.h>
#include <fcntl.h>

#define MAX_LENGTH 1024

#ifndef __HEADER_H
#define __HEADER_H

void print_prompt();
void tokenise(char *command);
void echo_execution(char **arg, int num);
void cd_execution(char **arg, int num);
void pwd_execution();
void ls_execution(char **arg, int num);
void identify_command(char **arg, int num);
void background_execution(char **arg, int num);
void pinfo_execution(char **arg, int num);
void exit_execution();
void check_for_bg_process();
int redirection(int redirect, int num_args);
void pipe_execution(char *pipecomm);

int input, output;
char invokedir[1024];
char prevdir[1024];
char *comm[64];
char *argument[64];
char *pargument[64];
int a;
struct back
{
    int backpid;
    char backname[1024];
    struct back *next;
};

struct back *present;

#endif