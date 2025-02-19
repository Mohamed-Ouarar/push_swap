/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa_pb_sa_sb_ss.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouarar <mouarar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 11:26:16 by mouarar           #+#    #+#             */
/*   Updated: 2025/02/19 11:26:17 by mouarar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	pa(stack **a, stack **b)
{
	push(a, b);
	write(1, "pa\n", 3);
}

void	pb(stack **a, stack **b)
{
	push(b, a);
	write(1, "pb\n", 3);
}

void	sa(stack **node)
{
	write(1, "sa\n", 3);
	swap(node);
}

void	sb(stack **node)
{
	write(1, "sb\n", 3);
	swap(node);
}

void	ss(stack **a, stack **b)
{
	write(1, "ss\n", 3);
	swap(a);
	swap(b);
}
