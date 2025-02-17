/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouarar <mouarar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 09:28:22 by mouarar           #+#    #+#             */
/*   Updated: 2025/02/14 09:33:46 by mouarar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	three_sort(stack **node)
{
	stack	*big_node;

	big_node = max_value(*node);
	if (*node == big_node)
		ra(node);
	else if ((*node)->next == big_node)
		rra(node);
	if ((*node)->value > (*node)->next->value)
		sa(node);
}

void	rrr(stack **a, stack **b)
{
	reverse_rotate(b);
	reverse_rotate(a);
	write(1, "rrr\n", 4);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	count_word(char const *str, char latter)
{
	int	i;
	int	words;
	int	inword;

	i = 0;
	words = 0;
	inword = 0;
	while (str[i])
	{
		if (!inword && str[i] != latter)
		{
			inword = 1;
			words++;
		}
		if (inword && str[i] == latter)
			inword = 0;
		i++;
	}
	return (words);
}
