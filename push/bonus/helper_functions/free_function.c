/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouarar <mouarar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 18:12:31 by mouarar           #+#    #+#             */
/*   Updated: 2025/02/18 18:19:17 by mouarar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

void	free_stack(stack **head)
{
	stack	*tmp;

	while (*head)
	{
		tmp = (*head)->next;
		free(*head);
		*head = tmp;
	}
}

void free_malloc(char **str)
{
	int i = 0;
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

void free_stacks(stack **a, stack **b)
{
	free_stack(a);
	if (*b)
		free_stack(b);
}
