#include "push_swap.h"

void	sorting_three(t_stack **a)
{
	t_stack	*last;

	while (is_sorted(*a) != 0)
	{
		last = last_node(*a);
		if ((*a)->id - (*a)->next->id == 1)
			swap(a, 's', 'a');
		else if ((*a)->id - last->id == 1 || (*a)->id - last->id == -1)
			reverse_rotate(a, 'v', 'a');
		else
			rotate(a, 'r', 'a');
	}
}

/*void	sorting_three(t_stack **a)
{
	while (is_sorted(*a) != 0)
	{
		last = last_node(*a);
		if (where_is((*a, 2) == 0)
			rotate(a, 'r', 'a');
		else
			swap(a, 's', 'a');
	}
}*/

void	sorting_four(t_stack **a, t_stack **b, t_stack *last)
{
	if ((*a)->id == 0 || (*a)->id == 3)
		push(a, b, 'p', 'b');
	else if (last->id == 0 || last->id == 3)
	{
		reverse_rotate(a, 'v', 'a');
		push(a, b, 'p', 'b');
	}
	else
	{
		swap(a, 's', 'a');
		push(a, b, 'p', 'b');
	}
	sorting_three(a);
	push(b, a, 'p', 'a');
	if ((*a)->id == 3)
		rotate(a, 'r', 'a');
}

void	five_last_sort(t_stack **a, t_stack **b)
{
	int	max;

	max = is_max(*a);
	push(b, a, 'p', 'a');
	push(b, a, 'p', 'a');
	if (is_sorted(*a) == 0)
		return ;
	if (((*a)->next->id > max / 2 && (*a)->id > (*a)->next->id)
		|| ((*a)->next->id > max / 2 && (*a)->id - (*a)->next->id != 1))
		swap(a, 's', 'a');
	while (is_sorted(*a) != 0)
		rotate(a, 'r', 'a');
}

void	sorting_five(t_stack **a, t_stack **b)
{
	int		min;
	int		max;

	while (element_num(*b) != 2)
	{
		min = is_min(*a);
		max = is_max(*a);
		if ((*a)->id == min || (*a)->id == max)
			push(a, b, 'p', 'b');
		else if ((*a)->next->id == min || (*a)->next->id == max)
			swap(a, 's', 'a');
		else if ((*a)->next->next->id == min ||(*a)->next->next->id == max)
			rotate(a, 'r', 'a');
		else 
			reverse_rotate(a, 'v', 'a');
	}
	sorting_three(a);
	five_last_sort(a, b);
}
