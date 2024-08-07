/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuferron <nuferron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 13:16:35 by nuferron          #+#    #+#             */
/*   Updated: 2023/09/13 22:48:30 by nuferron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	distributor(t_stack **a, t_stack **b)
{
	int	max_id;

	max_id = is_max(*a);
	if (max_id == 1)
		swap(a, 'a');
	else if (max_id == 2)
		sorting_three(a);
	else if (max_id == 3)
		sorting_four(a, b, last_node(*a));
	else if (max_id == 4)
		sorting_five(a, b);
	else
		sorting_more(a, b);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	b = NULL;
	a = NULL;
	if (argc < 2)
		return (-1);
	if (argv[1][0] == '\0' || checking_input(argc, argv) == -1)
		return (ft_printf("Error\n"));
	creating_stack(argc, argv, &a);
	if (is_sorted(a) == 0)
	{
		free_mem(a);
		return (1);
	}
	distributor(&a, &b);
	free_mem(a);
	return (0);
}
