/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkartit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 21:36:29 by mkartit           #+#    #+#             */
/*   Updated: 2024/09/24 21:36:30 by mkartit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	m_sleep(long int time, t_vars *data)
{
	long int	start;

	start = get_time();
	while (!(data->is_death))
	{
		if (get_time() - start >= time)
			break ;
		usleep(1000);
	}
}

void	eating(t_philo *philo)
{
	t_vars			*data;
	pthread_mutex_t	*first_fork;
	pthread_mutex_t	*second_fork;

	data = philo->data;
	first_fork = &philo->r_philo->fork;
	second_fork = &philo->fork;
	if (&philo->fork < &philo->r_philo->fork)
	{
		first_fork = &philo->fork;
		second_fork = &philo->r_philo->fork;
	}
	(pthread_mutex_lock(first_fork), message(philo, FORK));
	if (philo->data->num_of_philos == 1)
	{
		(m_sleep(data->time_infs->time_to_die, data), message(philo, DEAD));
		(pthread_mutex_unlock(first_fork), data->is_death = 1);
		return ;
	}
	(pthread_mutex_lock(second_fork), message(philo, FORK));
	(pthread_mutex_lock(&data->tracker), philo->times_ate++);
	(message(philo, EAT), philo->last_meal = get_time());
	pthread_mutex_unlock(&data->tracker);
	m_sleep(data->time_infs->time_to_eat, data);
	(pthread_mutex_unlock(first_fork), pthread_mutex_unlock(second_fork));
}
