/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_functions_2_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouarar <mouarar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 10:17:30 by mouarar           #+#    #+#             */
/*   Updated: 2025/02/21 10:17:31 by mouarar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

static	char	**fill(char **str, const char *string, char c)
{
	int	lenght;
	int	j;

	j = 0;
	while (*string)
	{
		while (*string && *string == c)
			string++;
		if (*string && *string != c)
		{
			lenght = 0;
			while (string[lenght] && string[lenght] != c)
				lenght++;
			str[j] = ft_substr(string, 0, lenght);
			if (!str[j])
				return (free_contet(str, j));
			j++;
			string += lenght;
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
