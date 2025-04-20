/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack_a_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouarar <mouarar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 10:17:09 by mouarar           #+#    #+#             */
/*   Updated: 2025/02/25 14:18:24 by mouarar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

void	empty_str(char *av, t_stack **a)
{
	int		i;
	char	**tmp;

	i = 0;
	if (*av == '\0' || if_just_spaces(av))
	{
		write(2, "Error\n", 7);
		free_stack(a);
		exit(1);
	}
	tmp = ft_split(av, ' ');
	if (!tmp)
	{
		free_stack(a);
		exit(1);
	}
	stack_fill(a, tmp);
	while (tmp[i])
		free(tmp[i++]);
	free(tmp);
}

int	repet_value(t_stack *a, int value)
{
	if (!a)
		return (0);
	while (a)
	{
		if (a->value == value)
			return (1);
		a = a->next;
	}
	return (0);
}

void	stack_fill(t_stack **a, char **av)
{
	long	nbr;

	while (*av)
	{
		nbr = ft_atoi(*av);
		if (nbr > INT_MAX)
		{
			write(2, "Error\n", 6);
			free_stack(a);
			exit(1);
		}
		if (repet_value(*a, (int)nbr))
		{
			write(2, "Error\n", 6);
			free_stack(a);
			exit(1);
		}
		if (!append_value(a, (int)nbr))
		{
			free_stack(a);
			exit(1);
		}
		av++;
	}
}

int	append_value(t_stack **stak, int value)
{
	t_stack	*node;
	t_stack	*last_node;

	if (!stak)
		return (0);
	node = malloc(sizeof(t_stack));
	if (!node)
		return (0);
	node->next = NULL;
	node->value = value;
	if (*stak == NULL)
	{
		node->past = NULL;
		*stak = node;
	}
	else
	{
		last_node = ft_listlast(*stak);
		node->past = last_node;
		last_node->next = node;
	}
	return (1);
}

int	if_just_spaces(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}
