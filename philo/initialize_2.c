/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorpela <mkorpela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 14:20:57 by mkorpela          #+#    #+#             */
/*   Updated: 2024/07/25 07:04:09 by mkorpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	destroy_incomplete_set_of_locks(pthread_mutex_t *locks, int i)
{
	i--;
	while (i >= 0)
	{
		if (pthread_mutex_destroy(&locks[i]) != 0)
		{
			ft_putstr_fd("Failed to destroy mutex\n", 2);
		}
		i--;
	}
}

static int	init_meals_total_lock(t_data *data)
{
	pthread_mutex_t	*lock;
	int				i;

	lock = malloc(sizeof(pthread_mutex_t) * data->num_of_philos);
	if (lock == NULL)
	{
		ft_putstr_fd("Malloc failure: meals_total_lock\n", 2);
		destroy_and_free_all(data, NULL);
		return (1);
	}
	i = 0;
	while (i < data->num_of_philos)
	{
		if (pthread_mutex_init(&lock[i], NULL) != 0)
		{
			ft_putstr_fd("pthread_mutex_init failure: meals_total_lock\n", 2);
			destroy_incomplete_set_of_locks(lock, i);
			free(lock);
			destroy_and_free_all(data, NULL);
			return (1);
		}
		i++;
	}
	data -> meals_total_lock = lock;
	return (0);
}

static int	init_meals_time_lock(t_data *data)
{
	pthread_mutex_t	*lock;
	int				i;

	lock = malloc(sizeof(pthread_mutex_t) * data->num_of_philos);
	if (lock == NULL)
	{
		ft_putstr_fd("Malloc failure: meals_time_lock\n", 2);
		destroy_and_free_all(data, NULL);
		return (1);
	}
	i = 0;
	while (i < data->num_of_philos)
	{
		if (pthread_mutex_init(&lock[i], NULL) != 0)
		{
			ft_putstr_fd("pthread_mutex_init failure: meals_time_lock\n", 2);
			destroy_incomplete_set_of_locks(lock, i);
			free(lock);
			destroy_and_free_all(data, NULL);
			return (1);
		}
		i++;
	}
	data -> meals_time_lock = lock;
	return (0);
}

static int	init_forks(t_data *data)
{
	pthread_mutex_t	*forks;
	int				i;

	forks = malloc(sizeof(pthread_mutex_t) * data->num_of_philos);
	if (forks == NULL)
	{
		ft_putstr_fd("Malloc failure: forks\n", 2);
		destroy_and_free_all(data, NULL);
		return (1);
	}
	i = 0;
	while (i < data->num_of_philos)
	{
		if (pthread_mutex_init(&forks[i], NULL) != 0)
		{
			ft_putstr_fd("pthread_mutex_init failure: forks\n", 2);
			destroy_incomplete_set_of_locks(forks, i);
			free(forks);
			destroy_and_free_all(data, NULL);
			return (1);
		}
		i++;
	}
	data->forks = forks;
	return (0);
}

int	init_locks(t_data *data)
{
	if (init_global_locks(data) == 1)
	{
		return (1);
	}
	if (init_forks(data) == 1)
	{
		return (1);
	}
	if (init_meals_total_lock(data) == 1)
	{
		return (1);
	}
	if (init_meals_time_lock(data) == 1)
	{
		return (1);
	}
	return (0);
}
