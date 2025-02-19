/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_function_4.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouarar <mouarar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 11:22:37 by mouarar           #+#    #+#             */
/*   Updated: 2025/02/19 11:22:38 by mouarar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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

char	*ft_strdup(const char *s1)
{
	char	*ptr;
	int		i;

	i = 0;
	ptr = (char *)(malloc(sizeof(char) * (ft_strlen(s1) + 1)));
	if (!ptr)
		return (NULL);
	while (s1[i])
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	i;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if ((ft_strlen(s) - start) < len)
		ptr = malloc(sizeof(char) * (ft_strlen(s) - start + 1));
	else
		ptr = malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (NULL);
	i = 0;
	while (*(s + start + i) && (len > 0))
	{
		*(ptr + i) = *(s + start + i);
		i++;
		len--;
	}
	*(ptr + i) = '\0';
	return (ptr);
}
