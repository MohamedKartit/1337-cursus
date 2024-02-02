/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkartit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 15:48:49 by mkartit           #+#    #+#             */
/*   Updated: 2023/11/01 15:48:51 by mkartit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	len;

	len = 0;
	while (len < n)
	{
		if ((unsigned char)s1[len] > (unsigned char)s2[len])
			return (1);
		else if ((unsigned char)s1[len] < (unsigned char)s2[len])
			return (-1);
		else if ((unsigned char)s1[len] == 0 || (unsigned char)s2[len] == 0)
			return ((unsigned char)s1[len] - (unsigned char)s2[len]);
		len++;
	}
	return (0);
}
