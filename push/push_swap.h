#ifndef PUSH_SWAP_H 
#define PUSH_SWAP_H

#include <stdbool.h>
#include <limits.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct list
{
	int value;
	int index;
	int final_index;
	int push_price;
	bool aboce_median;
	bool cheapest;
	struct list *tarhet_node;
	struct list *past;
	struct list *next;
} stack;

int		repet_value(stack *a, int value);
void stack_fill(stack **a,char **av);
void append_value(stack **stak, int value);
bool stack_sorted(stack *node);
void three_sort(stack **node);
void move_nodes(stack **a, stack **b);
void rotate_both(stack **a , stack **b, stack *cheapest);
void reverse_rotate_both(stack **a,stack **b, stack *cheapest);
void finish_rotation(stack **node, stack *top_node , char stack);
void push_swap(stack **a, stack **b);
stack	*ft_lstlast(stack *lst);
int stack_len(stack *node);
int max_value(stack **node);
stack *find_smallest(stack *node);
stack *return_cheapest(stack *node);
void set_price(stack *a, stack *b);
void set_cheapest(stack *node);
void set_index(stack *node);
void set_target_node(stack *a, stack *b);
void	init_nodes(stack *a, stack *b);
void ra(stack **a);
void rb(stack **b);
void rra(stack **a);
void rrb(stack **b);
void pa(stack **a, stack **b);
void pb(stack **a, stack **b);
void sa(stack **node);
void sb(stack **node);
void ss(stack **node);
void	push(stack **dst, stack **src);
void rotate(stack **node);
void reverse_rotate(stack **node);
void swap(stack **node);
int	ft_atoi(const char *str);
char	**ft_split(char const *s, char c);



#endif