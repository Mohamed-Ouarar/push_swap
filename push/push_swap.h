#ifndef PUSH_SWAP_H 
#define PUSH_SWAP_H

 #include <stdbool.h>
 #include <limits.h>
 #include <unistd.h>
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

void 	three_sort(stack **node);
void 	set_target_node(stack *a, stack *b);
void 	set_price(stack *a, stack *b);
void 	set_cheapest(stack *node);
stack 	*return_cheapest(stack *node);
void 	move_nodes(stack **a, stack **b);
void 	rotate_both(stack **a , stack **b, stack *cheapest);
void 	reverse_rotate_both(stack **a,stack **b, stack *cheapest);
void 	finish_rotation(stack **node, stack *top_node , char stack);
void 	push_swap(stack **a, stack **b);
stack	*ft_lstlast(stack *lst);
int 	max_value(stack **node);
stack 	*find_smallest(stack *node);
int 	stack_len(stack *node);
void 	set_index(stack *node);
int		repet_value(stack *a, int value);
void 	stack_fill(stack **a,char **av);
void 	append_value(stack **stak, int value);
int 	main(int ac, char **av);
stack	*ft_lstlast(stack *lst);
void	push(stack **dst, stack **src);
void 	rotate(stack **node);
void 	reverse_rotate(stack **node);
void 	swap(stack **node);

#endif