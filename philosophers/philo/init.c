/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkartit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 21:36:34 by mkartit           #+#    #+#             */
/*   Updated: 2024/09/24 21:36:35 by mkartit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_init(t_vars *data, t_time *time)
{
	if (init_data(data, time))
		return (0);
	if (init_mutexes(data))
	{
		free(data->philos);
		return (0);
	}
	if (init_philos(data, data->philos))
	{
		free(data->philos);
		return (0);
	}
	return (1);
}

int	init_mutexes(t_vars *data)
{
	if (pthread_mutex_init(&data->print_mutex, NULL) != 0)
		return (1);
	if (pthread_mutex_init(&data->tracker, NULL) != 0)
		return (1);
	return (0);
}

int	init_philos(t_vars *data, t_philo *philos)
{
	int	i;

	i = 0;
	while (i < data->num_of_philos)
	{
		philos[i].id = i + 1;
		philos[i].times_ate = 0;
		philos[i].last_meal = data->g_time;
		philos[i].data = data;
		philos[i].r_philo = &philos[(i + 1) % data->num_of_philos];
		philos[i].l_philo = &philos[(i + data->num_of_philos - 1)
			% data->num_of_philos];
		if (pthread_mutex_init(&philos[i].fork, NULL) != 0)
			return (1);
		i++;
	}
	return (0);
}

long int	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

int	init_data(t_vars *data, t_time *time)
{
	data->g_time = get_time();
	data->is_death = 0;
	data->all_ate = 0;
	data->time_infs = time;
	data->philos = malloc(sizeof(t_philo) * data->num_of_philos);
	if (!data->philos)
		return (1);
	return (0);
}
