##
## EPITECH PROJECT, 2017
## Makefile
## File description:
##
##

UI		=	srcs/ui/

DUNGEON		=	srcs/dungeon/

SRCS		=	srcs/

HUD		=	srcs/hud/

EVENT		=	srcs/event/

PARTICLES	=	srcs/particles/

TEXT		=	srcs/text_box/

SRC		=	$(SRCS)main.c				\
			$(SRCS)initialisation.c			\
			$(SRCS)entity.c				\
			$(SRCS)disp_room.c			\
			$(SRCS)texture_bank.c			\
			$(SRCS)player.c				\
			$(SRCS)utility.c			\
			$(SRCS)character.c			\
			$(SRCS)mob.c				\
			$(SRCS)collision.c			\
			$(SRCS)my_rpg.c				\
			$(SRCS)draw_destroy_pause.c		\
			$(SRCS)init_pause.c			\
			$(SRCS)pause.c				\
			$(SRCS)hitbox.c				\
			$(SRCS)mob_hit.c			\
			$(SRCS)destroy_mob.c			\
			$(SRCS)mob_position.c			\
			$(SRCS)attack.c				\
			$(SRCS)character_collision.c		\
			$(SRCS)music.c				\
			$(SRCS)ult_attack.c			\
			$(SRCS)move_player.c			\
			$(SRCS)utils_sprite.c			\
			$(SRCS)safe_zone.c			\
			$(SRCS)boss.c				\
			$(HUD)inventory.c			\
			$(HUD)draw_hud.c			\
			$(HUD)map.c				\
			$(HUD)shop.c				\
			$(HUD)game_over.c			\
			$(HUD)end_menu.c			\
			$(TEXT)text_box.c			\
			$(PARTICLES)particles_gen.c		\
			$(EVENT)create_event.c			\
			$(EVENT)display_event.c			\
			$(DUNGEON)load_dungeon.c		\
			$(DUNGEON)room_functions.c		\
			$(DUNGEON)run_dungeon.c			\
			$(DUNGEON)switch_room.c			\
			$(DUNGEON)generate_room.c		\
			$(DUNGEON)trigger.c			\
			$(UI)change_volume.c			\
			$(UI)effect.c				\
			$(UI)init_window.c			\
			$(UI)option_menu.c			\
			$(UI)init_linked_cloud.c		\
			$(UI)main_menu.c			\
			$(UI)set_fullscreen.c			\
			$(UI)draw_destroy_menu.c		\
			$(UI)init_main_menu.c			\
			$(UI)menu_button.c			\
			$(UI)counter.c

OBJ		=	$(SRC:.c=.o)

NAME		=	my_rpg

CFLAGS		=	-Wall -Wextra

LIB		=	-Llib/ -lmy -lm -lgnl -llist -lcsfml-window -lcsfml-graphics -lcsfml-audio -lcsfml-system

CPPFLAGS	=	-I include/


all:	$(NAME)

$(NAME):	$(OBJ)
	make -C lib/my
	make -C lib/gnl
	make -C lib/list
	$(CC) -o $(NAME) $(CfLAGS) $(OBJ) $(LIB) $(CPPFLAGS)

clean:
	make clean -C tests/
	make clean -C lib/my/
	make clean -C lib/gnl/
	make clean -C lib/list/
	rm -f $(OBJ)

tests_run:
	make -C tests/

fclean:	clean
	rm -f $(NAME)
	make fclean -C tests/
	make fclean -C lib/my/
	make fclean -C lib/gnl/
	make fclean -C lib/list/

re:	fclean all

.PHONY: all clean fclean re
