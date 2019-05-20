##
## EPITECH PROJECT, 2017
## Makefile
## File description:
##
##

SRC	=	srcs/my_list_add.c	\
		srcs/my_list_delete.c	\
		srcs/my_list_size.c

OBJ	=	$(SRC:.c=.o)

NAME	=	liblist.a

CFLAGS	=	-Wall -Wextra

CPPFLAGS	=	-I include/

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
