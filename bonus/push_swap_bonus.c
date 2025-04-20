/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouarar <mouarar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 11:21:34 by mouarar           #+#    #+#             */
/*   Updated: 2025/02/26 12:52:27 by mouarar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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
		return (0);
	av += 1;
	check_argement(av, &a);
	a_lenth = stack_lenght(a);
	str = read_input(&a);
	if (str)
	{
		ptr = ft_split(str, '\n');
		free(str);
		ac = 0;
		while (ptr[ac])
			applay_moves(ptr[ac++], &a, &b);
		free_malloc(ptr);
	}
	is_sorted(a, a_lenth);
	free_stacks(&a, &b);
}
