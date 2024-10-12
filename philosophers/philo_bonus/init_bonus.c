/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkartit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 17:30:17 by mkartit           #+#    #+#             */
/*   Updated: 2024/10/01 17:30:18 by mkartit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	init_philos(t_vars *data)
{
	int	i;

	i = 0;
	while (i < data->num_of_philos)
	{
		data->philos[i].id = i + 1;
		data->philos[i].meals = 0;
		data->philos[i].eat = 0;
		data->philos[i].last_meal = 0;
		data->philos[i].vars = data;
		i += 1;
	}
	return (0);
}

int	init_semaphores(t_vars *data)
{
	sem_unlink("/philo_forks");
	sem_unlink("/philo_death");
	sem_unlink("/philo_print");
	data->forks = sem_open("/philo_forks", O_CREAT, 0644, data->num_of_philos);
	data->death = sem_open("/philo_death", O_CREAT, 0644, 0);
	data->printer = sem_open("/philo_print", O_CREAT, 0644, 1);
	if (data->forks == SEM_FAILED || data->death == SEM_FAILED
		|| data->printer == SEM_FAILED)
		return (1);
	return (0);
}

int	init_data(t_vars *data, t_time *time)
{
	data->time_infs = time;
	data->philos = malloc(sizeof(t_philo) * data->num_of_philos);
	if (!data->philos)
		return (1);
	return (0);
}
