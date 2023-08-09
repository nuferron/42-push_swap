/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algorithm.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuferron <nuferron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 13:29:15 by nuferron          #+#    #+#             */
/*   Updated: 2023/08/09 15:36:30 by nuferron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	from_a_to_b(t_stack **a, t_stack **b, int x)
{
	t_stack	*last;

	while (is_sorted(*a) != 0)
	{
		last = last_node(*a);
		if ((*a)->id - (*a)->next->id == 1)
			swap(a, 's', 'a');
		else if (last->id < 10 * x && (*a)->id < 10 * x && last->id < (*a)->id
			&& *b && last_node(*b)->id > (*b)->id)
			reverse_rotate(a, 'V', 0);
		else if (last->id < 10 * x && (*a)->id < 10 * x && last->id < (*a)->id)
			reverse_rotate(a, 'v', 'a');
		else if ((*a)->id < 10 * x && (*a)->id != is_max(*a)
			&& (*a)->id != is_max(*a) - 1)
			push(a, b, 'p', 'b');
		else
			rotate(a, 'r', 'a');
		if (element_num(*b) == 10 * x)
			x++;
	}
}

void	sorting_more(t_stack **a, t_stack **b)
{
	from_a_to_b(a, b, 1);
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
			rotate(b, 'r', 'b');
	}
	if (is_sorted(*a) != 0)
		swap(a, 's', 'a');
}
