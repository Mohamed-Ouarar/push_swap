/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa_pb_sa_sb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouarar <mouarar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:58:20 by mouarar           #+#    #+#             */
/*   Updated: 2025/02/19 10:47:48 by mouarar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

void	pa(t_stack **a, t_stack **b)
{
	if (!*b)
		return ;
	push(a, b);
}

void	pb(t_stack **a, t_stack **b)
{
	if (!*a)
		return ;
	push(b, a);
}

void	sa(t_stack **a)
{
	if (!*a)
		return ;
	swap(a);
}

void	sb(t_stack **b)
{
	if (!*b)
		return ;
	swap(b);
}

void	ss(t_stack **a, t_stack **b)
{
	sa(a);
	sb(b);
}
