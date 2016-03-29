##
## Makefile for gfx_tekadventure in /home/puilla_e/Semestre2/infographie
## 
## Made by edouard puillandre
## Login   <puilla_e@epitech.net>
## 
## Started on  Tue Mar 29 16:49:58 2016 edouard puillandre
## Last update Tue Mar 29 16:54:08 2016 edouard puillandre
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
		src/my_init_fct.c

RM	=	rm -f

NAME	=	diabete_man

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
