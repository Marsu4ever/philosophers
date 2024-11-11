/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_monitor_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorpela <mkorpela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 16:34:28 by mkorpela          #+#    #+#             */
/*   Updated: 2024/07/25 07:12:52 by mkorpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	raise_the_end_flag(t_philo **philos, int i)
{
	pthread_mutex_lock((*philos)[i].end_flag);
	(*philos)[i].data->end_flag = true;
	pthread_mutex_unlock((*philos)[i].end_flag);
}

static void	death_has_occurred(t_philo **philos, int i)
{
	raise_the_end_flag(philos, i);
	pthread_mutex_lock((*philos)[i].printer);
	printf("%ld ", get_timestamp((*philos)->data->start_time));
	printf("%d died\n", (*philos)[i].philo_id);
	pthread_mutex_unlock((*philos)[i].printer);
}

static int	check_for_deaths(t_philo **philos)
{
	int	i;

	i = 0;
	while (i < (*philos)->data->num_of_philos)
	{
		pthread_mutex_lock((*philos)[i].last_ate_lock);
		if ((*philos)[i].data->die_time <
				get_absolute_timestamp() - (*philos)[i].last_ate)
		{
			pthread_mutex_unlock((*philos)[i].last_ate_lock);
			death_has_occurred(philos, i);
			return (1);
		}
		pthread_mutex_unlock((*philos)[i].last_ate_lock);
		i++;
	}
	return (0);
}

void	run_monitor(t_philo **philos)
{
	int	i;

	i = 0;
	while (1)
	{
		if (check_for_deaths(philos) == 1)
		{
			break ;
		}
		if ((*philos)->data->num_of_meals != -1)
		{
			if (are_all_philos_full(philos) == true)
			{
				raise_the_end_flag(philos, i);
				break ;
			}
		}
	}
}
