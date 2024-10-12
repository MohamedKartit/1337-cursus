/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkartit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 21:36:39 by mkartit           #+#    #+#             */
/*   Updated: 2024/09/24 21:36:40 by mkartit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_vars	data;
	t_time	time;
	int		error;

	error = check_args(&data, &time, av, ac);
	if (error)
		return (error_printer(error));
	if (!ft_init(&data, &time))
		return (1);
	if (start_simulation(&data))
	{
		free(data.philos);
		return (1);
	}
	if (wait_simulation(&data))
	{
		free(data.philos);
		return (1);
	}
	return (0);
}
