/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkartit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 17:30:12 by mkartit           #+#    #+#             */
/*   Updated: 2024/10/01 17:30:12 by mkartit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static int	len(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

static int	is_nym(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	len_checker(char **av)
{
	if (len(av[1]) > 11 || !is_nym(av[1]))
		return (N_PHILOS);
	if (len(av[2]) > 11 || !is_nym(av[2]))
		return (T_DIE);
	if (len(av[3]) > 11 || !is_nym(av[3]))
		return (T_EAT);
	if (len(av[4]) > 11 || !is_nym(av[4]))
		return (T_SLEEP);
	return (0);
}

static int	in_checker(t_vars *data, t_time *time, int ac)
{
	if (data->num_of_philos == 0 || (ac == 6 && data->num_of_meals == 0))
		return (NONE);
	if (data->num_of_philos < 1 || data->num_of_philos > 200
		|| data->num_of_philos > INT_MAX)
		return (N_PHILOS);
	if (time->time_to_die < 60 || time->time_to_die > INT_MAX)
		return (T_DIE);
	if (time->time_to_eat < 60 || time->time_to_eat > INT_MAX)
		return (T_EAT);
	if (time->time_to_sleep < 60 || time->time_to_sleep > INT_MAX)
		return (T_SLEEP);
	if ((data->num_of_meals < 1 && ac == 6) || data->num_of_meals > INT_MAX)
		return (N_MEALS);
	return (0);
}

int	check_args(t_vars *data, t_time *time, char **av, int ac)
{
	int	r_value;

	r_value = 0;
	if (ac != 5 && ac != 6)
		return (42);
	r_value = len_checker(av);
	if (r_value)
		return (r_value);
	data->num_of_philos = ft_atoi(av[1]);
	time->time_to_die = ft_atoi(av[2]);
	time->time_to_eat = ft_atoi(av[3]);
	time->time_to_sleep = ft_atoi(av[4]);
	data->num_of_meals = -1;
	if (ac == 6)
	{
		if (len(av[5]) > 11 || !is_nym(av[5]))
			return (N_MEALS);
		data->num_of_meals = ft_atoi(av[5]);
	}
	r_value = in_checker(data, time, ac);
	return (r_value);
}
