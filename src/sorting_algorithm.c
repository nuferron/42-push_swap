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

int	less_moves(t_stack *stack, int max)
{
	int		top;
	int		bottom;
	t_stack	*last;

	top = 0;
	bottom = 0;
	last = last_node(stack);
	while (stack)
	{
		if (stack->id < max)
			break ;
		top++;
		stack = stack->next;
	}
	while (last)
	{
		if (last->id < max)
			break ;
		bottom++;
		last = last->prev;
	}
	if (bottom < top)
		return (-bottom);
	return (top);
}

void	from_a_to_b(t_stack **a, t_stack **b, int x, int y)
{
	t_stack	*last;

	while (is_sorted(*a) != 0)
	{
		last = last_node(*a);
		if ((*a)->id < y * x && (*a)->id < is_max(*a) - 1)
		{
			push(a, b, 'b');
			if (*b && (*b)->next && (*b)->id < (x * y - y / 2))
				rotate(b, 'b');
		}
		else if (less_moves(*a, x * y) <= 0)
			reverse_rotate(a, 'a');
		else
			rotate(a, 'a');
		if (element_num(*b) == x * y)
			x++;
	}
}

void	from_b_to_a(t_stack **a, t_stack **b)
{
	while (*b)
	{
		if ((*b)->id >= is_max(*b) - 2)
		{
			push(b, a, 'a');
			if ((*a)->id == is_max(*b) - 2)
				rotate(a, 'a');
			else if ((*a)->id - (*a)->next->id == 1)
				swap(a, 'a');
			if ((*a)->next->id - (last_node(*a))->id == 2
				|| (*a)->id - (last_node(*a))->id == 2)
				reverse_rotate(a, 'a');
		}
		else if (where_is(*b, is_max(*b)) > element_num(*b) / 2)
			reverse_rotate(b, 'b');
		else
			rotate(b, 'b');
	}
}

void	sorting_more(t_stack **a, t_stack **b)
{
	if (element_num(*a) >= 500)
		from_a_to_b(a, b, 1, element_num(*a) / 8);
	else
		from_a_to_b(a, b, 1, element_num(*a) / 4);
	if (element_num(*b) >= 500)
		from_b_to_a(a, b);
	else
		from_b_to_a(a, b);
	if (is_sorted(*a) != 0)
		swap(a, 'a');
}
