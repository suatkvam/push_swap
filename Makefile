NAME= push_swap

INCLUDE_FLAGS = -I./error -I./utils -I./algorithms -I./libft -I./parser

LIBFT_DIR = libft
LIBFT_LIB = $(LIBFT_DIR)/libft.a
LIBFT_FLAGS = -L$(LIBFT_DIR) -lft

ERROR_SRC= exit_error.c has_duplicate.c is_not_numaric.c is_overflow.c \
			validate_arguments.c

UTILS_SRC=  ft_atoll.c free_stack.c init_stack.c free_id_list.c find_min_id.c \
			pop.c push.c push_a.c push_b.c reverse_rotate_a.c reverse_rotate_b.c \
			revese_rotate_both.c rotate_a.c rotate_b.c rotate_both.c \
			swap_a.c swap_b.c simultaneous_swap.c free_split_args.c \
			init_id_list.c
			
			
PARSER_SRC= process_args.c
ALGORITHMS_SRC= chunk.c  chunk_utils.c  is_sorted.c  set_rank_by_value.c  sort.c

SRC=	$(addprefix error/, $(ERROR_SRC))\
		$(addprefix utils/, $(UTILS_SRC))\
		$(addprefix parser/, $(PARSER_SRC))\
		$(addprefix algorithms/, $(ALGORITHMS_SRC))\
		main.c


OBJ= $(SRC:.c=.o)

CC= cc

CFLAG= -Wall -Werror -Wextra

CFLAG += $(INCLUDE_FLAGS)
CFLAG += -g

RM= rm -f

all: $(LIBFT_LIB) $(NAME) clean

$(NAME): $(OBJ) $(LIBFT_DIR)
	$(CC) $(CFLAG) -o $(NAME) $(OBJ) $(LIBFT_FLAGS)

$(LIBFT_LIB):
	@make -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAG) -c $< -o $@

clean:
	@make -C $(LIBFT_DIR) clean
	$(RM) $(OBJ)

fclean: clean
	@make -C $(LIBFT_DIR) fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re