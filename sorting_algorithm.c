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

/*void	sorting_more(t_stack **a, t_stack **b)
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
}*/

void sorting_more(t_stack **a, t_stack **b)
{
	t_stack *last;
	int	x;

	x = 1;
	while (element_num(*a) > 1 && is_sorted(*a) != 0)
	{
		last = last_node(*a);
		if ((*a)->id < 10 * x && (*a)->id != is_max(*a))
			push(a, b, 'p', 'b');
		else if ((*a)->next->id < 10 * x)
			swap(a, 's', 'a');
		else if (last->id < 10 * x)
			reverse_rotate(a, 'v', 'a');
		else
			rotate(a, 'r', 'a');
		if (element_num(*b) == 10 * x)
			x++;
	}
	//print_stack(*a, "stack a:");
	//print_stack(*b, "stack b:");
	int	i = 0;
	while(*b && i < 13)
	{
		if ((*b)->id == is_max(*b) || (*b)->next->id == is_max(*b))
			push(b, a, 'p', 'a');
		else if ((*a)->id != is_min(*a) && (*b)->id < (*b)->next->id)
		{
			swap(a, 'S', 0);
			swap(b, 0, 0);
		}
		else if ((*a)->id - (*a)->next->id == 1)
			swap(a, 's', 'a');
		else if (where_is(*b, is_max(*b)) > element_num(*b) / 2)
			reverse_rotate(b, 'v', 'b');
		else /*if (where_is(*b, is_max(*b)) < element_num(*b) / 2)*/
			rotate(b, 'r', 'b');
		i++;
		print_stack(*a, "stack a:");
	}
}
