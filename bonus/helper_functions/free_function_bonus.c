/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_function_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouarar <mouarar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 10:17:16 by mouarar           #+#    #+#             */
/*   Updated: 2025/02/21 10:17:17 by mouarar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

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

void	free_malloc(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}

char	**free_contet(char **string, int count)
{
	int	i;

	i = 0;
	while (i < count)
		free(string[i++]);
	free(string);
	return (NULL);
}

void	free_stacks(t_stack **a, t_stack **b)
{
	free_stack(a);
	if (*b)
		free_stack(b);
}
