##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

SRC     =		src/my_putstr.c					\
				src/my_strcat.c					\
				src/my_strcmp.c					\
				src/my_str_to_word_array.c		\
				src/env.c						\
				src/my_strlen.c					\
				src/check_env.c	\
				src/main.c

OBJ     =       $(SRC:.c=.o)

RM      =       rm -f

NAME    =       42sh

all:    $(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) -g3 $(OBJ)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re
