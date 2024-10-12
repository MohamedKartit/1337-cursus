/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkartit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 17:30:31 by mkartit           #+#    #+#             */
/*   Updated: 2024/10/01 17:30:32 by mkartit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*philo_life(void *data)
{
	pthread_t	t_monitor;
	t_philo		*philo;
	t_vars		*vars;

	philo = (t_philo *)data;
	vars = philo->vars;
	philo->last_meal = get_time();
	pthread_create(&t_monitor, NULL, monitor, (void *)philo);
	pthread_detach(t_monitor);
	if (philo->id % 2 == 0)
		m_sleep(vars->time_infs->time_to_eat);
	while (1)
	{
		if (!take_fork(philo))
			break ;
		if (!eating(philo))
			break ;
		if (!sleeping(philo))
			break ;
		if (!thinking(philo))
			break ;
	}
	release_fork(philo);
	return (NULL);
}

void	start_simulation(t_vars *data)
{
	int	i;

	data->g_time = get_time();
	i = 0;
	while (i < data->num_of_philos)
	{
		data->philos[i].pid = fork();
		if (data->philos[i].pid == -1)
		{
			printf("Error: fork failed\n");
			exit(1);
		}
		if (data->philos[i].pid == 0)
		{
			philo_life((void *)&data->philos[i]);
			exit(0);
		}
		i += 1;
	}
}
