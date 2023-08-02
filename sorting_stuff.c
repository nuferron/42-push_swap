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

int	sorting_three(t_stack **a)
{
	int	counter = 0;
	t_stack	*last;

	while (is_sorted(*a) != 0 && counter < 4)
	{
		last = last_node(*a);
		if ((*a)->id - (*a)->next->id == 1)
		{
			swap(a);
			write(1, "sa\n", 3);
		}
		else if ((*a)->id - last->id == 1 || (*a)->id - last->id == -1)
		{
			reverse_rotate(a);
			write(1, "rra\n", 4);
		}
		else
		{
			rotate(a);
			write(1, "ra\n", 3);
		}
		print_stack(*a, "three:");
		counter++;
	}
	return (counter);
}

void	sorting_four(t_stack **a, t_stack **b, t_stack *last)
{
	if ((*a)->id == 0 || (*a)->id == 3)
	{
		push(a, b);
		write(1, "pb\n", 3);
	}
	else if (last->id == 0 || last->id == 3)
	{
		reverse_rotate(a);
		push(a, b);
		write(1, "pb\nrra\n", 7);
	}
	else
	{
		swap(a);
		push(a, b);
		write(1, "sa\npb\n", 3);
	}
	sorting_three(a);
	push(b, a);
	write(1, "pa\n", 3);
	if ((*a)->id == 3)
	{
		rotate(a);
		write(1, "ra\n", 3);
	}
}

void	five_last_sort(t_stack **a, t_stack **b)
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
}

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
/* AQUESTA ES LA QU FUNCIONA PER TOTS ELS CASOS
int	sorting_five(t_stack **a, t_stack **b)
{
	t_stack *last;
	int		counter = 0;
	int		min;
	int		max;

	while (element_num(*b) != 2 && counter < 5)
	{
		last = last_node(*a);
		min = getting_min_id(*a);
		max = getting_max_id(*a);
		if ((*a)->id == min || (*a)->id == max)
		{
			push(a, b);
			write(1, "pb\n", 3);
		}
		else if (last->id == min || last->id == max)
		{
			reverse_rotate(a);
			push(a, b);
			write(1, "rra\npb\n", 7);
		}
		else if ((*a)->next->id == min || (*a)->next->id == max)
		{
			swap(a);
			push(a, b);
			write(1, "sa\npb\n", 6);
		}
		else if ((*a)->next->next->id == min ||(*a)->next->next->id == max)
		{
			rotate(a);
			write(1, "ra\n", 3);
		}
		else if ((*a)->next->next->next->id == min
				|| (*a)->next->next->next->id == max)
		{
			reverse_rotate(a);
			write(1, "rra\n", 4);
		}
	}
	sorting_three(a);
	if (is_sorted(*a) != 0 || (*a)->id != 0 || (last_node(*a))->id != max)
		five_last_sort(a, b);
	return (0);
}*/

int	sorting_five(t_stack **a, t_stack **b)
{
	int		min;
	int		max;

	while (element_num(*b) != 2)
	{
		min = getting_min_id(*a);
		max = getting_max_id(*a);
		if ((*a)->id == min || (*a)->id == max)
			print_moves(a, b, 'b', NULL);
		else if ((last_node(*a))->id == min || (last_node(*a))->id == max)
		{
			print_moves(a, b, 'R', reverse_rotate);
			print_moves(a, b, 'b', NULL);
		}
		else if ((*a)->next->id == min || (*a)->next->id == max)
		{
			print_moves(a, b, 's', swap);
			print_moves(a, b, 'b', NULL);
		}
		else if ((*a)->next->next->id == min ||(*a)->next->next->id == max)
			print_moves(a, b, 'r', rotate);
		else /*if ((*a)->next->next->next->id == min
				|| (*a)->next->next->next->id == max)*/
			print_moves(a, b, 'R', reverse_rotate);
	}
	sorting_three(a);
	if (is_sorted(*a) != 0 || (*a)->id != 0 || (last_node(*a))->id != max)
		five_last_sort(a, b);
	return (0);
}
