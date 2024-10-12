/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkartit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 17:30:38 by mkartit           #+#    #+#             */
/*   Updated: 2024/10/01 17:30:39 by mkartit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

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

void	printer(t_philo *philo, char *msg)
{
	long int	time;

	sem_wait(philo->vars->printer);
	time = get_time() - philo->vars->g_time;
	printf("%ld %d %s", time, philo->id, msg);
}

void	m_sleep(long int time)
{
	long int	start;

	start = get_time();
	while (get_time() - start < time)
		usleep(100);
}

long int	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}
