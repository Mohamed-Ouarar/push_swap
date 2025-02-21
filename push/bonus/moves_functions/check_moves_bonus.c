/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_moves_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouarar <mouarar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 10:17:44 by mouarar           #+#    #+#             */
/*   Updated: 2025/02/21 10:17:45 by mouarar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

int	check_moves(char *str)
{
	if (ft_strcmp(str, "sa\n") || ft_strcmp(str, "sb\n")
		|| ft_strcmp(str, "ss\n"))
		return (1);
	else if (ft_strcmp(str, "pa\n") || ft_strcmp(str, "pb\n"))
		return (1);
	else if (ft_strcmp(str, "ra\n") || ft_strcmp(str, "rb\n")
		|| ft_strcmp(str, "rr\n"))
		return (1);
	else if (ft_strcmp(str, "rra\n") || ft_strcmp(str, "rrb\n")
		|| ft_strcmp(str, "rrr\n"))
		return (1);
	return (0);
}

void	applay_moves(char *str, t_stack **a, t_stack **b)
{
	if (ft_strcmp(str, "sa"))
		sa(a);
	if (ft_strcmp(str, "sb"))
		sb(b);
	if (ft_strcmp(str, "ss"))
		ss(a, b);
	if (ft_strcmp(str, "pa"))
		pa(a, b);
	if (ft_strcmp(str, "pb"))
		pb(a, b);
	if (ft_strcmp(str, "ra"))
		ra(a);
	if (ft_strcmp(str, "rb"))
		rb(b);
	if (ft_strcmp(str, "rr"))
		rr(a, b);
	if (ft_strcmp(str, "rra"))
		rra(a);
	if (ft_strcmp(str, "rrb"))
		rrb(b);
	if (ft_strcmp(str, "rrr"))
		rrr(a, b);
}

char	*read_input(t_stack **a)
{
	char	*str;
	char	*tmp;

	while (1)
	{
		tmp = get_next_line(0);
		if (!tmp)
			break ;
		if (!check_moves(tmp))
		{
			free(tmp);
			if (str)
				free(str);
			free_stack(a);
			write(2, "Error\n", 6);
			exit(1);
		}
		str = add_line_to_line(str, tmp);
		free(tmp);
	}
	return (str);
}
