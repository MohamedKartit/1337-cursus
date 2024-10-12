/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkartit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 17:30:03 by mkartit           #+#    #+#             */
/*   Updated: 2024/10/01 17:30:05 by mkartit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <fcntl.h>
# include <limits.h>
# include <pthread.h>
# include <semaphore.h>
# include <signal.h>
# include <stdatomic.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <sys/wait.h>
# include <unistd.h>

# define EAT "\033[0;32mis eating\033[0m\n"
# define SLEEP "\033[0;34mis sleeping\033[0m\n"
# define THINK "\033[0;33mis thinking\033[0m\n"
# define FORK "has taken a fork\n"
# define DEAD "\033[0;31mdied\033[0m\n"

# define ERROR "Error: Invalid number of arguments. \n<number of philos>\
 <time to die> <time to eat> <time to sleep> [optionel: <number of meals>]\n"

enum				e_error
{
	N_PHILOS = 1,
	T_DIE = 2,
	T_EAT = 3,
	T_SLEEP = 4,
	N_MEALS = 5,
	NONE = 6,
};

typedef struct s_time
{
	long int		time_to_die;
	long int		time_to_eat;
	long int		time_to_sleep;
}					t_time;

typedef struct s_philo
{
	int				pid;
	int				id;
	int				meals;
	atomic_int		eat;
	atomic_size_t	last_meal;
	struct s_vars	*vars;
}					t_philo;

typedef struct s_vars
{
	t_time			*time_infs;
	t_philo			*philos;
	sem_t			*forks;
	sem_t			*printer;
	sem_t			*death;
	long int		g_time;
	long int		num_of_philos;
	long int		num_of_meals;
}					t_vars;

/*=================== init args ====================*/
int					check_args(t_vars *data, t_time *time, char **av, int ac);
int					init_data(t_vars *data, t_time *time);
int					init_semaphores(t_vars *data);
int					init_philos(t_vars *data);

/*=================== utils ====================*/
long int			ft_atoi(const char *nptr);
long int			get_time(void);
void				printer(t_philo *philo, char *msg);
void				m_sleep(long int time);

/*================== simulation ================*/
void				start_simulation(t_vars *data);
void				exit_simulation(t_vars *vars);
void				*philo_life(void *data);
void				*monitor(void *data);

/*================== actions ===================*/
void				release_fork(t_philo *philo);
int					take_fork(t_philo *philo);
int					eating(t_philo *philo);
int					thinking(t_philo *philo);
int					sleeping(t_philo *philo);

#endif
