NAME = push_swap

SRC =	./src/main.c \
		./src/utils.c ./src/utils1.c \
		./src/lst.c \
		./src/moves.c ./src/moves1.c ./src/moves2.c \
		./src/parsing.c \
		
		
		
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