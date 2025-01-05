/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Swap_And_Push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouarar <mouarar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 14:02:56 by mouarar           #+#    #+#             */
/*   Updated: 2025/01/05 14:04:16 by mouarar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void pa(stack **a, stack **b)
{
	push(a, b);
	write(1, "pa\n", 3);
}

void pb(stack **a, stack **b)
{
	push(b, a);
	write(1, "pb\n", 3);
}

void sa(stack **node)
{
	write(1, "sa\n", 3);
	swap(node);
}

void sb(stack **node)
{
	write(1, "sb\n", 3);
	swap(node);
}

void ss(stack **node)
{
	write(1, "ss\n", 3);
	swap(node);
}