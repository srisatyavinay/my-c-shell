#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <dirent.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/dir.h>
#include <pwd.h> 
#include <grp.h> 
#include <time.h> 
#include <locale.h> 

#define MAX_LENGTH 1024

#ifndef __HEADER_H
#define __HEADER_H

void print_prompt();
void tokenise(char* command);
void echo_execution(char** arg, int num);
void cd_execution(char** arg, int num);
void pwd_execution();
void ls_execution(char** arg, int num);



char invokedir[1024];
char prevdir[1024];
// extern char* workingdir;
char* comm[64];
char* argument[64];
int a;
// extern char* username;
// extern char* systemname;
// char* workingdir;

#endif