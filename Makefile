NAME = push_swap

CC = GCC

FLAGS = -Wall -Wextra -Werror

SRC = cout.c faire_move.c init.c input_utils.c input_verif.c main.c petit_tri.c pos.c push.c reverse_rotate.c rotate.c stack.c swap.c trie.c utils.c

OJBS = $(SRC:.c=.o)

${NAME}:
		$(CC) $(FLAGS) $(SRC) -Iincludes -o $(NAME)

RM = rm -f

all: ${NAME}

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all