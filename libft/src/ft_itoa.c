/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuferron <nuferron@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 00:15:43 by nuferron          #+#    #+#             */
/*   Updated: 2023/09/13 20:21:41 by nuferron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_conversion(char *str, int n, int sign, int nlen)
{
	str[nlen] = '\0';
	while (nlen > 0)
	{
		str[--nlen] = n % 10 + '0';
		n = n / 10;
	}
	if (sign)
		str[0] = '-';
	return (str);
}

char	*ft_itoa(int n)
{
	int	nlen;
	int	sign;
	char	*str;

	sign = 0;
	nlen = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	if (n < 0)
	{
		sign = -1;
		n = -n;
		nlen++;
	}
	str = (char *)malloc(sizeof(char) * (nlen + 1));
	if (!str)
		return (NULL);
	return (ft_conversion(str, n, sign, int_len(n) + nlen));
}