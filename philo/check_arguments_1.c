/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arguments_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorpela <mkorpela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 15:18:44 by mkorpela          #+#    #+#             */
/*   Updated: 2024/07/25 06:54:46 by mkorpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	only_4_or_5_args(int argc)
{
	if (argc != 5 && argc != 6)
	{
		ft_putstr_fd("Pass exactly 4 or 5 arguments.\n", 2);
		ft_putstr_fd("./philo [# of philosophers] [time to die (ms)] ", 2);
		ft_putstr_fd("[time to eat (ms)] [time to sleep (ms)] ", 2);
		ft_putstr_fd("--- OPTIONAL [# of times a philosopher eats] ---\n", 2);
		return (false);
	}
	return (true);
}

static bool	only_contains_digits(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] < '0' || argv[i][j] > '9')
			{
				ft_putstr_fd("Input should only contain digits [0-9].\n", 2);
				return (false);
			}
			j++;
		}
		i++;
	}
	return (true);
}

static bool	value_is_not_zero(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j] && argv[i][j] == '0')
		{
			if (argv[i][j + 1] == '\0')
			{
				ft_putstr_fd("Numbers should be greater than Zero.\n", 2);
				return (false);
			}
			j++;
		}
		i++;
	}
	return (true);
}

int	check_arguments(int argc, char **argv)
{
	if (only_4_or_5_args(argc) == false)
		return (1);
	if (only_contains_digits(argv) == false)
		return (1);
	if (value_is_not_zero(argv) == false)
		return (1);
	if (value_is_not_greater_than_int_max(argv) == false)
		return (1);
	return (0);
}
