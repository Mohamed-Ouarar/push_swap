/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouarar <mouarar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 11:44:04 by mouarar           #+#    #+#             */
/*   Updated: 2025/01/05 14:04:44 by mouarar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(stack **dst, stack **src)
{
	stack *node_to_push;

	node_to_push = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->past = NULL;
	node_to_push->past = NULL;
	if (!*dst)
	{
		*dst = node_to_push;
		node_to_push->next = NULL;
	}
	else
	{
		node_to_push->next = *dst;
		node_to_push->past->next = node_to_push;
		*dst = node_to_push;
	}
}

void rotate(stack **node)
{
	stack *last_node;

	last_node = ft_lstlast(node);
	last_node->next = *node;
	*node = (*node)->next;
	(*node)->past = NULL;
	last_node->next->past = last_node;
	last_node->next->past = NULL;
}

void reverse_rotate(stack **node)
{
    stack *last;
    int len;

    len = stack_len(*node);
    if (NULL == *node || NULL == node || 1 == len)
        return;
    last = find_last_node(*node);
    last->past->next = NULL;
    last->next = *node;
    last->past = NULL;
    *node = last;
    last->next->past = last;
}

void swap(stack **node)
{
	stack *next;
	stack *head;

	next = (*node)->next->next;
	head = (*node)->next;

	(*node)->next->next->past = *node;
	(*node)->next->past = NULL;
	(*node)->next->next = (*node);

	(*node)->past = (*node)->next;	
	(*node)->next = next;

	*node = head;
}