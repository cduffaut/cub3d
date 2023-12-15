SRC = \
	input_in_list.c utils/print_var.c gnl/get_next_line_utils.c \
	gnl/get_next_line.c
OBJ = $(SRC:.cpp=.o)

CC = gcc
FLAGS = -Wall -Wextra -Werror

NAME = cub3d

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean $(NAME)

.PHONY: all re clean fclean
