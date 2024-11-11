/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_and_free_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorpela <mkorpela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 14:39:05 by mkorpela          #+#    #+#             */
/*   Updated: 2024/07/25 06:59:18 by mkorpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	destroy_array_of_locks(t_data *data, pthread_mutex_t *locks)
{
	int	i;

	i = 0;
	while (i < data->num_of_philos)
	{
		if (pthread_mutex_destroy(&locks[i]) != 0)
		{
			return (1);
		}
		i++;
	}
	locks = NULL;
	return (0);
}

static void	destroy_and_free_a_single_lock(pthread_mutex_t *lock)
{
	if (pthread_mutex_destroy(lock) != 0)
	{
		ft_putstr_fd("Failed to destroy lock\n", 2);
	}
	free(lock);
	lock = NULL;
}

static void	destroy_and_free_array_of_locks(t_data *data, pthread_mutex_t *lock)
{
	if (destroy_array_of_locks(data, lock) == 1)
	{
		ft_putstr_fd("Failed to destroy lock(s)\n", 2);
	}
	free(data->forks);
	data->forks = NULL;
}

void	destroy_and_free_all(t_data *data, t_philo **philos)
{
	if (data->end_flag_lock != NULL)
	{
		destroy_and_free_a_single_lock(data -> end_flag_lock);
	}
	if (data->printer != NULL)
	{
		destroy_and_free_a_single_lock(data -> printer);
	}
	if (data -> forks != NULL)
	{
		destroy_and_free_array_of_locks(data, data -> forks);
	}
	if (data -> meals_total_lock != NULL)
	{
		destroy_and_free_array_of_locks(data, data -> meals_total_lock);
	}
	if (data -> meals_time_lock != NULL)
	{
		destroy_and_free_array_of_locks(data, data -> meals_time_lock);
	}
	if (philos != NULL)
	{
		free((*philos));
	}
}

void	free_memory_resources(t_philo **philos)
{
	destroy_and_free_all((*philos)->data, philos);
}
