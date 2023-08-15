/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_do.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuferron <nuferron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 14:44:08 by nuferron          #+#    #+#             */
/*   Updated: 2023/08/14 16:47:12 by nuferron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	do_swap(t_stack **a, t_stack **b, char *str)
{
	if (str[1] == 'a' && element_num(*a) > 1)
	{
		swap(a, '0');
		return (0);
	}
	if (str[1] == 'b' && element_num(*b) > 1)
	{
		swap(b, '0');
		return (0);
	}
	if (str[1] == 's' && element_num(*a) > 1 && element_num(*b) > 1)
	{
		swap(a, '0');
		swap(b, '0');
		return (0);
	}
	return (-1);
}

int	do_rr(t_stack **a, t_stack **b, char *str)
{
	if (str[2] == 'a' && element_num(*a) > 1)
	{
		reverse_rotate(a, '0');
		return (0);
	}
	if (str[2] == 'b' && element_num(*b) > 1)
	{
		reverse_rotate(b, '0');
		return (0);
	}
	if (str[2] == 'r' && element_num(*a) > 1 && element_num(*b) > 1)
	{
		reverse_rotate(a, '0');
		reverse_rotate(b, '0');
		return (0);
	}
	if (str[1] == '\n' && element_num(*a) > 1 && element_num(*b) > 1)
	{
		rotate(a, '0');
		rotate(b, '0');
		return (0);
	}
	return (-1);
}

int	do_rot(t_stack **a, t_stack **b, char *str)
{
	if (str[1] == 'a' && element_num(*a) > 1)
	{
		rotate(a, '0');
		return (0);
	}
	if (str[1] == 'b' && element_num(*b) > 1)
	{
		rotate(b, '0');
		return (0);
	}
	return (-1);
}

int	do_push(t_stack **a, t_stack **b, char *str)
{
	if (str[1] == 'a' && element_num(*b) >= 1)
	{
		push(b, a, '0');
		return (0);
	}
	if (str[1] == 'b' && element_num(*a) >= 1)
	{
		push(a, b, '0');
		return (0);
	}
	return (-1);
}
