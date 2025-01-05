/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_numbers_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouarar <mouarar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 14:51:05 by mouarar           #+#    #+#             */
/*   Updated: 2025/01/05 14:35:07 by mouarar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void three_sort(stack **node)
{
	int max_number;

	max_number = max_value(&node);
	if ((*node)->value == max_number)
		ra(node);
	else if ((*node)->next->value == max_number)
		rra(node);
	if ((*node)->value > (*node)->next->value)
		sa(node);
}

void move_nodes(stack **a, stack **b)
{
	stack *cheaapest_node;

	cheaapest_node = return_cheapest(*b);
	if (cheaapest_node->aboce_median && cheaapest_node->tarhet_node->aboce_median)
		rotate_both(a, b, cheaapest_node);
	else if (!cheaapest_node->aboce_median && !cheaapest_node->tarhet_node->aboce_median)
		reverse_rotate_both(a, b, cheaapest_node);
	finish_rotation(a, cheaapest_node->tarhet_node, 'a');
	finish_rotation(b, cheaapest_node, 'b');
	pa(a, b);
}

void rotate_both(stack **a , stack **b, stack *cheapest)
{
	while (*a != cheapest->tarhet_node && *b != cheapest)
		rr(a, b);
	set_index(*a);
	set_index(*b);
}

void reverse_rotate_both(stack **a,stack **b, stack *cheapest)
{
	while (*a != cheapest->tarhet_node && *b != cheapest)
		rrr(a, b);
	set_index(*a);
	set_index(*b);
}

void finish_rotation(stack **node, stack *top_node , char stack)
{
	while (*node != top_node)
	{
		if (stack = 'a')
		{
			if (top_node->aboce_median)
				ra(node);
			else
				rra(node);
		}
		if (stack = 'b')
		{
			if (top_node->aboce_median)
				rb(node);
			else
				rrb(node);
		}
	}
}

void push_swap(stack **a, stack **b)
{
	stack *smallest;
	int		len_a;

	len_a = stack_len(*a);
	while (len_a-- > 3)
		pd(b, a);
	three_sort(a);
	while (*b)
	{
		init_nodes(*a, *b);
		move_nodes(a, b);
	}
	set_index(*a);
	smallest = find_smallest(*a);
	if (smallest->aboce_median)
		while (*a != smallest)
			ra(a);
	else 
		while ( *a != smallest)
			rra(a);	
}
