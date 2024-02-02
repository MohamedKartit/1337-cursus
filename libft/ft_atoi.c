/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkartit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 20:40:51 by mkartit           #+#    #+#             */
/*   Updated: 2023/11/01 20:40:53 by mkartit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	x;
	int	sign;
	int	number;

	x = 0;
	sign = 1;
	number = 0;
	while (nptr[x] && ((nptr[x] >= 9 && nptr[x] <= 13) || nptr[x] == 32))
		x++;
	if (nptr[x] == '+' || nptr[x] == '-')
	{
		if (nptr[x] == '-')
			sign *= -1;
		x++;
	}
	while (nptr[x] >= '0' && nptr[x] <= '9')
	{
		number = number * 10 + (nptr[x] - 48);
		x++;
	}
	return (number * sign);
}
