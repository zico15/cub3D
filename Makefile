# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/12 18:43:51 by edos-san          #+#    #+#              #
#    Updated: 2023/03/13 17:37:19 by edos-san         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= 	gcc -Wall -Wextra -Werror  -g # -fsanitize=address
RM			= 	/bin/rm -f
NAME		= 	cub3D
INCLUDES	= 	-Iheaders/
MILIB		=	-I /usr/X11/include -g -L /usr/X11/lib -l minilibx-linux -framework OpenGL -framework AppKit

SRCS		=   main.c $(shell find src/ -name '*.c')
OBJS		= 	$(SRCS:.c=.o)


MLX_LIB_DIR = mlx_linux/
#directories with .h
LIBFT_INCLUDE = -ILIBFT/include
MLX_INCLUDE = -Imlx_linux

COLOUR_GREEN=\033[7;1;32m
COLOUR_END=\033[0m
COLOUR_YELLOW=\033[7;1;33m

MLX_FLAGS = -L$(MLX_LIB_DIR) -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz

# ^ primeira dependencia
# @ nome da regra
all: $(NAME)

$(NAME): $(OBJS) 
	@$(MAKE) -s -C mlx_linux
	@$(CC) $(^) $(MLX_FLAGS) -o $(@)

%.o: %.c $(MLX_LIB)
	@$(CC) $(INCLUDES) $(MLX_INCLUDE) -c $(^) -o $(@)

bonus: all

clean:
	@$(RM) $(OBJS)
	@echo "\033[0;31mREMOVED OBJECT FILES\033[0m"

fclean: clean
	@$(RM) $(NAME)
	@echo "\033[0;31mREMOVED cub3D EXECUTABLE\033[0m"

re: fclean all

norm :
	@norminette -R CheckForbiddenSourceHeader $(SRCS) headers/

m: fclean

v:
	@make re && make clean && clear && valgrind ./cub3D map/map1.cub

vv:
	@make re && make clean && clear && valgrind  -v ./cub3D map/*
r:
	@make re && make clean && clear && ./cub3D map/map1.cub

rr:
	@make re && make clean && clear && ./cub3D map/*


.PHONY: all re clean fclean m
