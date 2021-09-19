# OSN Assignment - 2

This is a working C shell that would mimic a bash shell which supports colon seperated commands.

## To execute

To start the shell use the following commands

```bash
$ make
$ ./myshell
```

## To stop

To stop the shell use the following command

```bash
$ exit
```

## Files used

### headers.h

This file contains all the libraries used in executing the shell. It also conatains the declarations of all functions, global variables etc.

### main.c

```c
int main()
```

This is the main file which contains the main function. It runs an infinite loop and on each iteration it calls other functions. It seperates the semicolon seperated commands and calls other functions to execute them

### print_prompt.c

```c
void print_prompt()
```

This function prints the user name, host name and the directory in which the process is running during execution in a formatted order.

### check_for_bg_process.c

```c
void check_for_bg_process()
```

This function checks for any completed backgroud process and prints a statement on the terminal.

### tokenise.c

```c
void tokenise(char *command)
```
This function removes the extra spaces in the obtained single command without ; from main.

```c
void identify_command(char **arg, int num)
```
This function identifies which command to execute and also determines if it is one of the builtin commands or one from the functions written here. It also does the `repeat` command function.

### echo_execution.c

```c
void echo_execution(char **arg, int num)
```
This function does the `echo` command execution

### pwd_execution.c

```c
void pwd_execution()
```
This function does the `pwd` command execution.

### cd_execution.c

```c
void cd_execution(char **arg, int num)
```
This function does the `cd` command execution. It also supports the usage of special symbols like  `~, /, -, .., .`

### ls_execution.c

```c
void ls_execution(char **arg, int num)
```
This function does the `ls` execution. It also supports the usage of `-l` and `-a` flags individually or together. It also supports listing the files or file details of multiple directories or files together.

### background_execution

```c
void background_execution(char **arg, int num)
```
This function implements the background and foreground process. It stores the ongoing background process in a linked list. Builtin commands are implemented using `execvp()`.

### pinfo_execution.c

```c
void pinfo_execution(char **arg, int num)
```
This function does the `pinfo` command execution.

### exit_execution.c

```c
void exit_execution()
```
When `exit` command is used the shell stops. This is implemented by this function.

## General Assumptions

- At max there can be 64 semi-colon seperated commands in a line.
- Each individual command can have 64 arguments and each one of them can be at max 1024 characters long.
- All the paths given must be less than 1024 characters.
- The hostname, system name, current working directory path is less than 1024 characters.
