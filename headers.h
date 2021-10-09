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
#include <signal.h>
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
void jobs_execution(char **arg, int num);
void sig_execution(char **arg, int num);
void fg_execution(char **arg, int num);
void bg_execution(char **arg, int num);
void ctrl_c_execution(int signum);
void ctrl_z_execution(int signum);

int input, output;
char invokedir[1024];
char prevdir[1024];
char *comm[64];
char *argument[64];
char *pargument[64];
int a;
int backnum;
struct fore *fproc;
int fprocpid;
int shellpid;

struct back
{
    int backpid;
    char backname[1024];
    int jobnum;
    struct back *next;
};

struct fore
{
    int fpid;
    char fname[1024];
};

struct back *present;

#endif
