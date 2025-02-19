/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouarar <mouarar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 11:30:37 by mouarar           #+#    #+#             */
/*   Updated: 2025/02/19 11:30:38 by mouarar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stak(stack **head)
{
	stack	*tmp;

	while (*head)
	{
		tmp = (*head)->next;
		free(*head);
		*head = tmp;
	}
}

int	repet_value(stack *a, int value)
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

void	stack_fill(stack **a, char **av)
{
	long	nbr;

	while (*av)
	{
		nbr = ft_atoi(*av);
		if (nbr < INT_MIN || nbr > INT_MAX)
		{
			write(2, "Error\n", 6);
			free_stak(a);
			exit(1);
		}
		if (repet_value(*a, (int)nbr))
		{
			write(2, "Error\n", 6);
			free_stak(a);
			exit(1);
		}
		if (!append_value(a, (int)nbr))
		{
			free_stak(a);
			exit(1);
		}
		av++;
	}
}

int	append_value(stack **stak, int value)
{
	stack	*node;
	stack	*last_node;

	if (!stak)
		return (0);
	node = malloc(sizeof(stack));
	if (!node)
		return (0);
	node->next = NULL;
	node->value = value;
	node->cheapest = 0;
	if (*stak == NULL)
	{
		node->past = NULL;
		*stak = node;
	}
	else
	{
		last_node = ft_lstlast(*stak);
		node->past = last_node;
		last_node->next = node;
	}
	return (1);
}

int	main(int ac, char **av)
{
	stack	*a;
	stack	*b;

	a = NULL;
	b = NULL;
	if (ac == 1)
		return (1);
	av += 1;
	while (*av)
	{
		empty_str(*av, &a);
		av++;
	}
	if (!stack_sorted(a))
	{
		if (stack_len(a) == 2)
			sa(&a);
		else if (stack_len(a) == 3)
			three_sort(&a);
		else
			push_swap(&a, &b);
	}
	free_stak(&a);
	return (0);
}
