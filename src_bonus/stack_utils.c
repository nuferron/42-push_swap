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

void	print_stack(t_stack *stack, char *str)
{
	if (!stack)
		return ;
	if (str[6] == 'a')
	{
		while (stack)
		{
			ft_printf("\033[0;32m");
			ft_printf("%s input: %d\n", str, stack->input);
			ft_printf("\033[0;m");
			stack = stack->next;
		}
	}
	else
	{
		while (stack)
		{
			ft_printf("\033[0;35m");
			ft_printf("%s input: %d\n", str, stack->input);
			ft_printf("\033[0;m");
			stack = stack->next;
		}
	}
	ft_printf("\n");
}
