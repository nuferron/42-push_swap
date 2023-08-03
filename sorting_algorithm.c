#include "push_swap.h"

int	where_is(t_stack *stack, int num)
{
	int	total;
	int	ubi;

	total = element_num(stack);
	ubi = 0;
	while (stack)
	{
		if (stack->id == num)
			return (ubi);
		ubi++;
		stack = stack->next;
	}
	return (-1);
}

void	sorting_more(t_stack **a, t_stack **b)
{
	while (element_num(*a) > 3)
	{
		if ((*a)->id == is_min(*a))
			push(a, b, 'p', 'b');
		else if (where_is(*a, is_min(*a)) < element_num(*a) / 2)
			rotate(a, 'r', 'a');
		else
			reverse_rotate(a, 'v', 'a');
	}
	sorting_three(a);
	while (*b)
	{
		push(b, a, 'p', 'a');
	}
}
