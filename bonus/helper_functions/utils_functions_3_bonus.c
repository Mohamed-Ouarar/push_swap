/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_functions_3_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouarar <mouarar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 10:17:37 by mouarar           #+#    #+#             */
/*   Updated: 2025/02/21 10:50:54 by mouarar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

t_stack	*ft_listlast(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst ->next != NULL)
		lst = lst -> next;
	return (lst);
}

bool	stack_sorted(t_stack *node)
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

void	is_sorted(t_stack *a, int a_lenth)
{
	if (stack_sorted(a) && (stack_lenght(a) == a_lenth))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}
