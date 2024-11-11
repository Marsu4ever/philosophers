/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorpela <mkorpela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 08:12:23 by mkorpela          #+#    #+#             */
/*   Updated: 2024/07/25 07:12:29 by mkorpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	drop_them_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

static int	pick_up_forks(t_philo *philo)
{
	if (check_if_simulator_over(philo) == 1)
		return (1);
	pthread_mutex_lock(philo->left_fork);
	if (check_if_simulator_over(philo) == 1)
	{
		pthread_mutex_unlock(philo->left_fork);
		return (1);
	}
	if (print_action(philo, "has taken a fork") == 1)
	{
		pthread_mutex_unlock(philo->left_fork);
		return (1);
	}
	pthread_mutex_lock(philo->right_fork);
	if (check_if_simulator_over(philo) == 1)
	{
		drop_them_forks(philo);
		return (1);
	}
	if (print_action(philo, "has taken a fork") == 1)
	{
		drop_them_forks(philo);
		return (1);
	}
	return (0);
}

static void	increment_meal_count(t_philo *philo)
{
	pthread_mutex_lock(philo->meals_eaten_lock);
	philo->meals_eaten++;
	pthread_mutex_unlock(philo->meals_eaten_lock);
}

static void	update_last_ate(t_philo *philo)
{
	pthread_mutex_lock(philo->last_ate_lock);
	philo->last_ate = get_absolute_timestamp();
	pthread_mutex_unlock(philo->last_ate_lock);
}

int	eat(t_philo *philo)
{	
	if (pick_up_forks(philo) == 1)
	{
		return (1);
	}
	if (print_action(philo, "is eating") == 1)
	{
		drop_them_forks(philo);
		return (1);
	}
	update_last_ate(philo);
	if (check_if_simulator_over(philo) == 1)
	{
		drop_them_forks(philo);
		return (1);
	}
	if (ft_usleep(philo, philo->data->eat_time) == 1)
	{
		drop_them_forks(philo);
		return (1);
	}
	drop_them_forks(philo);
	increment_meal_count(philo);
	return (0);
}
