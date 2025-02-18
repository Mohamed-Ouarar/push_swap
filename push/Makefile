SRC = 1_push_swap.c 2_3_numbers_sort.c 3_push_swap_utils.c 4_push_swap_utils.c 5_ra_rb_rra_rrb.c 6_pa_pb_sa_sb.c \
	7_Push_Rotate_Swap_ReverseRotate.c ft_atoi.c ft_split.c new_method.c utils_functions.c

BONUS_SRC = bonus/get_next_line/get_next_line.c bonus/get_next_line/get_next_line_utils.c bonus/helper_functions/fill_stack_a.c bonus/helper_functions/free_function.c \
	bonus/helper_functions/utils_functions_1.c bonus/helper_functions/utils_functions_2.c bonus/helper_functions/utils_functions_3.c bonus/moves_functions/check_moves.c \
	bonus/moves_functions/moves.c bonus/moves_functions/pa_pb_sa_sb.c bonus/moves_functions/ra_rb_rra_rrb.c bonus/push_swap_bonus.c

OBJS = $(SRC:.c=.o)
BONUS_OBJS = $(BONUS_SRC:.c=.o)
NAME = push_swap
BONUS_NAME = checker
CC = cc
CFLAGS = -Wall -Wextra -Werror #-fsanitize=address -g

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

bonus : $(BONUS_NAME)

$(BONUS_NAME) : $(BONUS_OBJS)
	$(CC) $(CFLAGS) $(BONUS_OBJS) -o $(BONUS_NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

fclean : clean
	rm -f $(NAME) $(BONUS_NAME)

clean :
	rm -f $(OBJS) $(BONUS_OBJS)

re : fclean all
