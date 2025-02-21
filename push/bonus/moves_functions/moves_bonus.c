/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouarar <mouarar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 10:17:51 by mouarar           #+#    #+#             */
/*   Updated: 2025/02/21 10:50:57 by mouarar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

void	rrr(t_stack **a, t_stack **b)
{
	rrb(b);
	rra(a);
}

void	push(t_stack **dst, t_stack **src)
{
	t_stack	*node_to_push;

	node_to_push = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->past = NULL;
	node_to_push->past = NULL;
	if (*dst == NULL)
	{
		*dst = node_to_push;
		node_to_push->next = NULL;
	}
	else
	{
		node_to_push->next = *dst;
		node_to_push->next->past = node_to_push;
		*dst = node_to_push;
	}
}

void	rotate(t_stack **node)
{
	t_stack	*last_node;
	int		lenght;

	lenght = stack_lenght(*node);
	if (1 == lenght)
		return ;
	last_node = ft_listlast(*node);
	last_node->next = *node;
	*node = (*node)->next;
	(*node)->past = NULL;
	last_node->next->past = last_node;
	last_node->next->next = NULL;
}

void	reverse_rotate(t_stack **node)
{
	t_stack	*last;
	int		lenght;

	lenght = stack_lenght(*node);
	if (lenght < 2)
		return ;
	last = ft_listlast(*node);
	last->past->next = NULL;
	last->next = *node;
	last->past = NULL;
	*node = last;
	last->next->past = last;
}

void	swap(t_stack **node)
{
	int	lenght;

	lenght = stack_lenght(*node);
	if (lenght < 2)
		return ;
	(*node) = (*node)->next;
	(*node)->past->past = *node;
	(*node)->past->next = (*node)->next;
	(*node)->next = (*node)->past;
	if ((*node)->next->next)
		(*node)->next->next->past = (*node)->next;
	(*node)->past = NULL;
}
