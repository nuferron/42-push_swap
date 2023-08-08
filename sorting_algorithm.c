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
	while (is_sorted(*a) != 0)
	{
		last = last_node(*a);
		if (*b && (*b)->next && (*a)->id - (*a)->next->id == 1
			&& (*b)->next->id - (*b)->id == 1)
		{
			swap(a, 'S', 0);
			swap(b, 0, 0);
		}
		else if ((*a)->id - (*a)->next->id == 1)
			swap(a, 's', 'a');
		else if (last->id < 10 * x && (*a)->id < 10 * x && last->id < (*a)->id
				&& *b && last_node(*b)->id > (*b)->id)
			reverse_rotate(a, 'V', 0);
		else if (last->id < 10 * x && (*a)->id < 10 * x && last->id < (*a)->id)
			reverse_rotate(a, 'v', 'a');
		else if ((*a)->id < 10 * x && (*a)->id != is_max(*a) && (*a)->id != is_max(*a) - 1)
			push(a, b, 'p', 'b');
		else
			rotate(a, 'r', 'a');
		if (element_num(*b) == 10 * x)
			x++;
	}
	//ft_printf("FINAL DE LA PRIMERA PART\n");
	//print_stack(*a, "stack a:");
	//print_stack(*b, "stack b:");
	while (*b)
	{
		if ((*b) && (*b)->next && (*a)->id - (*a)->next->id == 1
			&& (*b)->id - (*b)->next->id == 1)
		{
			swap(a, 'S', 0);
			swap(b, 0, 0);
		}
		else if ((*a)->id - (*a)->next->id == 1)
			swap(a, 's', 'a');
		else if (((*b)->id == is_max(*b) || ((*b)->next->id == is_max(*b)
				&& (*b)->id - (*b)->next->id == -1)))
			push(b, a, 'p', 'a');
		else if (where_is(*b, is_max(*b)) > element_num(*b) / 2)
			reverse_rotate(b, 'v', 'b');
		else
			rotate(b, 'r', 'a');
	}
	if (is_sorted(*a) != 0)
		swap(a, 's', 'a');
}
