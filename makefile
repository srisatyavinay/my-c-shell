all:
	gcc main.c print_prompt.c tokenise.c echo_execution.c pwd_execution.c cd_execution.c ls_execution.c pinfo_execution.c background_execution.c exit_execution.c check_for_bg_process.c -o myshell