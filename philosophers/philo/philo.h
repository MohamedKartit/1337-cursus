/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkartit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 21:36:45 by mkartit           #+#    #+#             */
/*   Updated: 2024/10/01 18:02:51 by mkartit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <limits.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>
# include <stdatomic.h>

# define EAT "\033[0;32mis eating\n\033[0m"
# define SLEEP "\033[0;34mis sleeping\n\033[0m"
# define THINK "\033[0;33mis thinking\n\033[0m"
# define FORK "has taken a fork\n"
# define DEAD "\033[0;31mdied\n\033[0m"

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
	int				id;
	atomic_int		times_ate;
	atomic_size_t	last_meal;
	pthread_t		id_thread;
	pthread_mutex_t	fork;
	struct s_philo	*r_philo;
	struct s_philo	*l_philo;
	struct s_vars	*data;
}					t_philo;

typedef struct s_vars
{
	pthread_mutex_t	tracker;
	pthread_mutex_t	print_mutex;
	t_time			*time_infs;
	long int		num_of_meals;
	long int		num_of_philos;
	long int		g_time;
	atomic_int		is_death;
	atomic_int		all_ate;
	t_philo			*philos;
}					t_vars;

/*==================== init args =====================*/
int					check_args(t_vars *data, t_time *time, char **av, int ac);
int					error_printer(int error);
long int			ft_atoi(const char *nptr);
int					ft_init(t_vars *data, t_time *time);
int					init_data(t_vars *data, t_time *time);
int					init_mutexes(t_vars *data);
int					init_philos(t_vars *data, t_philo *philos);

/*==================== utils =====================*/
long int			get_time(void);
void				m_sleep(long int time, t_vars *data);
void				message(t_philo *philo, char *str);
int					len(char *str);

/*==================== simulation =====================*/
int					start_simulation(t_vars *data);
int					wait_simulation(t_vars *data);
void				monitor(t_vars *data);

/*================== routine ========================*/
void				*philo_life(void *data);
void				eating(t_philo *philo);

#endif
