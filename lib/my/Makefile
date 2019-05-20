##
## EPITECH PROJECT, 2017
## Makefile
## File description:
##
##

SRC	=	my_strcmp.c			\
		my_strlen.c			\
		my_strdup.c			\
		my_getnbr.c			\
		tab_len.c			\
		my_putstr.c			\
		my_putchar.c			\
		my_strncpy.c			\
		my_strcpy.c			\
		array_size.c			\
		find_char.c			\
		split_by.c			\
		my_str_isalpha.c		\
		my_put_tab.c			\
		my_strcat.c			\
		power.c				\
		my_revstr.c			\
		my_isnum.c			\
		my_str_to_word_array.c		\
		clean_str.c			\
		dir_content.c			\
		my_realloc.c			\
		my_int_to_str.c			\
		free_2d_arr.c			\
		find_str.c			\
		tab_realloc.c			\
		env_variables.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

CFLAGS	=	-Wall -Wextra

all:	$(NAME) move

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f ../$(NAME)

move:
	mv $(NAME) ../
