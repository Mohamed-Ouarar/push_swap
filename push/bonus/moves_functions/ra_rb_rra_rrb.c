/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra_rb_rra_rrb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouarar <mouarar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:58:29 by mouarar           #+#    #+#             */
/*   Updated: 2025/02/19 10:54:06 by mouarar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

void	ra(t_stack **a)
{
	if (!*a)
		return ;
	rotate(a);
}

void	rb(t_stack **b)
{
	if (!*b)
		return ;
	rotate(b);
}

void	rr(t_stack **a, t_stack **b)
{
	rb(b);
	ra(a);
}

void	rra(t_stack **a)
{
	if (!*a)
		return ;
	reverse_rotate(a);
}

void	rrb(t_stack **b)
{
	if (!*b)
		return ;
	reverse_rotate(b);
}
