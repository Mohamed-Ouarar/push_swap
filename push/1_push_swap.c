/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_push_swap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouarar <mouarar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 09:02:31 by mouarar           #+#    #+#             */
/*   Updated: 2025/01/11 13:20:01 by mouarar          ###   ########.fr       */
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
	int		i;

	while (*av)
	{
		nbr = ft_atoi(*av);
		if (nbr < INT_MIN || nbr > INT_MAX)
		{
			write(1, "Error_1\n", 8);
			free_stak(a);
			exit(1);
		}
		if (repet_value(*a, (int)nbr))
		{
			write(1, "Error_2\n", 8);
			free_stak(a);
			exit(1);
		}
		append_value(a, (int)nbr);
		av++;
	}
}

void	append_value(stack **stak, int value)
{
	stack	*node;
	stack	*last_node;

	if (!stak)
		return ;
	node = malloc(sizeof(stack));
	if (!node)
		return ;
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
}

bool	stack_sorted(stack *node)
{
	if (!node)
		return (1);
	while (node->next)
	{
		if (node->value > node->next->value)
			return (false);
		node = node->next;
	}
	return (true);
}
#include <stdio.h>
void	ft_print_stack(stack *node)
{
	while (node)
	{
		printf("%d\n", (*node).value);
		node = node->next;
	}
}

int	main(int ac, char **av)
{
	stack	*a;
	stack	*b;
	char	**tmp;

	a = NULL;
	b = NULL;
	if (ac == 1 || (!av[1][0] && ac == 2))
		return (1);
	av += 1;
	while (*av)
	{
		tmp = ft_split(*av, ' ');
		stack_fill(&a, tmp);
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
	ft_print_stack(a);
	free_stak(&a);
}
