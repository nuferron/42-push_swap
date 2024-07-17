/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_till_five.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuferron <nuferron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 13:26:34 by nuferron          #+#    #+#             */
/*   Updated: 2023/09/14 15:17:59 by nuferron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sorting_three(t_stack **a)
{
	t_stack	*last;

	while (is_sorted(*a) != 0)
	{
		last = last_node(*a);
		if ((*a)->id - (*a)->next->id == 1)
			swap(a, 'a');
		else if ((*a)->id - last->id == 1 || (*a)->id - last->id == -1)
			reverse_rotate(a, 'a');
		else
			rotate(a, 'a');
	}
}

void	sorting_four(t_stack **a, t_stack **b, t_stack *last)
{
	if ((*a)->id == 0 || (*a)->id == 3)
		push(a, b, 'b');
	else if (last->id == 0 || last->id == 3)
	{
		reverse_rotate(a, 'a');
		push(a, b, 'b');
	}
	else
	{
		swap(a, 'a');
		push(a, b, 'b');
	}
	sorting_three(a);
	push(b, a, 'a');
	if ((*a)->id == 3)
		rotate(a, 'a');
}

static void	five_last_sort(t_stack **a, t_stack **b)
{
	int	max;

	max = is_max(*a);
	push(b, a, 'a');
	push(b, a, 'a');
	if (is_sorted(*a) == 0)
		return ;
	if (((*a)->next->id > max / 2 && (*a)->id > (*a)->next->id)
		|| ((*a)->next->id > max / 2 && (*a)->id - (*a)->next->id != 1))
		swap(a, 'a');
	while (is_sorted(*a) != 0)
		rotate(a, 'a');
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
			push(a, b, 'b');
		else if ((*a)->next->id == min || (*a)->next->id == max)
			swap(a, 'a');
		else if ((*a)->next->next->id == min || (*a)->next->next->id == max)
			rotate(a, 'a');
		else
			reverse_rotate(a, 'a');
	}
	sorting_three(a);
	five_last_sort(a, b);
}
