/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkartit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 18:50:56 by mkartit           #+#    #+#             */
/*   Updated: 2023/11/20 18:50:58 by mkartit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_convert_hexa(char *hexa, int base, unsigned int n, int fd)
{
	long int	nbr;
	int			counter;

	nbr = n;
	counter = 0;
	if (nbr >= base)
		counter += ft_convert_hexa(hexa, base, nbr / base, fd);
	counter += ft_putchar_fd(hexa[nbr % base], fd);
	return (counter);
}

int	ft_unsigned_number(unsigned int nbr, int fd)
{
	int	counter;

	counter = 0;
	if (nbr >= 10)
		counter += ft_unsigned_number(nbr / 10, fd);
	counter += ft_putchar_fd("0123456789"[nbr % 10], fd);
	return (counter);
}

int	ft_to_converter(char c, unsigned int n, int fd)
{
	int	counter;

	counter = 0;
	if (c == 'x')
		counter += ft_convert_hexa("0123456789abcdef", 16, n, fd);
	else if (c == 'X')
		counter += ft_convert_hexa("0123456789ABCDEF", 16, n, fd);
	return (counter);
}

int	ft_mem_printer(size_t n, int fd)
{
	int	counter;

	counter = 0;
	if (n == 0)
		return (counter += ft_putstr_fd("(nil)", fd));
	if (n < 16)
	{
		counter += ft_putstr_fd("0x", fd);
		counter += ft_putchar_fd("0123456789abcdef"[n % 16], fd);
	}
	else
	{
		counter += ft_mem_printer(n / 16, fd);
		counter += ft_putchar_fd("0123456789abcdef"[n % 16], fd);
	}
	return (counter);
}
