/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuferron <nuferron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 13:26:58 by nuferron          #+#    #+#             */
/*   Updated: 2023/09/13 22:48:30 by nuferron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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

int	is_max(t_stack *stack)
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

int	is_min(t_stack *stack)
{
	int		id;
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

void	print_moves(char move, char stack)
{
	if (stack == '0')
		return ;
	else if (stack != '2' && move != 'R')
		ft_printf("%c%c\n", move, stack);
	else if (stack != '2' && move == 'R')
		ft_printf("rr%c\n", stack);
	else if (stack == '2' && (move == 's' || move == 'r'))
		ft_printf("%c%c\n", move, move);
	else if (stack == '2' && move == 'R')
		ft_printf("rrr\n");
}
