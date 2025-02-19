/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouarar <mouarar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 11:21:34 by mouarar           #+#    #+#             */
/*   Updated: 2025/02/19 13:41:57 by mouarar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	check_argement(char **av, t_stack **a)
{
	while (*av)
	{
		empty_str(*av, a);
		av++;
	}
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	char	*str;
	char	**ptr;
	int		a_lenth;

	a = NULL;
	b = NULL;
	if (ac == 1)
		return (1);
	av += 1;
	check_argement(av, &a);
	a_lenth = stack_len(a);
	str = read_input(&a);
	ptr = ft_split(str, '\n');
	free(str);
	ac = 0;
	while (ptr[ac])
		applay_moves(ptr[ac++], &a, &b);
	free_malloc(ptr);
	is_sorted(a, a_lenth);
	free_stacks(&a, &b);
}
