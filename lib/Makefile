##
## EPITECH PROJECT, 2023
## make file
## File description:
## ..
##
SRC	:=	my_getnbr.c	\
		my_strlen.c	\
		my_putchar.c	\
		my_strdup.c	\
		my_strcpy.c	\
		my_array_to_str.c \
		my_strcmp.c	\
		how_many_digits.c 	\
		int_to_string.c	\
		my_str_to_word_array.c	\
		my_str_to_word_array_path.c	\
		my_str_to_word_array_keep.c	\
		my_show_word_array.c	\
		my_array_sup_dup.c	\
		my_array_dup.c	\
		input.c	\
		my_putstr.c	\
		my_arraylen.c	\
		my_strncpy.c	\
		my_strncmp.c	\
		my_strcat.c	\
		my_revstr.c	\
		del_space.c \
		free_array.c \

OBJ	=	$(SRC:.c=.o)

NAME    =       libmy.a

all:	$(NAME)

libmy.a: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	cp my.h ../include/my.h
clean:
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)
re: fclean all


PHONY: all re fclean clean libmy.a
