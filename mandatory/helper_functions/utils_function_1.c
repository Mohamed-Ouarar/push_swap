/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_function_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouarar <mouarar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 11:22:13 by mouarar           #+#    #+#             */
/*   Updated: 2025/02/26 12:34:29 by mouarar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	move_nodes(t_stack **a, t_stack **b)
{
	t_stack	*cheapest_node;

	cheapest_node = return_cheapest(*b);
	if (cheapest_node->first_half && \
		cheapest_node->target_node->first_half)
		rotate_both(a, b, cheapest_node);
	else if (!(cheapest_node->first_half) && \
		!(cheapest_node->target_node->first_half))
		reverse_rotate_both(a, b, cheapest_node);
	finish_rotation(b, cheapest_node, 'b');
	finish_rotation(a, cheapest_node->target_node, 'a');
	pa(a, b);
}

void	rotate_both(t_stack **a, t_stack **b, t_stack *cheapest)
{
	while (*a != cheapest->target_node && *b != cheapest)
		rr(a, b);
	set_index(*a);
	set_index(*b);
}

void	reverse_rotate_both(t_stack **a, t_stack **b, t_stack *cheapest)
{
	while (*a != cheapest->target_node && *b != cheapest)
		rrr(a, b);
	set_index(*a);
	set_index(*b);
}

void	finish_rotation(t_stack **node, t_stack *top_node, char stack)
{
	while (*node != top_node)
	{
		if (stack == 'a')
		{
			if (top_node->first_half)
				ra(node);
			else
				rra(node);
		}
		if (stack == 'b')
		{
			if (top_node->first_half)
				rb(node);
			else
				rrb(node);
		}
	}
}

void	push_swap(t_stack **a, t_stack **b)
{
	t_stack	*smallest;
	int		len_a;
	int		average;

	average = average_value(*a);
	len_a = stack_lenght(*a);
	first_step(average, a, b, len_a);
	three_sort(a);
	while (*b)
	{
		init_nodes(*a, *b);
		move_nodes(a, b);
	}
	set_index(*a);
	smallest = find_smallest(*a);
	if (smallest->first_half)
		while (*a != smallest)
			ra(a);
	else
		while (*a != smallest)
			rra(a);
}
