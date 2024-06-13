##
## EPITECH PROJECT, 2023
## makefile
## File description:
## Makefile
##

SRC	=	src/main.c 	\
		src/which_where.c \
		src/jobctrl/change_status.c\
		src/jobctrl/fg.c\
		src/jobctrl/bg.c \
		src/guava.c \
		src/shell_base/change_directory.c \
		src/shell_base/check_path.c \
		src/shell_base/double_redirection_input.c \
		src/shell_base/env.c \
		src/shell_base/exec_pipe.c \
		src/shell_base/inf_boucle.c \
		src/shell_base/redirection_input.c \
		src/shell_base/redirection_output.c \
		src/shell_base/single_line.c \
		src/shell_base/unsetenv.c \
		src/shell_base/is_built_in.c \
		src/shell_base/remove_space_from_str.c \
		src/shell_base/search_sep.c \
		src/shell_base/manage_redirections.c \
		src/shell_base/logical_and_or.c \
		src/history/write_history.c \
		src/history/print_history.c \
		src/history/history_index.c \
		src/history/exclamation_mark.c \
		src/shell_base/my_strdup_start_end.c \
		src/shell_base/find_pwd.c \
		src/goyaverc.c \
		src/shell_base/execute_command.c \
		src/local_vars/set_local_var.c	\
		src/local_vars/get_var.c	\
		src/local_vars/correct_set.c	\
		src/local_vars/add_local_var.c	\
		src/local_vars/update_local_var.c	\
		src/local_vars/free_dict.c	\
		src/local_vars/unset_local_var.c	\
		src/local_vars/is_assign.c	\
		src/local_vars/export_env_var.c	\
		src/local_vars/var_used.c	\
		src/local_vars/all_vars_exist.c	\
		src/shell_base/verif_command.c	\
		src/alias_command/alias_command.c	\
		src/alias_command/print_alias.c	\
		src/alias_command/unalias_command.c	\
		src/alias_command/is_alias.c	\
		src/alias_command/command_walias.c	\
		src/termios/init_termios.c	\
		src/termios/print_char.c	\
		src/termios/arrow.c	\
		src/termios/backspace.c	\
		src/termios/get_all_prog.c \
		src/termios/update.c \
		src/termios/line_editing_ctrl.c \
		src/jobctrl/execadv.c	\
		src/jobctrl/init_jobs.c	\
		src/jobctrl/ping_jobs.c	\
		src/backtick/backtick.c	\
		src/jobctrl/rev_list.c	\
		src/jobctrl/jobs.c	\
		src/jobctrl/jobs_visual.c	\

OBJ	=	${SRC:.c=.o}

NAME	=	42sh

CFLAGS	:=	-Wall -Wextra -g3

CPPFLAGS	:=	-Iinclude

LDFLAGS	:= -Llib -lmy -lprintf

all: ${NAME}

fclean: clean
	make fclean -C lib
	make fclean -C lib/my_printf
	rm -f ${NAME}

clean:
	make clean -C lib
	make clean -C lib/my_printf
	rm -f ${OBJ}
	rm -f vgcore.*
	rm -f *.log
	rm -f .*~

re: fclean
	${MAKE} all

${NAME}: $(OBJ)
	make -C lib
	make -C lib/my_printf
	cp lib/my.h include/my.h
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS) $(CPPFLAGS) $(CFLAGS)

debug: ${OBJ}
	make -C lib
	make -C lib/my_printf
	cp lib/my.h include/my.h
	$(CC) -o $(NAME) $(SRC) $(LDFLAGS) $(CPPFLAGS) $(CFLAGS) -g3


.PHONY: all re fclean clean
