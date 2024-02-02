/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkartit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 11:53:58 by mkartit           #+#    #+#             */
/*   Updated: 2023/11/20 22:18:47 by mkartit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	percent_checker(const char *s)
{
	while (*s)
	{
		if (*s != '%')
			return (0);
		s++;
	}
	return (1);
}

static int	percent_counter(const char *s)
{
	int	i;

	i = 0;
	while (*s)
	{
		if (*s == '%')
			i++;
		s++;
	}
	return (i);
}

static int	get_choices(va_list args, char s, int fd)
{
	int	counter;

	counter = 0;
	if (s == 'c')
		counter = ft_putchar_fd((char)va_arg(args, int), fd);
	else if (s == 's')
		counter = ft_putstr_fd(va_arg(args, char *), fd);
	else if (s == 'p')
		counter = ft_mem_printer((size_t)va_arg(args, void *), fd);
	else if (s == 'd')
		counter = ft_putnbr_fd(va_arg(args, int), fd);
	else if (s == 'i')
		counter = ft_putnbr_fd(va_arg(args, int), fd);
	else if (s == 'u')
		counter = ft_unsigned_number(va_arg(args, unsigned int), fd);
	else if (s == 'x')
		counter = ft_to_converter(s, va_arg(args, unsigned int), fd);
	else if (s == 'X')
		counter = ft_to_converter(s, va_arg(args, unsigned int), fd);
	else if (s == '%')
		counter = ft_putchar_fd('%', fd);
	else
		counter = ft_putchar_fd('%', fd) + ft_putchar_fd(s, fd);
	return (counter);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		counter;
	int		len;

	va_start(args, format);
	counter = 0;
	len = 0;
	if (format == NULL || (format[0] == '%' && (format[1] == '\0')))
		return (-1);
	while (format[len])
	{
		if (format[len] == '%' && format[len + 1])
		{
			len++;
			counter += get_choices(args, format[len], 1);
		}
		else
			counter += ft_putchar_fd(format[len], 1);
		len++;
	}
	if (percent_checker(format) && percent_counter(format) % 2 != 0)
		return (-1);
	va_end(args);
	return (counter);
}
