/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_push_swap_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouarar <mouarar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 13:44:31 by mouarar           #+#    #+#             */
/*   Updated: 2025/01/12 05:21:23 by mouarar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

stack	*ft_lstlast(stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst ->next != NULL)
		lst = lst -> next;
	return (lst);
}

int	stack_len(stack *node)
{
	int	count;

	count = 0;
	if (!node)
		return (0);
	while (node)
	{
		count++;
		node = node->next;
	}
	return (count);
}

stack	*max_value(stack *node)
{
	stack	*big_node;
	int		max;

	if (!node)
		return (NULL);
	max = INT_MIN;
	while (node)
	{
		if (max < node->value)
		{
			max = node->value;
			big_node = node;
		}
		node = node->next;
	}
	return (big_node);
}

stack	*find_smallest(stack *node)
{
	stack	*smallest;
	long	max;

	if (!node)
		return (NULL);
	max = LONG_MAX;
	while (node)
	{
		if (node->value < max)
		{
			max = node->value;
			smallest = node;
		}
		node = node->next;
	}
	return (smallest);
}

stack	*return_cheapest(stack *node)
{
	if (NULL == node)
        return (NULL);
	while (node)
	{
		if (node->cheapest)
			return (node);
		node = node->next;
	}
	return (NULL);
}
