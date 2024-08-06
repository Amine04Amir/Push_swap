NAME = push_swap

SRC =	./src/commands/push.c ./src/commands/swap.c ./src/commands/rotate.c ./src/commands/rev_rotate.c \
		./src/main/errors.c ./src/main/helpers.c ./src/main/stack_info.c \
		./src/main/sort_three.c \
		./src/main/main.c ./src/main/split.c \
		./src/main/init_stack.c ./src/main/init_a.c ./src/main/init_b.c \
		./src/main/sort_stacks.c \
		
		
CC = cc
CFLAGS = -Werror -Wextra -Wall

all : $(NAME)

OBJ = $(SRC:.c=.o)

$(NAME) : $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean :  
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.SECONDARY: $(OBJ)

.PHONY: all clean fclean re