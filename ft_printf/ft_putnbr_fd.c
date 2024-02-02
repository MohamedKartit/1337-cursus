/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkartit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 13:16:39 by mkartit           #+#    #+#             */
/*   Updated: 2023/11/04 13:16:40 by mkartit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	nbr_printer(int n, int fd)
{
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n *= -1;
	}
	if (n > 9)
		nbr_printer(n / 10, fd);
	ft_putchar_fd((n % 10) + 48, fd);
}

int	ft_putnbr_fd(int n, int fd)
{
	int			counter;
	long int	nbr;

	counter = 0;
	nbr = n;
	nbr_printer(n, fd);
	if (nbr == 0)
		return (1);
	if (nbr < 0)
	{
		nbr *= -1;
		counter++;
	}
	while (nbr > 0)
	{
		nbr /= 10;
		counter++;
	}
	return (counter);
}
