/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuferron <nuferron@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 18:27:53 by nuferron          #+#    #+#             */
/*   Updated: 2023/09/13 20:21:42 by nuferron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	//if (dstsize <= 0)
	//	return (ft_strlen(src));
	while (src[i] != '\0' && i < (dstsize - 1))
	{
			dst[i] = src[i];
			i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}
/*
#include <string.h>
#include <stdio.h>
int main()
{
	char	dmem[50] = "yohohohohoohohoho";
	char	mem[] = "wassup";

	char *dstr = strdup("");
	char *str = strdup("helloooooo");
	size_t s = ft_strlcpy(dstr, str, 5);
	size_t a = ft_strlcat(dmem, mem, 30);
	printf("str %zu [dst] |%s| [src] %s\n", s, dstr, str);
	//printf("ret %zu [dst] %s [src] %s\n", a, dmem, mem);
}*/