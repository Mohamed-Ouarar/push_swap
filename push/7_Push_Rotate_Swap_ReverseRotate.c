/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   7_Push_Rotate_Swap_ReverseRotate.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouarar <mouarar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 11:44:04 by mouarar           #+#    #+#             */
/*   Updated: 2025/02/17 16:30:41 by mouarar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(stack **dst, stack **src)
{
	stack	*node_to_push;

	if (*src == NULL)
	{
		free_stak(dst);
		exit(1);
	}
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

void	rotate(stack **node)
{
	stack	*last_node;
	int		len;

	len = stack_len(*node);
	if (1 == len)
		return ;
	last_node = ft_lstlast(*node);
	last_node->next = *node;
	*node = (*node)->next;
	(*node)->past = NULL;
	last_node->next->past = last_node;
	last_node->next->next = NULL;
}

void	reverse_rotate(stack **node)
{
	stack	*last;
	int		len;

	len = stack_len(*node);
	if (1 == len)
		return ;
	last = ft_lstlast(*node);
	last->past->next = NULL;
	last->next = *node;
	last->past = NULL;
	*node = last;
	last->next->past = last;
}

void	swap(stack **node)
{
	(*node) = (*node)->next;
	(*node)->past->past = *node;
	(*node)->past->next = (*node)->next;
	(*node)->next = (*node)->past;
	if ((*node)->next->next)
		(*node)->next->next->past = (*node)->next;
	(*node)->past = NULL;
}
