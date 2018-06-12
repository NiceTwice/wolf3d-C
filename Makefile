##
## Makefile for Makefile in /home/fisun_s/rendu/MUL_2014_wolf3d
## 
## Made by Fisun Sergii
## Login   <fisun_s@epitech.net>
## 
## Started on  Sun Dec 21 22:50:27 2014 Fisun Sergii
## Last update Sun Dec 21 22:50:40 2014 Fisun Sergii
##

NAME=		wolf3d

CC=		gcc

CFLAGS=		-I./include/ -Wall -Wextra

SRC=		my_drowline.c \
		my_put_pixel_image.c \
		wolf.c \
		my_get_nextline.c \
		readfile.c \
		my_getnbr.c \
		calcs.c \
		get_map.c \
		get_maps.c \
		my_strdup.c \
		mini_map.c \
		init_wolf.c \
		gere_buttons.c \
		draws.c \
		opt_calcs.c \
		img_tools.c \
		moves.c \
		hooks.c

OBJ=		$(SRC:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJ)
		$(CC) -Ofast -o $(NAME) $(OBJ) -L./minilibx/ -lmlx_x86_64 -L/usr/lib64/X11 -lXext -lX11 -lm

clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)

re:		fclean all
