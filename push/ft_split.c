/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouarar <mouarar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 16:54:19 by mouarar           #+#    #+#             */
/*   Updated: 2025/01/05 14:40:40 by mouarar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	int	count_word(char const *str, char latter)
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

static	char	**free_contet(char **string, int count)
{
	int	i;

	i = 0;
	while (i < count)
		free(string[i++]);
	free(string);
	return (NULL);
}

static	char	**fill(char **str, const char *string, char c)
{
	int	len;
	int	j;

	j = 0;
	while (*string)
	{
		while (*string && *string == c)
			string++;
		if (*string && *string != c)
		{
			len = 0;
			while (string[len] && string[len] != c)
				len++;
			str[j] = ft_substr(string, 0, len);
			if (!str[j])
				return (free_contet(str, j));
			j++;
			string += len;
		}
	}
	str[j] = NULL;
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**ptr;

	if (!s)
		return (NULL);
	ptr = (char **)(malloc(sizeof(char *) * (count_word(s, c) + 1)));
	if (!ptr)
		return (NULL);
	return (fill(ptr, s, c));
}
