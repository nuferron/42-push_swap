/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuferron <nuferron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 18:58:54 by nuferron          #+#    #+#             */
/*   Updated: 2023/08/29 23:01:17 by nuferron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	making_moves(t_stack **a, t_stack **b, char *str)
{
	int	prot;

	prot = -1;
	if (ft_strncmp(str, "s", 1) == 0)
		prot = do_swap(a, b, str);
	else if (ft_strncmp(str, "rr", 2) == 0)
		prot = do_rr(a, b, str);
	else if (ft_strncmp(str, "r", 1) == 0)
		prot = do_rot(a, b, str);
	else if (ft_strncmp(str, "p", 1) == 0)
		prot = do_push(a, b, str);
	if (prot == -1)
	{
		ft_printf("Error\n");
		exit(-1);
	}
}

void	reading_moves(t_stack **a, t_stack **b, int flag)
{
	char	*str;

	while (1)
	{
		str = get_next_line(0);
		if (!str || *str == '\n')
			break ;
		making_moves(a, b, str);
		if (flag == 1)
		{
			print_stack(*a, "stack a:");
			print_stack(*b, "stack b:");
		}
		free(str);
	}
	free(str);
}

void	checking_flag(int argc, char **argv, t_stack **a, t_stack **b)
{
	if (ft_strncmp(argv[1], "-v", 2) == 0)
	{
		creating_stack(argc - 1, ++argv, a);
		reading_moves(a, b, 1);
	}
	else
	{
		creating_stack(argc, argv, a);
		reading_moves(a, b, 0);
	}
}

int	main(int argc, char **argv)
{
	static t_stack	*a = NULL;
	static t_stack	*b = NULL;
	char			**input;

	input = argv;
	if (argc < 2)
		return (-1);
	if (argv[1][0] == '\0' || (ft_strncmp(argv[1], "-v", 2) == 0
		&& checking_input(argc - 1, ++input) == -1))
		return (ft_printf("Error\n"));
	else if (argv[1][0] == '\0' || checking_input(argc, argv) == -1)
		return (ft_printf("Error\n"));
	checking_flag(argc, argv, &a, &b);
	if (is_sorted(a) == 0 && !b)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	free_mem(a);
	return (0);
}
