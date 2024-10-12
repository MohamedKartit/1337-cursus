/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulations.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkartit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 21:36:50 by mkartit           #+#    #+#             */
/*   Updated: 2024/10/01 18:03:11 by mkartit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	monitor(t_vars *data)
{
	int (i);
	while (!data->all_ate)
	{
		i = -1;
		while (!data->is_death && ++i < data->num_of_philos)
		{
			pthread_mutex_lock(&data->tracker);
			if (get_time()
				- data->philos[i].last_meal
				> (size_t)data->time_infs->time_to_die)
			{
				message(&data->philos[i], DEAD);
				data->is_death = 1;
			}
			(pthread_mutex_unlock(&data->tracker), usleep(100));
		}
		if (data->is_death)
			break ;
		i = 0;
		while (data->num_of_meals != -1 && i < data->num_of_philos
			&& data->philos[i].times_ate >= data->num_of_meals)
			i++;
		if (i == data->num_of_philos)
			data->all_ate = 1;
	}
}

void	message(t_philo *philo, char *str)
{
	long int	time;

	pthread_mutex_lock(&philo->data->print_mutex);
	time = get_time() - philo->data->g_time;
	if (!philo->data->is_death && !philo->data->all_ate)
		printf("%ld %d %s", time, philo->id, str);
	pthread_mutex_unlock(&philo->data->print_mutex);
}

void	*philo_life(void *ptr)
{
	t_philo	*philo;
	t_vars	*data;

	philo = (t_philo *)ptr;
	data = philo->data;
	if (philo->id % 2 == 0)
		usleep(1000);
	while (!data->is_death && !data->all_ate)
	{
		eating(philo);
		message(philo, SLEEP);
		m_sleep(data->time_infs->time_to_sleep, data);
		message(philo, THINK);
		usleep(500);
	}
	return (NULL);
}

int	start_simulation(t_vars *data)
{
	int	i;

	i = -1;
	while (++i < data->num_of_philos)
	{
		pthread_mutex_lock(&data->tracker);
		data->philos[i].last_meal = data->g_time;
		pthread_mutex_unlock(&data->tracker);
		if (pthread_create(&data->philos[i].id_thread, NULL, &philo_life,
				&data->philos[i]))
		{
			printf("Error: pthread_create\n");
			free(data->philos);
			return (1);
		}
	}
	monitor(data);
	return (0);
}

int	wait_simulation(t_vars *data)
{
	int	i;

	i = -1;
	while (++i < data->num_of_philos)
		pthread_join(data->philos[i].id_thread, NULL);
	i = -1;
	while (++i < data->num_of_philos)
		pthread_mutex_destroy(&data->philos[i].fork);
	pthread_mutex_destroy(&data->print_mutex);
	pthread_mutex_destroy(&data->tracker);
	free(data->philos);
	return (0);
}
