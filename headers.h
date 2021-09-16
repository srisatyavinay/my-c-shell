#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define MAX_LENGTH 1024

#ifndef __HEADER_H
#define __HEADER_H

void print_prompt();
void tokenise(char* command);
void echo_execution(char** arg, int num);
void cd_execution(char** arg, int num);
void pwd_execution();



char invokedir[1024];
// extern char* workingdir;
char* comm[64];
char* argument[64];
int a;
// extern char* username;
// extern char* systemname;
// char* workingdir;

#endif