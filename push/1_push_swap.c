#include "push_swap.h"

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
	return (0);
}
void stack_fill(stack **a,char **av)
{
	long		nbr;
	while (av)
	{
		nbr = ft_atoi(*av);
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
	node->cheapest = 0;
	if (*stak = NULL)
	{
		node->past = NULL;
		*stak = node;
	}
	else
	{
		last_node = ft_lstlast(*stak);
		node->past = last_node;
		last_node->next = node;
	}
}

bool stack_sorted(stack *node)
{
	if (!node)
		return 1;
	while (node->next)
	{
		if (node->value > node->next->value)
			return false;
		node = node->next;
	}
	return true;
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
	stack_fill(&a, av + 1);
	if (!stack_sorted(a))
	{
		if (stack_len(a) == 2)
			sa(&a);
		else if (stack_len(a) == 3)
			three_sort(&a);
		else
			push_swap(&a, &b);
	}
	// free_stack(&a);
	return 0;
}