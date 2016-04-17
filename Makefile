##
## Makefile for gfx_tekadventure in /home/puilla_e/Semestre2/infographie
##
## Made by edouard puillandre
## Login   <puilla_e@epitech.net>
##
## Started on  Tue Mar 29 16:49:58 2016 edouard puillandre
## Last update Sun Apr 17 23:20:59 2016 edouard puillandre
##

DEBUG	=	yes

CC	=	gcc

CFLAGS	=	-Iinclude	\
		-Wall		\
		-Wextra		\
		-Werror		\
		-std=c99

ifeq ($(DEBUG), yes)
CFLAGS	+=	-g		\
		-D DEBUG
endif

LDFLAGS	=	-L/usr/local/lib		\
		-L/home/${USER}/.froot/lib	\
		-I/home/${USER}/.froot/include	\
		-llapin				\
		-lsfml-audio			\
		-lsfml-graphics			\
		-lsfml-window			\
		-lsfml-system			\
		-lstdc++			\
		-ldl				\
		-lm

SRC	=	src/main.c		\
		src/free_all.c		\
		src/my_init_fct.c	\
		src/bitmap.c		\
		src/copy_in_pix.c	\
		src/change_pos.c	\
		src/decal.c		\
		src/load.c		\
		src/change_clipable.c	\
		src/tekpixel.c		\
		src/scale.c		\
		src/check_click.c	\
		src/coef.c		\
		src/init_board.c	\
		src/fct_button.c	\
		src/load_node.c		\
		src/put_board.c		\
		src/go.c		\
		src/same_way.c		\
		src/diff_way.c		\
		src/next_node.c		\
		src/tektext.c		\
		src/string.c		\
		src/move_poteau.c	\
		src/load_node_1.c	\
		src/my_getnbr.c		\
		src/set_ram.c

RM	=	rm -f

NAME	=	aventure

OBJ	=	$(SRC:.c=.o)

$(NAME): $(OBJ)
ifeq ($(DEBUG), yes)
	@tput setaf 2; tput bold
	@echo
	@echo Debug mode
	@echo
	@tput sgr0
endif
	$(CC) $(OBJ) -o $(NAME) $(LDFLAGS)

all: $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
