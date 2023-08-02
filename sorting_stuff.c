#include "push_swap.h"

int	getting_max_id(t_stack *stack)
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

int	getting_min_id(t_stack *stack)
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

/*int	is_sorted(t_stack *stack)
{
	int	sort;

	sort = 0;
	if (stack->next == NULL)
		return (0);
	while (stack)
	{
		if (stack->id != sort)
			return (-1);
		sort++;
		stack = stack->next;
	}
	return (0);
}*/

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

/*void	five_last_sort(t_stack **a, t_stack **b)
{
	int	max;

	max = getting_max_id(*a);
	push(b, a);
	push(b, a);
	write(1, "pa\npa\n", 6);
	if (is_sorted(*a) == 0)
		return ;
	if (((*a)->next->id > max / 2 && (*a)->id > (*a)->next->id)
		|| ((*a)->next->id > max / 2 && (*a)->id - (*a)->next->id != 1)
		|| ((*a)->id - (*a)->next->id == 1 && (*a)->id < max / 2))
	{
		swap(a);
		write(1, "sa\n", 3);
	}
	if ((*a)->id - (*a)->next->id == -1)
	{
		rotate(a);
		rotate(a);
		write(1, "ra\n", 3);
	}
	else if ((*a)->id - (*a)->next->id != -1)
		rotate(a);
	write(1, "ra\n", 3);
}*/

void	five_last_sort(t_stack **a, t_stack **b)
{
	int	max;

	max = getting_max_id(*a);
	push(b, a, 'p', 'b');
	push(b, a, 'p', 'b');
	if (is_sorted(*a) == 0)
		return ;
	if (((*a)->next->id > max / 2 && (*a)->id > (*a)->next->id)
		|| ((*a)->next->id > max / 2 && (*a)->id - (*a)->next->id != 1)
		|| ((*a)->id - (*a)->next->id == 1 && (*a)->id < max / 2))
		swap(a, 's', 'a');
	if (is_sorted(*a) == 0)
		return ;
	if ((*a)->id - (*a)->next->id == -1)
	{
		rotate(a, 'r', 'a');
		rotate(a, 'r', 'a');
	}
	else if ((*a)->id - (*a)->next->id != -1)
		rotate(a, 'r', 'a');
}

//int	five_last_sort()

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

// AQUESTA FUNCIONA
void	sorting_five(t_stack **a, t_stack **b)
{
	int		min;
	int		max;

	while (element_num(*b) != 2)
	{
		min = getting_min_id(*a);
		max = getting_max_id(*a);
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
