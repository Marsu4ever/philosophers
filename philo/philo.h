/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorpela <mkorpela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 15:19:34 by mkorpela          #+#    #+#             */
/*   Updated: 2024/07/25 07:12:10 by mkorpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_data
{
	int					num_of_philos;
	int					die_time;
	int					eat_time;
	int					sleep_time;
	int					num_of_meals;
	long				start_time;
	bool				end_flag;
	pthread_mutex_t		*end_flag_lock;
	pthread_mutex_t		*forks;
	pthread_mutex_t		*meals_total_lock;
	pthread_mutex_t		*meals_time_lock;
	pthread_mutex_t		*printer;	
}	t_data;

typedef struct s_philo
{
	int					philo_id;
	pthread_t			philo_thread;	
	pthread_mutex_t		*left_fork;
	pthread_mutex_t		*right_fork;
	long				last_ate;
	pthread_mutex_t		*last_ate_lock;	
	int					meals_eaten;
	pthread_mutex_t		*meals_eaten_lock;
	pthread_mutex_t		*printer;
	pthread_mutex_t		*end_flag;
	t_data				*data;
}	t_philo;

bool	are_all_philos_full(t_philo **philos);
int		check_arguments(int argc, char **argv);
int		check_if_simulator_over(t_philo *philo);
void	destroy_and_free_all(t_data *data, t_philo **philos);
int		eat(t_philo *philo);
void	free_memory_resources(t_philo **philos);
void	ft_putstr_fd(char *s, int fd);
int		ft_usleep(t_philo *philo, int time);
long	get_absolute_timestamp(void);
long	get_timestamp(long start_time);
int		init_global_locks(t_data *data);
int		init_locks(t_data *data);
int		init_threads_and_simulation(t_philo	**philos);
int		initialize(t_data *data, t_philo **philos, int argc, char **argv);
void	*philo_simulator(void *philos);
int		print_action(t_philo *philo, char *str);
void	run_monitor(t_philo **philos);
bool	value_is_not_greater_than_int_max(char **argv);

#endif