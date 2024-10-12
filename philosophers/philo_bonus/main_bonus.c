/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkartit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 17:30:21 by mkartit           #+#    #+#             */
/*   Updated: 2024/10/01 17:30:22 by mkartit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	error_printer(int error)
{
	if (error == N_PHILOS)
		printf("Error: Invalid number of philosophers\n");
	else if (error == T_DIE)
		printf("Error: Invalid time to die\n");
	else if (error == T_EAT)
		printf("Error: Invalid time to eat\n");
	else if (error == T_SLEEP)
		printf("Error: Invalid time to sleep\n");
	else if (error == N_MEALS)
		printf("Error: Invalid number of meals\n");
	else if (error == 42)
		printf("%s", ERROR);
	else
		return (0);
	return (1);
}

int	ft_init(t_vars *data, t_time *time)
{
	if (init_data(data, time))
		return (0);
	if (init_semaphores(data))
	{
		if (data->philos)
			free(data->philos);
		return (0);
	}
	if (init_philos(data))
	{
		if (data->philos)
			free(data->philos);
		return (0);
	}
	return (1);
}

void	exit_simulation(t_vars *vars)
{
	int	i;

	i = 0;
	while (i < vars->num_of_philos)
	{
		sem_wait(vars->death);
		i += 1;
	}
	i = 0;
	while (i < vars->num_of_philos)
	{
		kill(vars->philos[i].pid, SIGKILL);
		i += 1;
	}
	sem_close(vars->forks);
	sem_close(vars->printer);
	sem_close(vars->death);
	free(vars->philos);
}

int	main(int ac, char **av)
{
	int		error;
	t_vars	data;
	t_time	time;

	error = check_args(&data, &time, av, ac);
	if (error)
		return (error_printer(error));
	if (!ft_init(&data, &time))
	{
		printf("Error: sem_open failed\n");
		return (1);
	}
	start_simulation(&data);
	exit_simulation(&data);
	return (0);
}
