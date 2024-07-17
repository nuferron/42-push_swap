/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_len.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuferron <nuferron@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 13:17:27 by nuferron          #+#    #+#             */
/*   Updated: 2023/11/29 15:15:56 by nuferron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	int_len(int num)
{
	int	counter;

	counter = 1;
	while (num / 10 != 0)
	{
		num = num / 10;
		counter++;
	}
	return (counter);
}