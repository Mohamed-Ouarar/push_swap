/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_method.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouarar <mouarar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 12:37:13 by mouarar           #+#    #+#             */
/*   Updated: 2025/02/18 10:14:45 by mouarar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	first_step(int average, stack **a, stack **b, int lenth)
{
	while (lenth-- > 3)
	{
		if ((*a)->value > average)
		{
			pb(a, b);
			rb(b);
		}
		else
			pb(a, b);
	}
}

static void	sort_function(int size, int *array)
{
	int	i;
	int	j;
	int	swap;

	i = 1;
	while (i <= size)
	{
		j = 0;
		while (j < size - i)
		{
			if (array[j] > array[j + 1])
			{
				swap = array[j + 1];
				array[j + 1] = array[j];
				array[j] = swap;
			}
			j++;
		}
		i++;
	}
}

int	average_value(stack *head)
{
	int	*array;
	int	average;
	int	size;

	size = 0;
	array = malloc(sizeof(int) * stack_len(head));
	if (!array)
	{
		free_stak(&head);
		exit(1);
	}
	while (head)
	{
		array[size] = head->value;
		head = head->next;
		size++;
	}
	sort_function(size, array);
	average = array[(size - 1) / 2];
	free(array);
	return (average);
}

void	empty_str(char *av, stack **a)
{
	int		i;
	char	**tmp;

	i = 0;
	if (*av == '\0')
	{
		write(2, "Error\n", 7);
		free_stak(a);
		exit(1);
	}
	tmp = ft_split(av, ' ');
	if (!tmp)
	{
		free_stak(a);
		exit(1);
	}
	stack_fill(a, tmp);
	while (tmp[i])
		free(tmp[i++]);
	free(tmp);
}
