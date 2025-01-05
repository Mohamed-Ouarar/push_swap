/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouarar <mouarar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 13:44:31 by mouarar           #+#    #+#             */
/*   Updated: 2025/01/04 13:47:54 by mouarar          ###   ########.fr       */
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

int max_value(stack **node)
{
	stack *tmp;
	int max;

	max = INT_MIN;
	tmp = *node;
	while (tmp->next)
	{
		if (max < tmp->value)
			max = tmp->value;
		tmp = tmp->next;
	}
	return (max);
}

stack *find_smallest(stack *node)
{
	stack *smallest;
	long max;
	
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
int stack_len(stack *node)
{
	int	count;

	count = 0;
	if (!node)
		return 0;
	while (node)
	{
		count++;
		node = node->next;
	}
	return (count);
}

void set_index(stack *node)
{
	int i;
	int mid;

	i = 0;
	mid = stack_len(node) / 2;
	while (node)
	{
		node->index = i;
		if (i <= mid)
			node->aboce_median = true;
		else
			node->aboce_median = false;
		i++;
		node = node->next;
	}
}