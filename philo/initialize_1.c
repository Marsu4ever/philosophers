/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorpela <mkorpela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 14:20:06 by mkorpela          #+#    #+#             */
/*   Updated: 2024/07/25 07:12:40 by mkorpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_atoi(char *number)
{
	int	num;
	int	i;

	num = 0;
	i = 0;
	while (number[i] != '\0')
	{
		num = num * 10 + (number[i] - 48);
		i++;
	}
	return (num);
}

static void	assign_right_fork(t_data *data, t_philo **philos, int i)
{
	if (data->num_of_philos == i + 1)
	{
		(*philos)[i].right_fork = &(data->forks[0]);
	}
	else
	{
		(*philos)[i].right_fork = &(data->forks[i + 1]);
	}
}

static int	init_philo_structs(t_data *data, t_philo **philos)
{
	int		i;

	*philos = malloc(sizeof(t_philo) * data->num_of_philos);
	if (*philos == NULL)
	{
		ft_putstr_fd("Failed to malloc array of structs: philos\n", 2);
		destroy_and_free_all(data, NULL);
		return (1);
	}
	i = 0;
	while (i < data->num_of_philos)
	{
		(*philos)[i].philo_id = i + 1;
		(*philos)[i].left_fork = &(data->forks[i]);
		assign_right_fork(data, philos, i);
		(*philos)[i].last_ate = 0;
		(*philos)[i].last_ate_lock = &(data->meals_time_lock[i]);
		(*philos)[i].meals_eaten = 0;
		(*philos)[i].meals_eaten_lock = &(data->meals_total_lock[i]);
		(*philos)[i].printer = data -> printer;
		(*philos)[i].end_flag = data -> end_flag_lock;
		(*philos)[i].data = data;
		i++;
	}
	return (0);
}

static void	init_data_struct(t_data *data, int argc, char **argv)
{
	data->num_of_philos = ft_atoi(argv[1]);
	data->die_time = ft_atoi(argv[2]);
	data->eat_time = ft_atoi(argv[3]);
	data->sleep_time = ft_atoi(argv[4]);
	if (argc == 5)
	{
		data->num_of_meals = -1;
	}
	else
	{
		data->num_of_meals = ft_atoi(argv[5]);
	}
	data->end_flag = false;
}

int	initialize(t_data *data, t_philo **philos, int argc, char **argv)
{
	init_data_struct(data, argc, argv);
	if (init_locks(data) == 1)
	{
		return (1);
	}
	if (init_philo_structs(data, philos) == 1)
	{
		return (1);
	}
	return (0);
}
