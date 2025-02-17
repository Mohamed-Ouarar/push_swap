/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_ra_rb_rra_rrb.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouarar <mouarar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 14:01:24 by mouarar           #+#    #+#             */
/*   Updated: 2025/02/14 09:30:02 by mouarar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(stack **a)
{
	rotate(a);
	write(1, "ra\n", 3);
}

void	rb(stack **b)
{
	rotate(b);
	write(1, "rb\n", 3);
}

void	rr(stack **a, stack **b)
{
	rotate(b);
	rotate(a);
	write(1, "rr\n", 3);
}

void	rra(stack **a)
{
	reverse_rotate(a);
	write(1, "rra\n", 4);
}

void	rrb(stack **b)
{
	reverse_rotate(b);
	write(1, "rrb\n", 4);
}
