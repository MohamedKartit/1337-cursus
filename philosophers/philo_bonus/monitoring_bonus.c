/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkartit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 17:30:26 by mkartit           #+#    #+#             */
/*   Updated: 2024/10/01 17:30:27 by mkartit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*monitor(void *data)
{
	t_philo	*philo;
	t_time	*time;
	int		i;

	philo = (t_philo *)data;
	time = philo->vars->time_infs;
	i = 0;
	while (1)
	{
		if (philo->eat == 0 && (get_time()
				- philo->last_meal) >= (size_t)time->time_to_die)
		{
			printer(philo, DEAD);
			while (i < philo->vars->num_of_philos)
			{
				sem_post(philo->vars->death);
				i += 1;
			}
		}
		usleep(100);
	}
	return (NULL);
}
