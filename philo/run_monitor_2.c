/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_monitor_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorpela <mkorpela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 06:33:29 by mkorpela          #+#    #+#             */
/*   Updated: 2024/07/25 07:07:22 by mkorpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	is_everybody_satisfied(t_philo **philos, int num_of_philos_full)
{
	bool	all_philos_full;

	if (num_of_philos_full == (*philos)->data->num_of_philos)
	{
		all_philos_full = true;
	}
	else
	{
		all_philos_full = false;
	}
	return (all_philos_full);
}

bool	are_all_philos_full(t_philo **philos)
{
	int		i;
	int		num_of_philos_full;
	bool	all_philos_full;

	i = 0;
	num_of_philos_full = 0;
	while (i < (*philos)->data->num_of_philos)
	{
		pthread_mutex_lock((*philos)[i].meals_eaten_lock);
		if ((*philos)[i].meals_eaten >= (*philos)->data->num_of_meals)
		{
			pthread_mutex_unlock((*philos)[i].meals_eaten_lock);
			num_of_philos_full++;
		}
		else
		{
			pthread_mutex_unlock((*philos)[i].meals_eaten_lock);
			break ;
		}
		i++;
	}
	all_philos_full = is_everybody_satisfied(philos, num_of_philos_full);
	return (all_philos_full);
}
