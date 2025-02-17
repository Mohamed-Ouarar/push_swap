/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouarar <mouarar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 09:21:27 by mouarar           #+#    #+#             */
/*   Updated: 2025/02/17 16:30:21 by mouarar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H 
# define PUSH_SWAP_H

# include <stdbool.h>
# include <limits.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct list
{
	struct list	*tarhet_node;
	struct list	*past;
	struct list	*next;
	int			value;
	int			index;
	int			final_index;
	int			push_price;
	bool		aboce_median;
	bool		cheapest;
}	stack;

int		repet_value(stack *a, int value);
void	stack_fill(stack **a, char **av);
int		append_value(stack **stak, int value);
bool	stack_sorted(stack *node);
void	three_sort(stack **node);
void	move_nodes(stack **a, stack **b);
void	rotate_both(stack **a, stack **b, stack *cheapest);
void	reverse_rotate_both(stack **a, stack **b, stack *cheapest);
void	finish_rotation(stack **node, stack *top_node, char stack);
void	push_swap(stack **a, stack **b);
stack	*ft_lstlast(stack *lst);
int		stack_len(stack *node);
stack	*max_value(stack *node);
stack	*find_smallest(stack *node);
stack	*return_cheapest(stack *node);
void	set_price(stack *a, stack *b);
void	set_cheapest(stack *node);
void	set_index(stack *node);
void	set_target_node(stack *a, stack *b);
void	init_nodes(stack *a, stack *b);
void	ra(stack **a);
void	rb(stack **b);
void	rra(stack **a);
void	rrb(stack **b);
void	rrr(stack **a, stack **b);
void	rr(stack **a, stack **b);
void	rrb(stack **b);
void	pa(stack **a, stack **b);
void	pb(stack **a, stack **b);
void	sa(stack **node);
void	sb(stack **node);
void	ss(stack **node);
void	push(stack **dst, stack **src);
void	rotate(stack **node);
void	reverse_rotate(stack **node);
void	swap(stack **node);
long	ft_atoi(const char *str);
char	**ft_split(char const *s, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
void	free_stak(stack **head);
void	ft_print_stack(stack *node);
long	ft_u_atoi(const char *str);
int		average_value(stack *head);
int		count_word(char const *str, char latter);
void	first_step(int average, stack **a, stack **b, int lenth);
int		empty_str(char *av, stack **a);

#endif