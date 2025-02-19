/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_function_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouarar <mouarar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 11:22:23 by mouarar           #+#    #+#             */
/*   Updated: 2025/02/19 13:49:15 by mouarar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*ft_lstlast(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst ->next != NULL)
		lst = lst -> next;
	return (lst);
}

int	stack_len(t_stack *node)
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

t_stack	*max_value(t_stack *node)
{
	t_stack	*big_node;
	int		max;

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

t_stack	*find_smallest(t_stack *node)
{
	t_stack	*smallest;
	long	max;

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

t_stack	*return_cheapest(t_stack *node)
{
	while (node)
	{
		if (node->cheapest)
			return (node);
		node = node->next;
	}
	return (NULL);
}
