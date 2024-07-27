/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuferron <nuferron@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 00:03:59 by nuferron          #+#    #+#             */
/*   Updated: 2023/09/13 22:48:30 by nuferron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../push_swap.h"

/* Swaps the first two elements of a stack */
void	swap(t_stack **stack, char s)
{
	int	tmp_input;
	int	tmp_id;

	if (element_num(*stack) < 2)
		return ;
	tmp_input = (*stack)->input;
	tmp_id = (*stack)->id;
	(*stack)->input = (*stack)->next->input;
	(*stack)->id = (*stack)->next->id;
	(*stack)->next->input = tmp_input;
	(*stack)->next->id = tmp_id;
	print_moves('s', s);
}

/* Pushes the first element of stack src into stack dst */
void	push(t_stack **src, t_stack **dst, char s)
{
	t_stack	*tmp;

	if (!(*src))
		return ;
	if (!(*dst))
	{
		*dst = *src;
		*src = (*src)->next;
		(*dst)->next = NULL;
	}
	else
	{
		tmp = (*dst);
		*dst = *src;
		*src = (*src)->next;
		(*dst)->next = tmp;
		((*dst)->next)->prev = *dst;
	}
	print_moves('p', s);
}

/* The first element of the stack becomes the last one */
void	rotate(t_stack **stack, char s)
{
	t_stack	*last;
	t_stack	*second;

	if (element_num(*stack) < 2)
		return ;
	last = last_node(*stack);
	second = (*stack)->next;
	last->next = (*stack);
	(*stack)->next = NULL;
	(*stack)->prev = last;
	(*stack) = second;
	(*stack)->prev = NULL;
	print_moves('r', s);
}

/* The last element of the stack becomes the first one */
void	reverse_rotate(t_stack **stack, char s)
{
	int		n;
	int		o;
	int		n1;
	int		o1;
	t_stack	*fil;

	if (element_num(*stack) < 2)
		return ;
	fil = (*stack);
	n = (*stack)->input;
	n1 = (*stack)->id;
	while ((*stack)->next != NULL)
	{
		(*stack) = (*stack)->next;
		o = (*stack)->input;
		o1 = (*stack)->id;
		(*stack)->input = n;
		(*stack)->id = n1;
		n = o;
		n1 = o1;
	}
	(*stack) = fil;
	(*stack)->input = n;
	(*stack)->id = n1;
	print_moves('R', s);
}
