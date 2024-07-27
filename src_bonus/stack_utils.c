/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuferron <nuferron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 13:25:31 by nuferron          #+#    #+#             */
/*   Updated: 2023/09/13 22:48:30 by nuferron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*new_node(int num, int id)
{
	t_stack	*element;

	element = (t_stack *)malloc(sizeof (t_stack));
	if (!element)
		return (NULL);
	element->input = num;
	element->id = id;
	element->next = NULL;
	element->prev = NULL;
	return (element);
}

t_stack	*last_node(t_stack *stack)
{
	if (!stack)
		return (stack);
	while (stack->next != NULL)
		stack = stack->next;
	return (stack);
}

void	add_back(t_stack **stack, t_stack *new)
{
	t_stack	*aux;

	if (!(*stack))
	{
		*stack = new;
		return ;
	}
	aux = last_node(*stack);
	aux->next = new;
	new->prev = aux;
}

int	free_mem(t_stack *stack)
{
	t_stack	*tmp;

	while (stack)
	{
		tmp = stack->next;
		free(stack);
		stack = tmp;
	}
	return (-1);
}

void	print_stack(t_stack *stack)
{
	static int	color = 1;

	if (!stack)
		return ;
	if (color == 1)
		ft_printf("\033[0;32mStack A: ");
	else
		ft_printf("\033[0;33mStack B: ");
	while (stack)
	{
		ft_printf("%d\n", stack->input);
		stack = stack->next;
	}
	ft_printf("\033[0;m\n");
	color = -color;
}