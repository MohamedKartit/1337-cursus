/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkartit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 18:29:36 by mkartit           #+#    #+#             */
/*   Updated: 2023/11/01 18:29:37 by mkartit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	if (n > 0)
	{
		while (n-- > 0 && (*str1 == *str2))
		{
			if (n <= 0)
				break ;
			++str1;
			++str2;
		}
		return ((*(unsigned char *) str1 - *(unsigned char *) str2));
	}
	else
		return (0);
}
