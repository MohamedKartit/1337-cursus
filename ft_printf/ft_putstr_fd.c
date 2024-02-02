/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkartit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 13:07:24 by mkartit           #+#    #+#             */
/*   Updated: 2023/11/20 16:31:05 by mkartit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr_fd(char *s, int fd)
{
	unsigned int	l;

	if (!s)
		return (write(1, "(null)", 6));
	l = 0;
	while (s[l])
		ft_putchar_fd(s[l++], fd);
	return (l);
}
