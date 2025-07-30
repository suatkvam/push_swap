NAME= push_swap

SRC=

OBJ= $(SRC:.c=.o)

CC= CC

CFLAG= -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAG) -o $(NAME) $(OBJ)

clean:
	rm rf $(OBJ)

fclean: clean
	rm rf

re: fclean all

.PHONY: all clean fclean re
