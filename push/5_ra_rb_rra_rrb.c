/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_and_rr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouarar <mouarar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 14:01:24 by mouarar           #+#    #+#             */
/*   Updated: 2025/01/05 14:01:52 by mouarar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ra(stack **a)
{
	rotate(a);
	write(1 ,"ra\n", 3);
}

void rb(stack **b)
{
	rotate(b);
	write(1 ,"ra\n", 3);
}

void rra(stack **a)
{
	reverse_rotate(a);
	write(1 ,"rra\n", 3);
}

void rrb(stack **b)
{
	reverse_rotate(b);
	write(1 ,"ra\n", 3);
}