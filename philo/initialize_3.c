/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorpela <mkorpela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 14:21:15 by mkorpela          #+#    #+#             */
/*   Updated: 2024/07/25 07:51:42 by mkorpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	init_end_flag_lock(t_data *data)
{
	pthread_mutex_t	*end_flag_lock;

	end_flag_lock = malloc(sizeof(pthread_mutex_t));
	if (end_flag_lock == NULL)
	{
		ft_putstr_fd("Malloc fail: end_flag_lock\n", 2);
		destroy_and_free_all(data, NULL);
		return (1);
	}
	if (pthread_mutex_init(end_flag_lock, NULL) != 0)
	{
		ft_putstr_fd("pthread_mutex_init failure: end_flag_lock\n", 2);
		free(end_flag_lock);
		destroy_and_free_all(data, NULL);
		return (1);
	}
	data->end_flag_lock = end_flag_lock;
	return (0);
}

static int	init_printer_lock(t_data *data)
{
	pthread_mutex_t	*printer;

	printer = malloc(sizeof(pthread_mutex_t));
	if (printer == NULL)
	{
		ft_putstr_fd("Malloc failure: printer\n", 2);
		return (1);
	}
	if (pthread_mutex_init(printer, NULL) != 0)
	{
		ft_putstr_fd("pthread_mutex_init failure: printer\n", 2);
		free(printer);
		return (1);
	}
	data->printer = printer;
	return (0);
}

int	init_global_locks(t_data *data)
{
	if (init_printer_lock(data) == 1)
	{
		return (1);
	}
	if (init_end_flag_lock(data) == 1)
	{
		return (1);
	}
	return (0);
}
