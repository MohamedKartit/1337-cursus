/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkartit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 14:39:24 by mkartit           #+#    #+#             */
/*   Updated: 2023/11/16 16:10:41 by mkartit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	l_dst;
	size_t	l_src;
	size_t	len;

	len = 0;
	if (dst == NULL && size == 0)
		return (ft_strlen(src));
	l_dst = ft_strlen(dst);
	l_src = ft_strlen(src);
	if (l_dst >= size || size == 0)
		return (l_src + size);
	while (src[len] && len < size - l_dst - 1)
	{
		dst[len + l_dst] = src[len];
		len++;
	}
	dst[len + l_dst] = '\0';
	return (l_dst + l_src);
}
