/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_simulator.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorpela <mkorpela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 15:43:42 by mkorpela          #+#    #+#             */
/*   Updated: 2024/07/25 07:50:59 by mkorpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	sweet_dreams(t_philo *philo)
{
	if (print_action(philo, "is sleeping") == 1)
	{
		return (1);
	}
	if (ft_usleep(philo, philo->data->sleep_time) == 1)
	{
		return (1);
	}
	return (0);
}

static int	thinking(t_philo *philo)
{
	if (print_action(philo, "is thinking") == 1)
	{
		return (1);
	}
	return (0);
}

static void	lonely_philo(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	print_action(philo, "has taken a fork");
	pthread_mutex_unlock(philo->left_fork);
	while (1)
	{
		if (check_if_simulator_over(philo) == 1)
		{
			return ;
		}
	}
}

void	*philo_simulator(void *philos)
{
	t_philo	*philo;

	philo = (t_philo *)(philos);
	if (philo->data->num_of_philos == 1)
	{
		lonely_philo(philo);
		return (NULL);
	}
	thinking(philo);
	if (philo->philo_id % 2 == 0)
	{
		usleep(30000);
	}
	while (1)
	{
		if (eat(philo) == 1)
			break ;
		if (sweet_dreams(philo) == 1)
			break ;
		if (thinking(philo) == 1)
			break ;
	}
	return (NULL);
}
