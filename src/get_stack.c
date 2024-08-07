/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuferron <nuferron@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 00:03:59 by nuferron          #+#    #+#             */
/*   Updated: 2023/09/13 22:48:30 by nuferron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../push_swap.h"

/* It creates a linked list with the element
value (num) and its FINAL id */
int	getting_a(t_stack **stack, int num, int id)
{
	t_stack	*tmp;

	tmp = new_node(num, id);
	if (!tmp)
		return (free_mem(*stack));
	if (*stack == NULL)
		*stack = tmp;
	else
		add_back(stack, tmp);
	return (0);
}

/* Given an array with the input (already valid),
the function returns the FINAL id of that element
in the stack */
int	getting_id(int argc, int *elements, int num)
{
	int	i;
	int	id;

	i = 0;
	id = 0;
	while ((i + 1) < argc)
	{
		if (elements[num] > elements[i])
			id++;
		i++;
	}
	return (id);
}

/* It initializes stack A */
int	creating_stack(int argc, char **input, t_stack **stack)
{
	int	*nums;
	int	i;
	int	aux;

	i = 1;
	aux = 0;
	nums = ft_calloc(argc - 1, sizeof (int));
	if (!nums)
		return (-1);
	while (i < argc)
		nums[aux++] = ft_atoll(input[i++]);
	i = -1;
	while (++i < argc - 1)
	{
		aux = getting_a(stack, nums[i], getting_id (argc, nums, i));
		if (aux == -1)
		{
			free(nums);
			return (-1);
		}
	}
	free(nums);
	return (0);
}
