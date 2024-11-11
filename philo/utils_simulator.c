/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_simulator.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorpela <mkorpela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 16:39:16 by mkorpela          #+#    #+#             */
/*   Updated: 2024/07/25 06:48:21 by mkorpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	get_timestamp(long start_time)
{
	struct timeval	now_time;

	gettimeofday(&now_time, NULL);
	return (now_time.tv_sec * 1000 + now_time.tv_usec / 1000 - start_time);
}

long	get_absolute_timestamp(void)
{
	struct timeval	now_time;

	gettimeofday(&now_time, NULL);
	return (now_time.tv_sec * 1000 + now_time.tv_usec / 1000);
}

int	print_action(t_philo *philo, char *str)
{
	if (check_if_simulator_over(philo) == 1)
	{
		return (1);
	}
	pthread_mutex_lock(philo->printer);
	printf("%ld", get_timestamp(philo->data->start_time));
	printf(" %d", philo->philo_id);
	printf(" %s\n", str);
	pthread_mutex_unlock(philo->printer);
	return (0);
}

int	ft_usleep(t_philo *philo, int time)
{
	long	start;

	start = get_absolute_timestamp();
	while (get_absolute_timestamp() - start < time)
	{
		if (check_if_simulator_over(philo) == 1)
		{
			return (1);
		}
		usleep(500);
	}
	return (0);
}

int	check_if_simulator_over(t_philo *philo)
{
	bool	end_simulation;

	end_simulation = false;
	pthread_mutex_lock(philo->end_flag);
	if (philo->data->end_flag == true)
	{
		end_simulation = true;
	}
	pthread_mutex_unlock(philo->end_flag);
	if (end_simulation == true)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
