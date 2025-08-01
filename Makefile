NAME= push_swap

INCLUDE_FLAGS = -I./error -I./utils -I./algorithms

ERROR_SRC= exit_error.c has_duplicate.c is_not_numaric.c is_overflow.c \
			validate_arguments.c

UTILS_SRC= ft_atoi.c ft_atoll.c ft_calloc.c free_stack.c init_stack.c \
			pop.c push.c push_a.c push_b.c reverse_rotate_a.c reverse_rotate_b.c \
			revese_rotate_both.c rotate_a.c rotate_b.c rotate_both.c \
			swap_a.c swap_b.c simultaneous_swap.c ft_split.c \
			ft_substr.c	ft_memcpy.c ft_strchr.c ft_strdup.c ft_strlen.c ft_strtrim.c




ALGORITHMS_SRC=	

SRC=	$(addprefix error/, $(ERROR_SRC))\
		$(addprefix utils/, $(UTILS_SRC))\
		$(addprefix algorithms/, $(ALGORITHMS_SRC))\
		main.c


OBJ= $(SRC:.c=.o)

CC= cc

CFLAG= -Wall -Werror -Wextra

CFLAG += $(INCLUDE_FLAGS)
CFLAG += -g

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAG) -o $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAG) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
