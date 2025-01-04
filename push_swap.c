#include "push_swap.h"
#include <stdio.h>

int		repet_value(stack *a, int value)
{
	if (!a)
		return (0);
	while (a)
	{
		if (a->value == value)
			return (1);
		a = a->next;
	}
}
void stack_fill(stack **a,char **av)
{
	long		nbr;
	while (av)
	{
		nbr = ft_aoti(*av);
		// if (nbr < INT_MIN || nbr > INT_MAX)
		// {}
		// else if (repet_value(a, (int)nbr))
		// {}
		append_value(&a, (int)nbr);
		av++;
	}
}

void append_value(stack **stak, int value)
{
	stack *node;
	stack *last_node;

	if (!stak)
		return;
	node = malloc(sizeof(stack));
	if (!node)
		return; 
	node->next = NULL;
	node->value = value;
	if (*stak = NULL)
	{
		node->past = NULL;
		*stak = node;
	}
	else
	{
		last_node = ft_lstlast(&stak);
		node->past = last_node;
		last_node->next = node;
	}
}


int main(int ac, char **av)
{
	stack *a;
	stack *b;

	a = NULL;
	b = NULL;
	if (ac == 1 || !av[1][0])
		return (1);
	else if ( ac == 2)
		av = ft_split(av[1], ' ');
	stack_fill(&a, av);
}