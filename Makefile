NAME = push_swap

SRC = src/push_swap.c

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