/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkartit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 17:23:05 by mkartit           #+#    #+#             */
/*   Updated: 2023/11/04 17:23:07 by mkartit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	num_lenght(int n)
{
	long int		nbr;
	unsigned int	len;

	len = 0;
	nbr = n;
	if (nbr < 0)
	{
		len++;
		nbr *= -1;
	}
	while (nbr > 9)
	{
		nbr /= 10;
		len++;
	}
	len++;
	return (len);
}

char	*ft_itoa(int n)
{
	long int		nbr;
	unsigned int	len;
	char			*str;

	nbr = n;
	len = num_lenght(nbr);
	str = (char *)malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	str[len--] = '\0';
	if (nbr == 0)
		str[0] = '0';
	else if (nbr < 0)
	{
		nbr *= -1;
		str[0] = '-';
	}
	while (nbr > 0)
	{
		str[len--] = (nbr % 10) + 48;
		nbr /= 10;
	}
	return (str);
}
