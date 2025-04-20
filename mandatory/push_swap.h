/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouarar <mouarar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 09:21:27 by mouarar           #+#    #+#             */
/*   Updated: 2025/02/26 16:26:43 by mouarar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H 
# define PUSH_SWAP_H

# include <stdbool.h>
# include <limits.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_stack
{
	struct s_stack	*target_node;
	struct s_stack	*past;
	struct s_stack	*next;
	int				value;
	int				index;
	int				push_price;
	bool			first_half;
	bool			cheapest;
}					t_stack;

int		repet_value(t_stack *a, int value);
void	stack_fill(t_stack **a, char **av);
int		append_value(t_stack **stak, int value);
bool	stack_sorted(t_stack *node);
void	three_sort(t_stack **node);
void	move_nodes(t_stack **a, t_stack **b);
void	rotate_both(t_stack **a, t_stack **b, t_stack *cheapest);
void	reverse_rotate_both(t_stack **a, t_stack **b, t_stack *cheapest);
void	finish_rotation(t_stack **node, t_stack *top_node, char stack);
void	push_swap(t_stack **a, t_stack **b);
t_stack	*ft_listlast(t_stack *lst);
int		stack_lenght(t_stack *node);
t_stack	*max_value(t_stack *node);
t_stack	*find_smallest(t_stack *node);
t_stack	*return_cheapest(t_stack *node);
void	set_price(t_stack *a, t_stack *b);
void	set_cheapest(t_stack *node);
void	set_index(t_stack *node);
void	set_target_node(t_stack *a, t_stack *b);
void	init_nodes(t_stack *a, t_stack *b);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	rrb(t_stack **b);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
void	sa(t_stack **node);
void	sb(t_stack **node);
void	ss(t_stack **a, t_stack **b);
void	push(t_stack **dst, t_stack **src);
void	rotate(t_stack **node);
void	reverse_rotate(t_stack **node);
void	swap(t_stack **node);
long	ft_atoi(const char *str);
char	**ft_split(char const *s, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
void	free_stack(t_stack **head);
int		average_value(t_stack *head);
int		count_word(char const *str, char latter);
void	first_step(int average, t_stack **a, t_stack **b, int lenth);
void	empty_str(char *av, t_stack **a);
int		if_just_spaces(char *str);

#endif