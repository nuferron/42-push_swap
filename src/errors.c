/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuferron <nuferron@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 00:03:59 by nuferron          #+#    #+#             */
/*   Updated: 2023/09/14 15:17:25 by nuferron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* Converts a string into a long long integer */
long long	ft_atoll(char *str)
{
	int			i;
	long long	num;
	int			neg;

	i = 0;
	num = 0;
	neg = 1;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			neg = -neg;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = (num * 10) + (str[i] - '0');
		i++;
	}
	return (num * neg);
}

/* It checks if the element has already been parsed.
If an error happens, it returns 1.
If the element is duplicated, it returns 1.
Otherwise, it saves the number and returns 0 */
int is_duplicated(int argc, int i, int num)
{
	static int	*elements = NULL;
	int			j;

	j = 0;
	if (!elements)
	{
		elements = (int *)ft_calloc(argc, sizeof(int));
		if (!elements)
			return (1);
	}
	while (j < i)
	{
		if (elements[j] == num)
		{
			free(elements);
			return (1);
		}
		j++;
	}
	elements[i] = num;
	if (i == argc - 1)
		free(elements);
	return (0);
}

/* This function checks that the input is valid.
Input conditions:
1. Only integers (int) are accepted
2. Elements can't be duplicated*/
int	checking_input(int argc, char **input)
{
	int	i;
	int	j;

	i = 1;
	while (input[i] != NULL)
	{
		j = 0;
		if ((input[i][j] == '-' || input[i][j] == '+')
				&& input[i][j++] != '\0')
			j++;
		while (input[i][j] != '\0')
		{
			if (!(input[i][j] >= '0' && input[i][j] <= '9'))
				return (-1);
			j++;
		}
		if (ft_atoll(input[i]) > 2147483647 || ft_atoll(input[i]) < -2147483648)
			return (-1);
		if (is_duplicated(argc, i - 1, ft_atoll(input[i])))
			return (-1);
		i++;
	}
	return (0);
}
