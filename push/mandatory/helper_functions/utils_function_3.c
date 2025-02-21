/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_function_3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouarar <mouarar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 11:22:31 by mouarar           #+#    #+#             */
/*   Updated: 2025/02/20 11:32:05 by mouarar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	set_price(t_stack *a, t_stack *b)
{
	int	a_lenght;
	int	b_lenght;

	a_lenght = stack_lenght(a);
	b_lenght = stack_lenght(b);
	while (b)
	{
		b->push_price = b->index;
		if (!(b->first_half))
			b->push_price = b_lenght - b->index;
		if (b->target_node->first_half)
			b->push_price += b->target_node->index;
		else
			b->push_price += a_lenght - b->target_node->index;
		b = b->next;
	}
}

void	set_cheapest(t_stack *node)
{
	t_stack	*cheapest;
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

void	set_index(t_stack *node)
{
	int	i;
	int	middle;

	i = 0;
	middle = stack_lenght(node) / 2;
	while (node)
	{
		node->index = i;
		if (i <= middle)
			node->first_half = true;
		else
			node->first_half = false;
		i++;
		node = node->next;
	}
}

void	set_target_node(t_stack *a, t_stack *b)
{
	t_stack	*target_node;
	t_stack	*current_a;
	long	best_match_value;

	while (b)
	{
		best_match_value = LONG_MAX;
		current_a = a;
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
			b->target_node = find_smallest(a);
		else
			b->target_node = target_node;
		b = b->next;
	}
}

void	init_nodes(t_stack *a, t_stack *b)
{
	set_index(a);
	set_index(b);
	set_target_node(a, b);
	set_price(a, b);
	set_cheapest(b);
}
