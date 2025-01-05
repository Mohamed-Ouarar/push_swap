SRC_FILES = push_swap.c push_swap_utils.c push.c 3_numbers_sort.c
OBJS_FILES = push_swap.o push_swap_utils.o push.o 3_numbers_sort.o

CC = cc 
CFLAGS = -Wall -Wxtra -Werror 
NAME = push_swap

all : $(NAME)

$(NAME) : $(OBJS_FILES)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean :
		rm -f $(OBJS_FILES)

fclean : clean 
	rm -f $(NAME)

re : fclean all