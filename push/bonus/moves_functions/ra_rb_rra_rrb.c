/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra_rb_rra_rrb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouarar <mouarar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:58:29 by mouarar           #+#    #+#             */
/*   Updated: 2025/02/18 18:04:18 by mouarar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

void	ra(stack **a)
{
	if (!*a)
		return;
	rotate(a);
}

void	rb(stack **b)
{
	if (!*b)	
		return ;
	rotate(b);
}

void	rr(stack **a, stack **b)
{
	rb(b);
	ra(a);
}

void	rra(stack **a)
{
	if (!*a)
		return ;
	reverse_rotate(a);
}

void	rrb(stack **b)
{
	if (!*b)
		return ;
	reverse_rotate(b);
}
