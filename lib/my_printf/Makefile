##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## emacs
##

NAME = libprintf.a

SRC =	lib/my_compute_power_rec.c\
	lib/my_count_digits.c\
	lib/my_getnbr.c\
	lib/my_putchar.c\
	lib/my_putfloat.c\
	lib/my_putnbr.c\
	lib/my_putnbr_base.c\
	lib/my_putstr.c\
	lib/my_strlen.c\
	lib/my_printf.c\
	lib/switch_case.c\
	lib/my_put_unsignedint.c\
	lib/my_put_error.c\
	lib/my_put_hashtag.c\
	lib/my_putexp.c\
	lib/is_flag.c\
	lib/my_putfloat_g.c\
	lib/switch_case2.c\
	lib/my_put_space.c\
	lib/my_putfloat_count.c\
	lib/my_putfloat_g_count.c\
	lib/my_putexp_count.c\
	lib/my_putnbr_base_flag.c\
	lib/my_putnbr_base_count.c

OBJ = $(SRC:.c=.o)

libmy.a: $(SRC)
	rm -f $(NAME)
	gcc -c $(SRC)
	ar rc $(NAME) *.o
	cp $(NAME) ../
	rm -f *.o

unit_tests: fclean libmy.a
	gcc -o unit_tests lib/my_printf.c ./tests/test_my_printf.c\
    libmy.a --coverage -lcriterion

tests_run: unit_tests
	./unit_tests

all: libmy.a

clean :
	rm -f *~
	rm -f #*#
	rm -f $(OBJ)
	rm -f *.gc*

fclean : clean
	rm -f $(NAME)
	rm -f ../$(NAME)

re : fclean all

.PHONY: all clean fclean re lib
