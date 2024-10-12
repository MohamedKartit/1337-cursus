/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkartit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 21:36:59 by mkartit           #+#    #+#             */
/*   Updated: 2024/09/24 21:37:00 by mkartit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long int	ft_atoi(const char *nptr)
{
	int			x;
	long int	number;

	x = 0;
	number = 0;
	while (nptr[x] && ((nptr[x] >= 9 && nptr[x] <= 13) || nptr[x] == 32))
		x++;
	if (nptr[x] == '+')
		x++;
	while (nptr[x] >= '0' && nptr[x] <= '9')
	{
		number = number * 10 + (nptr[x] - 48);
		x++;
	}
	return (number);
}

int	len(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}
