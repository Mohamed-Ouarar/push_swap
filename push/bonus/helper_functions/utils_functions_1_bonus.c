/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_functions_1_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouarar <mouarar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 10:17:25 by mouarar           #+#    #+#             */
/*   Updated: 2025/02/23 09:43:09 by mouarar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

int	stack_lenght(t_stack *node)
{
	int	count;

	count = 0;
	if (!node)
		return (0);
	while (node)
	{
		count++;
		node = node->next;
	}
	return (count);
}

void	check_argement(char **av, t_stack **a)
{
	while (*av)
	{
		empty_str(*av, a);
		av++;
	}
}

long	ft_atoi(const char *str)
{
	int				i;
	int				sign;
	long			result;

	sign = 1;
	i = 0;
	result = 0;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
		if (!str[i])
			return (LONG_MAX);
	}
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		result = result * 10 + str[i] - 48;
		i++;
		if ((result * sign) > INT_MAX || (result * sign) < INT_MIN)
			return (LONG_MAX);
	}
	if (str[i] && (str[i] < '0' || str[i] > '9'))
		return (LONG_MAX);
	return (result * sign);
}

char	*add_line_to_line(char const *s1, char const *s2)
{
	char	*ptr;
	int		i;
	int		j;

	ptr = NULL;
	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	ptr = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!ptr)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
		ptr[j++] = s1[i++];
	i = 0;
	free((void *)s1);
	while (s2[i])
		ptr[j++] = s2[i++];
	ptr[j] = '\0';
	return (ptr);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] == s2[i])
			i++;
		else
			return (0);
	}
	return (1);
}
