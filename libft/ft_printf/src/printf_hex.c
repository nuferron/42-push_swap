/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_hex_cap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuferron <nuferron@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 00:03:59 by nuferron          #+#    #+#             */
/*   Updated: 2023/11/29 15:54:49 by nuferron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	hex_conversion(int fd, unsigned int dec_num, const char *base)
{
	int			nbytes;
	int			hex_value;
	int			w_protection;

	hex_value = base[dec_num % 16];
	nbytes = 0;
	if (dec_num / 16 > 0)
	{
		dec_num = dec_num / 16;
		w_protection = hex_conversion(fd, dec_num, base);
		if (w_protection == -1)
			return (-1);
		nbytes += w_protection;
	}
	if (write(fd, &hex_value, 1) == -1)
		return (-1);
	nbytes++;
	return (nbytes);
}

int	print_hex(int fd, unsigned int dec_num, const char *base)
{
	if (dec_num == 0)
		return (write(fd, "0", 1));
	return (hex_conversion(fd, dec_num, base));
}
