##
## EPITECH PROJECT, 2017
## Makefile
## File description:
##
##

SRC	=	get_next_line.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libgnl.a

CFLAGS	=	-Wall -Wextra

all:	$(NAME) move

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f ../$(NAME)

move:
	mv $(NAME) ../

re:	fclean all
