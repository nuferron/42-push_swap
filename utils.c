#include "push_swap.h"

int	element_num(t_stack *stack)
{
	int	counter;

	counter = 0;
	while (stack)
	{
		counter++;
		stack = stack->next;
	}
	return (counter);
}

int	is_max(t_stack *stack)
{
	int	id;

	id = 0;
	while (stack)
	{
		if (stack->id > id)
			id = stack->id;
		stack = stack->next;
	}
	return (id);
}

int	is_min(t_stack *stack)
{
	int	id;
	t_stack	*tmp;

	id = 0;
	while (stack)
	{
		tmp = stack;
		while (tmp)
		{
			if (id == tmp->id)
				return (id);
			tmp = tmp->next;
		}
		id++;
	}
	return (-1);
}

int	is_sorted(t_stack *stack)
{
	if (stack->next == NULL)
		return (0);
	while (stack->next != NULL)
	{
		if (stack->id - stack->next->id != -1)
			return (-1);
		stack = stack->next;
	}
	return (0);
}

void	print_moves(char move, char stack)
{
	if (move == 'S')
		ft_printf("ss\n");
	else if (move == 'R')
		ft_printf("rr\n");
	else if (move == 'V')
		ft_printf("rrr\n");
	if (move == 'S' || move == 'R' || move == 'V')
		return ;
	if (move == 's')
		ft_printf("s");
	else if (move == 'r')
		ft_printf("r");
	else if (move == 'v')
		ft_printf("rr");
	else if (move == 'p')
		ft_printf("p");
	if (stack == 'a')
		ft_printf("a\n");
	else if (stack == 'b')
		ft_printf("b\n");
}
