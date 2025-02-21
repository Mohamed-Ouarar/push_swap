SRC = mandatory/helper_functions/utils_function_1.c mandatory/helper_functions/utils_function_2.c mandatory/helper_functions/utils_function_3.c mandatory/helper_functions/utils_function_4.c \
	mandatory/helper_functions/utils_function_5.c mandatory/helper_functions/utils_function_6.c mandatory/moves/apply_moves.c mandatory/moves/pa_pb_sa_sb_ss.c \
	mandatory/moves/ra_rb_rr_rra_rrb.c mandatory/push_swap.c

BONUS_SRC = bonus/get_next_line/get_next_line_bonus.c bonus/get_next_line/get_next_line_utils_bonus.c bonus/helper_functions/fill_stack_a_bonus.c bonus/helper_functions/free_function_bonus.c \
	bonus/helper_functions/utils_functions_1_bonus.c bonus/helper_functions/utils_functions_2_bonus.c bonus/helper_functions/utils_functions_3_bonus.c bonus/moves_functions/check_moves_bonus.c \
	bonus/moves_functions/moves_bonus.c bonus/moves_functions/pa_pb_sa_sb_ss_bonus.c bonus/moves_functions/ra_rb_rra_rrb_bonus.c bonus/push_swap_bonus.c

OBJS = $(SRC:.c=.o)
BONUS_OBJS = $(BONUS_SRC:.c=.o)
NAME = push_swap
BONUS_NAME = checker
CC = cc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

bonus : $(BONUS_NAME)

$(BONUS_NAME) : $(BONUS_OBJS)
	$(CC) $(CFLAGS) $(BONUS_OBJS) -o $(BONUS_NAME)

$(BONUS_OBJS) : %_bonus.o : %_bonus.c bonus/push_swap_bonus.h bonus/get_next_line/get_next_line.h
	$(CC) $(CFLAGS) -c $< -o $@

fclean : clean
	rm -f $(NAME) $(BONUS_NAME)

clean :
	rm -f $(OBJS) $(BONUS_OBJS)

re : fclean all
