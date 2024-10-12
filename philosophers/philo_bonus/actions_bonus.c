/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkartit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 17:30:08 by mkartit           #+#    #+#             */
/*   Updated: 2024/10/01 17:30:09 by mkartit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	take_fork(t_philo *philo)
{
	sem_wait(philo->vars->forks);
	printer(philo, FORK);
	sem_post(philo->vars->printer);
	sem_wait(philo->vars->forks);
	printer(philo, FORK);
	sem_post(philo->vars->printer);
	return (1);
}

void	release_fork(t_philo *philo)
{
	sem_post(philo->vars->forks);
	sem_post(philo->vars->forks);
}

int	eating(t_philo *philo)
{
	philo->last_meal = get_time();
	printer(philo, EAT);
	philo->meals++;
	if (philo->meals == philo->vars->num_of_meals)
		sem_post(philo->vars->death);
	philo->eat = 1;
	sem_post(philo->vars->printer);
	m_sleep(philo->vars->time_infs->time_to_eat);
	release_fork(philo);
	philo->eat = 0;
	return (1);
}

int	sleeping(t_philo *philo)
{
	printer(philo, SLEEP);
	sem_post(philo->vars->printer);
	m_sleep(philo->vars->time_infs->time_to_sleep);
	return (1);
}

int	thinking(t_philo *philo)
{
	printer(philo, THINK);
	sem_post(philo->vars->printer);
	usleep(500);
	return (1);
}
