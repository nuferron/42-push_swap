/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuferron <nuferron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 18:58:54 by nuferron          #+#    #+#             */
/*   Updated: 2023/08/13 20:44:04 by nuferron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	do_swap(t_stack **a, t_stack **b, char *str)
{
	if (ft_strncmp(str, "sa", 2) == 0)
		swap(a, '0');
	else if (ft_strncmp(str, "sb", 2) == 0)
		swap(b, '0');
	else
	{
		swap(a, '0');
		swap(b, '0');
	}
}

void	do_rev_n_rot(t_stack **a, t_stack **b, char *str)
{
	if (ft_strncmp(str, "rra", 3) == 0)
		reverse_rotate(a, '0');
	else if (ft_strncmp(str, "rrb", 3) == 0)
		reverse_rotate(b, '0');
	else if (ft_strncmp(str, "rrr", 3) == 0)
	{
		reverse_rotate(a, '0');
		reverse_rotate(b, '0');
	}
	else if (ft_strncmp(str, "ra", 2) == 0)
		rotate(a, '0');
	else if (ft_strncmp(str, "rb", 2) == 0)
		rotate(b, '0');
	else
	{
		rotate(a, '0');
		rotate(b, '0');
	}
}

void	making_moves(t_stack **a, t_stack **b)
{
	char	*str;

	while (1)
	{
		str = get_next_line(0);
		if (!str || *str == '\n')
			break ;
		if (ft_strncmp(str, "s", 1) == 0)
			do_swap(a, b, str);
		else if (ft_strncmp(str, "r", 1) == 0)
			do_rev_n_rot(a, b, str);
		else if (ft_strncmp(str, "pb", 2) == 0)
			push(a, b, '0');
		else if (ft_strncmp(str, "pa", 2) == 0)
			push(b, a, '0');
		free(str);
	}
	free(str);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		i;

	i = 1;
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
		return (ft_printf("OK\n"));
	}
	making_moves(&a, &b);
	if (is_sorted(a) == 0)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	free_mem(a);
	return (0);
}
