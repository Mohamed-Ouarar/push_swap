/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouarar <mouarar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 09:21:27 by mouarar           #+#    #+#             */
/*   Updated: 2025/02/21 10:50:50 by mouarar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H 
# define PUSH_SWAP_BONUS_H

# include <stdbool.h>
# include <limits.h>
# include <unistd.h>
# include <stdlib.h>
# include "get_next_line/get_next_line.h"

typedef struct list
{
	struct list	*past;
	struct list	*next;
	int			value;
}	t_stack;

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

void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);
void	rra(t_stack **a);
void	rr(t_stack **a, t_stack **b);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
void	sa(t_stack **a);
void	sb(t_stack **b);
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
int		count_word(char const *str, char latter);
void	empty_str(char *av, t_stack**a);
void	free_malloc(char **str);
char	**free_contet(char **string, int count);
char	*read_input(t_stack **a);
int		ft_strcmp(char *s1, char *s2);
char	*add_line_to_line(char const *s1, char const *s2);
void	applay_moves(char *str, t_stack **a, t_stack **b);
void	free_stacks(t_stack **a, t_stack **b);
void	is_sorted(t_stack *a, int a_lenth);
void	check_argement(char **av, t_stack **a);

#endif