/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algorithm.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuferron <nuferron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 13:29:15 by nuferron          #+#    #+#             */
/*   Updated: 2023/09/13 22:48:30 by nuferron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	where_is(t_stack *stack, int num)
{
	int	ubi;

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

static int	less_moves(t_stack *stack, int max)
{
	t_stack	*last;

	last = last_node(stack);
	while (stack && last)
	{
		if (stack->id < max)
			return (1);
		else if (stack->id < max)
			return (0);
		stack = stack->next;
		last = last->next;
	}
	return (0);
}

static void	from_a_to_b(t_stack **a, t_stack **b, int y)
{
	int	x;

	x = 1;
	while (is_sorted(*a) != 0)
	{
		if ((*a)->id < y * x && (*a)->id < is_max(*a) - 1)
		{
			push(a, b, 'b');
			if (*b && (*b)->next && (*b)->id < (x * y - y / 2))
				rotate(b, 'b');
		}
		else if (less_moves(*a, x * y))
			reverse_rotate(a, 'a');
		else
			rotate(a, 'a');
		if (element_num(*b) == x * y)
			x++;
	}
}

static void	from_b_to_a(t_stack **a, t_stack **b)
{
	int		max_b;
	t_stack	*last;

	while (*b)
	{
		max_b = is_max(*b);
		if ((*b)->id >= max_b - 2)
		{
			push(b, a, 'a');
			if ((*a)->id == max_b - 2)
				rotate(a, 'a');
			else if ((*a)->id - (*a)->next->id == 1)
				swap(a, 'a');
			last = last_node(*a);
			if ((*a)->next->id - last->id == 2 || (*a)->id - last->id == 2)
				reverse_rotate(a, 'a');
		}
		else if (where_is(*b, max_b) > element_num(*b) / 2)
			reverse_rotate(b, 'b');
		else
			rotate(b, 'b');
	}
}

void	sorting_more(t_stack **a, t_stack **b)
{
	int	elem_a;

	elem_a = element_num(*a);
	if (elem_a >= 500)
		from_a_to_b(a, b, elem_a / 8);
	else
		from_a_to_b(a, b, elem_a / 4);
	from_b_to_a(a, b);
	if (is_sorted(*a) != 0)
		swap(a, 'a');
}
