/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_functions_3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouarar <mouarar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 18:05:10 by mouarar           #+#    #+#             */
/*   Updated: 2025/02/18 18:23:25 by mouarar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

stack	*ft_lstlast(stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst ->next != NULL)
		lst = lst -> next;
	return (lst);
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

void is_sorted(stack *a, int a_lenth)
{
	if (stack_sorted(a) && (stack_len(a) == a_lenth))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}
