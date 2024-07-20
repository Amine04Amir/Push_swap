NAME = push_swap

SRC =	./src/0_main.c ./src/1_process.c \
		./src/utils.c ./src/utils1.c \
		./src/3_lst.c \
		./src/moves.c ./src/moves1.c ./src/moves2.c \
		./src/2_sort.c \
		
		
		
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