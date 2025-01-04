/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_numbers_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouarar <mouarar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 14:51:05 by mouarar           #+#    #+#             */
/*   Updated: 2025/01/04 13:48:45 by mouarar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.c"


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


void set_target_node(stack *a, stack *b)
{
	stack *target_node;
	stack *current_a;
	long best_match_value;

	while (b)
	{
		best_match_value = LONG_MAX;
		current_a = a ;
		while (current_a)
		{
			if (current_a->value > b->value && current_a->value < best_match_value)
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





void set_price(stack *a, stack *b)
{
	int	a_len;
	int b_len;

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
void set_cheapest(stack *node)
{
	long max;
	stack *cheapest;
	
	if (!node)
		return ;
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

stack *return_cheapest(stack *node)
{
	while (node)
	{
		if (node->cheapest)
			return (node);
		node = node->next;
	}
	return (NULL);
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
