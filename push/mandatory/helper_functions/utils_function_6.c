/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_function_6.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouarar <mouarar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 11:22:56 by mouarar           #+#    #+#             */
/*   Updated: 2025/02/20 10:40:09 by mouarar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

bool	stack_sorted(t_stack *node)
{
	while (node->next)
	{
		if (node->value > node->next->value)
			return (false);
		node = node->next;
	}
	return (true);
}

void	three_sort(t_stack **node)
{
	t_stack	*big_node;

	big_node = max_value(*node);
	if (*node == big_node)
		ra(node);
	else if ((*node)->next == big_node)
		rra(node);
	if ((*node)->value > (*node)->next->value)
		sa(node);
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
