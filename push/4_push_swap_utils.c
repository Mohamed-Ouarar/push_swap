/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_push_swap_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouarar <mouarar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 14:18:30 by mouarar           #+#    #+#             */
/*   Updated: 2025/02/18 10:31:32 by mouarar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_price(stack *a, stack *b)
{
	int	a_len;
	int	b_len;

	a_len = stack_len(a);
	b_len = stack_len(b);
	while (b)
	{
		b->push_price = b->index;
		if (!(b->aboce_median))
			b->push_price = b_len - b->index;
		if (b->tarhet_node->aboce_median)
			b->push_price += b->tarhet_node->index;
		else
			b->push_price += a_len - b->tarhet_node->index;
		b = b->next;
	}
}

void	set_cheapest(stack *node)
{
	stack	*cheapest;
	long	max;

	max = LONG_MAX;
	while (node)
	{
		if (node->push_price < max)
		{
			max = node->push_price;
			cheapest = node;
		}
		node = node->next;
	}
	cheapest->cheapest = true;
}

void	set_index(stack *node)
{
	int	i;
	int	mid;

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

void	set_target_node(stack *a, stack *b)
{
	stack	*target_node;
	stack	*current_a;
	long	best_match_value;

	while (b)
	{
		best_match_value = LONG_MAX;
		current_a = a ;
		while (current_a)
		{
			if (current_a->value > b->value && \
				current_a->value < best_match_value)
			{
				best_match_value = current_a->value;
				target_node = current_a;
			}
			current_a = current_a->next;
		}
		if (best_match_value == LONG_MAX)
			b->tarhet_node = find_smallest(a);
		else
			b->tarhet_node = target_node;
		b = b->next;
	}
}

void	init_nodes(stack *a, stack *b)
{
	set_index(a);
	set_index(b);
	set_target_node(a, b);
	set_price(a, b);
	set_cheapest(b);
}
