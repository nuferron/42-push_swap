/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuferron <nuferron@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 13:17:27 by nuferron          #+#    #+#             */
/*   Updated: 2023/09/13 20:21:41 by nuferron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*aux;
	size_t			i;

	i = 0;
	aux = s;
	while (i < n)
		aux[i++] = '\0';
}

/*
#include <strings.h>
#include <string.h>
int main()
{
	char str[] = "It's-a me, Mario!";
	char str2[] = "hola que tal";

	char *str3 = NULL;
	//str3 = strdup("hola");
	bzero(str, 300);
	//ft_memset(str, 127, -1);
	printf("bo |%s|\nft %s\n", str, str2);
}*/