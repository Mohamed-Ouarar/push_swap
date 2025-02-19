/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_function_5.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouarar <mouarar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 11:22:43 by mouarar           #+#    #+#             */
/*   Updated: 2025/02/19 13:49:56 by mouarar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

long	ft_atoi(const char *str)
{
	int				i;
	int				sign;
	long			result;

	sign = 1;
	i = 0;
	result = 0;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
		if (!str[i])
			return (LONG_MAX);
	}
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		result = result * 10 + str[i] - 48;
		i++;
		if (result > INT_MAX)
			return (LONG_MAX);
	}
	if (str[i] && (str[i] < '0' || str[i] > '9'))
		return (LONG_MAX);
	return (result * sign);
}

void	first_step(int average, t_stack **a, t_stack **b, int lenth)
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

int	average_value(t_stack *head)
{
	int	*array;
	int	average;
	int	size;

	size = 0;
	array = malloc(sizeof(int) * stack_len(head));
	if (!array)
	{
		free_stack(&head);
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

void	empty_str(char *av, t_stack **a)
{
	int		i;
	char	**tmp;

	i = 0;
	if (*av == '\0')
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
