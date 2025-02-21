/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouarar <mouarar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 11:30:37 by mouarar           #+#    #+#             */
/*   Updated: 2025/02/21 11:07:39 by mouarar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack **head)
{
	t_stack	*tmp;

	while (*head)
	{
		tmp = (*head)->next;
		free(*head);
		*head = tmp;
	}
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
		if (nbr < INT_MIN || nbr > INT_MAX)
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

int	append_value(t_stack **stack, int value)
{
	t_stack	*node;
	t_stack	*last_node;

	if (!stack)
		return (0);
	node = malloc(sizeof(t_stack));
	if (!node)
		return (0);
	node->next = NULL;
	node->value = value;
	node->cheapest = 0;
	if (*stack == NULL)
	{
		node->past = NULL;
		*stack = node;
	}
	else
	{
		last_node = ft_listlast(*stack);
		node->past = last_node;
		last_node->next = node;
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

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
		if (stack_lenght(a) == 2)
			sa(&a);
		else if (stack_lenght(a) == 3)
			three_sort(&a);
		else
			push_swap(&a, &b);
	}
	free_stack(&a);
	return (0);
}
