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

/* It checks if the first element lower than max is closer
to the beginning of the stack (returns 0) or to the end 
(returns 1)
*/
static int	less_moves(t_stack *stack, int max)
{
	t_stack	*last;

	last = last_node(stack);
	while (stack && last)
	{
		if (stack->id < max)
			return (0);
		else if (last->id < max)
			return (1);
		stack = stack->next;
		last = last->prev;
	}
	return (0);
}

/* Elements are passed from stack A to stack B.
-> y is the number of elements of a chunk; for example,
for a stack with 100 elements, we will have 4 chunks of 25
elements each.
-> x is the number of chunks we have passed to the stack B (starting 1)

1. Is the first element in the stack A part of the chunk and not the maximum?
	For example, in a stack with 100 elements, in the first loop:
	Is the first element less than 25?
	YES
		L> Push it to B
		a) Is this element in the first half of the chunk (p.e. 0-12)?
		YES => rotate (first to last)
	NO
2. Is the closest element belonging to the chunk near the end of the stack?
	YES => reverse rotate (last to first)
	NO => rotate (first to last)
3. Are all the numbers of the chunk in the stack B?
	YES => x++ (let's start working with the next chunk)
*/
static void	from_a_to_b(t_stack **a, t_stack **b, int y)
{
	int	x;

	x = 1;
	while (is_sorted(*a) != 0)
	{
		if ((*a)->id < y * x && (*a)->id < is_max(*a) - 1)
		{
			push(a, b, 'b');
			if ((*b)->id < (x * y - y / 2))
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

/* Elements are past from stack B to stack A.
1. Is the first element one of the three largest elements in stack B?
	YES
		L> Push it to A
		a) Was it the third largest element?
			YES => rotate (put it in the last position)
		b) Is it greater by one unit than the next element?
			YES => swap
		c) Is the last element in stack A smaller than the first
			or the second element by two units?
			YES => reverse rotate (put it in the first position)
	NO
2. Is the maximum element in the stack B in the second half of the stack?
	YES => reverse rotate (last to first)
	NO => rotate (first to last)
*/
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

/* Stack A will be divided into chunks:
If the stack has 500 or more elements, it will be divided into 8 chunks
If the stack has 6 to 499 elements, it will be divided into 4 chunks
Elements will be passed in a certain way to stack B and then, again to
the stack A*/
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