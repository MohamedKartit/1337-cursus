/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkartit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 20:31:13 by mkartit           #+#    #+#             */
/*   Updated: 2023/11/14 13:52:33 by mkartit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*ptr1;
	const unsigned char	*ptr2;

	if (!dest && !src)
		return (0);
	ptr1 = dest;
	ptr2 = src;
	if (ptr1 > ptr2)
		while (n--)
			*(ptr1 + n) = *(ptr2 + n);
	else
		while (n--)
			*ptr1++ = *ptr2++;
	return (dest);
}
