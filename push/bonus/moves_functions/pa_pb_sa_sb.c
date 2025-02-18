/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa_pb_sa_sb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouarar <mouarar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:58:20 by mouarar           #+#    #+#             */
/*   Updated: 2025/02/18 18:04:14 by mouarar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

void	pa(stack **a, stack **b)
{
	if (!*b)
		return ;
	push(a, b);
}

void	pb(stack **a, stack **b)
{
	if (!*a)
		return ;
	push(b, a);
}

void	sa(stack **a)
{
	if (!*a)
		return ;
	swap(a);
}

void	sb(stack **b)
{
	if (!*b)
		return ;
	swap(b);
}

void	ss(stack **a, stack **b)
{
	sa(a);
	sb(b);
}
