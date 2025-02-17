SRC = 1_push_swap.c 2_3_numbers_sort.c 3_push_swap_utils.c 4_push_swap_utils.c 5_ra_rb_rra_rrb.c 6_pa_pb_sa_sb.c \
	7_Push_Rotate_Swap_ReverseRotate.c ft_atoi.c ft_split.c new_method.c utils_functions.c
OBJS = $(SRC:.c=.o)
NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror #-fsanitize=address -g

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

fclean : clean
	rm -f $(NAME)
clean :
	rm -f $(OBJS)
re : fclean all

