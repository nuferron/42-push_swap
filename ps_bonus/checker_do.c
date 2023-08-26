/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_do.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuferron <nuferron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 14:44:08 by nuferron          #+#    #+#             */
/*   Updated: 2023/08/15 12:53:25 by nuferron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	do_swap(t_stack **a, t_stack **b, char *str)
{
	if (ft_strncmp(str, "sa\n", 3) == 0)
	{
		swap(a, '0');
		return (0);
	}
	if (ft_strncmp(str, "sb\n", 3) == 0)
	{
		swap(b, '0');
		return (0);
	}
	if (ft_strncmp(str, "ss\n", 3) == 0
		&& element_num(*a) > 1)
	{
		swap(a, '0');
		swap(b, '0');
		return (0);
	}
	return (-1);
}

int	do_rr(t_stack **a, t_stack **b, char *str)
{
	if (ft_strncmp(str, "rra\n", 4) == 0)
	{
		reverse_rotate(a, '0');
		return (0);
	}
	if (ft_strncmp(str, "rrb\n", 4) == 0)
	{
		reverse_rotate(b, '0');
		return (0);
	}
	if (ft_strncmp(str, "rrr\n", 4) == 0
		&& element_num(*a) > 1)
	{
		reverse_rotate(a, '0');
		reverse_rotate(b, '0');
		return (0);
	}
	if (ft_strncmp(str, "rr\n", 3) == 0
		&& element_num(*a) > 1)
	{
		rotate(a, '0');
		rotate(b, '0');
		return (0);
	}
	return (-1);
}

int	do_rot(t_stack **a, t_stack **b, char *str)
{
	if (ft_strncmp(str, "ra\n", 3) == 0)
	{
		rotate(a, '0');
		return (0);
	}
	if (ft_strncmp(str, "rb\n", 3) == 0)
	{
		rotate(b, '0');
		return (0);
	}
	return (-1);
}

int	do_push(t_stack **a, t_stack **b, char *str)
{
	if (ft_strncmp(str, "pa\n", 3) == 0)
	{
		push(b, a, '0');
		return (0);
	}
	if (ft_strncmp(str, "pb\n", 3) == 0)
	{
		push(a, b, '0');
		return (0);
	}
	return (-1);
}
