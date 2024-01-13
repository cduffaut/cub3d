# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pudry <pudry@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/31 08:09:16 by pudry             #+#    #+#              #
#    Updated: 2024/01/06 11:11:09 by pudry            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
CC = gcc
FLAGS = -Wall -Wextra -Werror #-fsanitize=address
LIBFT = libft/libft.a

MLX = mlx/libmlx.a
INCLUDES = -I/opt/X11/include -Imlx
MLX_FLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit


BLUE = \\033[1;34m
WHITE = \\033[0;37m
YELLOW = \\033[0;33m
RED = \\033[1;31m
GREEN = \\033[1;32m
BRWN = \\033[0; 33m
GREY = \\033[1;30m

#utils/ft_check_map.c utils/ft_stock_map.c
GNL = gnl/get_next_line.c gnl/get_next_line_utils.c

INPUT = input/convert_colours_to_int.c input/convert_colours_to_int_2.c \
	input/create_trgb.c input/get_from_trgb.c input/input_in_list_4.c input/input_in_list_5.c \
	input/check_map.c input/input_in_list.c input/input_in_list_3.c input/input_in_list_2.c \
	input/free_all_init.c input/input_in_list_6.c input/input_in_list_7.c

RAY_CAST = raycasting/put_wall.c raycasting/raycasting.c raycasting/ft_background.c

MAIN = main.c put_map.c key_hook.c door.c free_and_exit_final.c

ERR = erreurs/ft_erreur.c

SRC = $(addprefix src/,$(INPUT) $(MAIN) $(ERR) $(RAY_CAST))

UTL = utils/print_var.c utils/ft_utils_mlx.c utils/ft_calcul.c utils/ft_utils.c utils/ft_colision.c utils/texture_in_data.c

# $(GNL:.c=.o)
OBJ = $(GNL:.c=.o) $(SRC:.c=.o) $(UTL:.c=.o)

all : lib $(NAME) header
	leaks --atExit -- ./$(NAME) map/mapwrong.cub

push : clean
	git add *
	git commit -m "Auto push"
	git push

.c.o:
	$(CC) $(FLAGS) -c -o $@ $< $(INCLUDES)

leaks: $(NAME)
	leaks --atExit -- ./$(NAME) map/mapwrong.cub

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) $(MLX_FLAGS) $(LIBFT) -o $(NAME)

lib :
	@make -C libft/
	@make -C mlx/

clean :
	@rm -f $(OBJ)
	@make clean -C libft/
	@make clean -C mlx/

fclean : clean
	@rm -f $(NAME)
	@make fclean -C libft/

re : fclean all

gen_obj :
	@$(CC) $(CFLAGS) -c $(SRC) $(GNL) $(SRC)

header :
	@echo "${GREEN}"
	@echo "                                                          ████                                                "
	@echo "                                                       ███    ███                                             "
	@echo "                                                    ██▓           ██                                          "
	@echo "                                                ▒██                  ███                                      "
	@echo "                                             ███                        ███                                   "
	@echo "                                          ███                              ███                                "
	@echo "                                        ██                                    ██                              "
	@echo "                                        █ ███                              ███ █                              "
	@echo "                                        █    ███                        ███    █                              "
	@echo "                             ▒█         █       ███                  ███       █         ██                   "
	@echo "                          ███   ███     █           ██            ██           █     ░██   ███                "
	@echo "                       ███         ███  █              ██      ██              █   ██         ███             "
	@echo "                    ███               ███                 ████                 ███                ██          "
	@echo "                 ██                      ███                █               ███                      ██░      "
	@echo "             ░██                            ███             █            ███                            ███   "
	@echo "          ███                                   ██          █         ██                                   ███"
	@echo "          ████                                 ████         █        ████                                 ████"
	@echo "          █   ░██                          ███    █         █        █    ███                          ███   █"
	@echo "          █       ██                    ███       █                  ██      ███                    ██▒      █"
	@echo "          █          ███             ███          █      ██████      ██         ███              ██          █"
	@echo "          █             ███       ███             █   ██        ███  █▒             ██       ███             █"
	@echo "          █                ███ ██░                ███              ███░                ██ ███                █"
	@echo "          █                   █                ███                    ███                █                   █"
	@echo "          █                   █             ███                          ███             █                   █"
	@echo "          █                   █          ███                                ███          █                   █"
	@echo "          █                   █         ███                                  ▓██         █                   █"
	@echo "          █                   █         █  ███                            ███  █         █                   █"
	@echo "          █                   █         █     ███                      ███     █         █                   █"
	@echo "          ███                 █         █         ██                ███        █         █                 ███"
	@echo "             ███              █         █            ██          ██            █         █              ███   "
	@echo "                ███           █         █               ██    ██               █         █           ███      "
	@echo "                   ███        █       ░██                  ██                  ███       █        ███         "
	@echo "               ███     ███    █    ███  █                   █                  █  ███    █     ██     ███     "
	@echo "            ███           ███ █ ███     █                   █                  █     ███ █ ███           ███  "
	@echo "          ██                 ██         █                   █                  █         ██                 ██"
	@echo "          █  ██                         █                   █                  █                         ██  █"
	@echo "          █     ██                      █                   █                  █                      ██     █"
	@echo "          █        ███                 ██▒                  █                  ██                 ███        █"
	@echo "          █           ███           ███   ███               █               ██   ███           ███           █"
	@echo "          █              ███     ██          ███            █           ███          ██     ███              █"
	@echo "          █                 ░███                ███         █        ███                ████                 █"
	@echo "          █                   █               ███  ███      █     ███  ███               █                   █"
	@echo "          █                   █            ███         ██   █  ██         ░██            █                   █"
	@echo "          █                   █         ██                ████                ██         █                   █"
	@echo "          ▒                   █         ████                                ████         █                   █"
	@echo "          █                   █         █   ▒██                          ███   █         █                   █"
	@echo "          █                   █         █       ██                    ██▓      █         █                   █"
	@echo "           ███                █         █          ███            ███          █         █                ███ "
	@echo "              ███             █         █             ███      ███             █         █             ███    "
	@echo "                  ██          █         █                ██████                █         █          ██        "
	@echo "                     ███      █      ████                   █                  ████      █      ▒██           "
	@echo "                        ███   █   ███   █                   █                  █   ███   █   ░██              "
	@echo "                           ██████       █                   █                  █       ██████                 "
	@echo "                                        █                   █                  █                              "
	@echo "                                        █                   █                  █                              "
	@echo "                                        █                   █                  █                              "
	@echo "                                        ███                 █                ▓██                              "
	@echo "                                           ███              █             ███                                 "
	@echo "                                              ███           █          ███                                    "
	@echo "                                                  ██        █       ███                                       "
	@echo "                                                     ██▒    █    ██                                           "
	@echo "                                                        ██▒ █ ██                                              "
	@echo '                       ____          _ _                                       ____             _ '
	@echo '                      / ___|___  ___(_) | ___                                 |  _ \ __ _ _   _| |'
	@echo '                     | |   / _ \/ __| | |/ _ \                                | |_) / _` | | | | |'
	@echo '                     | |__|  __/ (__| | |  __/                                |  __/ (_| | |_| | |'
	@echo '                      \____\___|\___|_|_|\___|                                |_|   \__,_|\__,_|_|'
	@echo ""
	@echo ""
	@echo "███████╗ ██████╗ ██████╗  ██████╗███████╗    ███████╗████████╗    ██╗  ██╗ ██████╗ ███╗   ██╗███╗   ██╗███████╗██╗   ██╗██████╗ "
	@echo "██╔════╝██╔═══██╗██╔══██╗██╔════╝██╔════╝    ██╔════╝╚══██╔══╝    ██║  ██║██╔═══██╗████╗  ██║████╗  ██║██╔════╝██║   ██║██╔══██╗"
	@echo "█████╗  ██║   ██║██████╔╝██║     █████╗      █████╗     ██║       ███████║██║   ██║██╔██╗ ██║██╔██╗ ██║█████╗  ██║   ██║██████╔╝"
	@echo "██╔══╝  ██║   ██║██╔══██╗██║     ██╔══╝      ██╔══╝     ██║       ██╔══██║██║   ██║██║╚██╗██║██║╚██╗██║██╔══╝  ██║   ██║██╔══██╗"
	@echo "██║     ╚██████╔╝██║  ██║╚██████╗███████╗    ███████╗   ██║       ██║  ██║╚██████╔╝██║ ╚████║██║ ╚████║███████╗╚██████╔╝██║  ██║"
	@echo "╚═╝      ╚═════╝ ╚═╝  ╚═╝ ╚═════╝╚══════╝    ╚══════╝   ╚═╝       ╚═╝  ╚═╝ ╚═════╝ ╚═╝  ╚═══╝╚═╝  ╚═══╝╚══════╝ ╚═════╝ ╚═╝  ╚═╝"
	@echo "${WHITE}"






.PHONY : fclean re all header clean cnt check leak map
