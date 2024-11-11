/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_threads_and_simulation.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorpela <mkorpela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 15:53:10 by mkorpela          #+#    #+#             */
/*   Updated: 2024/07/25 07:09:37 by mkorpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	join_threads(t_philo **philos)
{
	int	i;

	i = 0;
	while (i < (*philos)->data->num_of_philos)
	{			
		if (pthread_join(((*philos)[i].philo_thread), NULL) != 0)
		{
			ft_putstr_fd("pthread_join failed\n", 2);
		}
		i++;
	}
}

static void	thread_creation_failed(t_philo **philos, int i)
{
	ft_putstr_fd("pthread_create failed\n", 2);
	i--;
	while (i >= 0)
	{
		if (pthread_join(((*philos)[i].philo_thread), NULL) != 0)
		{
			ft_putstr_fd("pthread_join failed\n", 2);
		}
		i--;
	}
}

static void	initialize_timestamps(t_philo **philos)
{
	int	i;

	(*philos)->data->start_time = get_absolute_timestamp();
	i = 0;
	while (i < (*philos)->data->num_of_philos)
	{
		(*philos)[i].last_ate = (*philos)->data->start_time;
		i++;
	}
}

int	init_threads_and_simulation(t_philo **philos)
{
	int	i;

	i = 0;
	initialize_timestamps(philos);
	while (i < (*philos)->data->num_of_philos)
	{
		if (pthread_create(&((*philos)[i].philo_thread), NULL,
			philo_simulator, (void *)&(*philos)[i]) != 0)
		{
			thread_creation_failed(philos, i);
			destroy_and_free_all((*philos)->data, philos);
			return (1);
		}
		i++;
	}
	run_monitor(philos);
	join_threads(philos);
	return (0);
}
