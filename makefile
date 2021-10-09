all:
	gcc main.c print_prompt.c tokenise.c echo_execution.c pwd_execution.c cd_execution.c ls_execution.c pinfo_execution.c background_execution.c exit_execution.c check_for_bg_process.c redirection.c pipe_execution.c jobs_execution.c sig_execution.c fg_execution.c bg_execution.c signal_handling.c -o myshell
