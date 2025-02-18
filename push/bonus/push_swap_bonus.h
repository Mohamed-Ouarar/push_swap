/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouarar <mouarar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 09:21:27 by mouarar           #+#    #+#             */
/*   Updated: 2025/02/18 19:47:32 by mouarar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H 
# define PUSH_SWAP_BONUS_H

# include <stdbool.h>
# include <limits.h>
# include <unistd.h>
# include <stdlib.h>
#include "get_next_line/get_next_line.h"

typedef struct list
{
	struct list	*past;
	struct list	*next;
	int			value;
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

void	ra(stack **a);
void	rb(stack **b);
void	rr(stack **a, stack **b);
void	rrb(stack **b);
void	rrr(stack **a, stack **b);
void	rra(stack **a);
void	rr(stack **a, stack **b);
void	pa(stack **a, stack **b);
void	pb(stack **a, stack **b);
void	sa(stack **a);
void	sb(stack **b);
void	ss(stack **a, stack **b);

void	push(stack **dst, stack **src);
void	rotate(stack **node);
void	reverse_rotate(stack **node);
void	swap(stack **node);

long	ft_atoi(const char *str);
char	**ft_split(char const *s, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
void	free_stack(stack **head);
int		count_word(char const *str, char latter);
void	empty_str(char *av, stack **a);
void free_malloc(char **str);
char	**free_contet(char **string, int count);
char	*read_input(stack **a);
int	ft_strcmp(char *s1, char *s2);
char	*ft_strjoin_kakarot(char const *s1, char const *s2);
void applay_moves(char *str, stack **a, stack **b);
void free_stacks(stack **a, stack **b);
void is_sorted(stack *a, int a_lenth);

#endif