/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arguments_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorpela <mkorpela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 15:49:55 by mkorpela          #+#    #+#             */
/*   Updated: 2024/07/10 16:05:16 by mkorpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	strcmp_int_max(char *number)
{
	char	*int_max;
	int		i;
	int		j;

	int_max = "2147483647";
	i = 0;
	j = 0;
	while (number[i] != '\0' && int_max[j] != '\0')
	{
		if (number[i] - int_max[j] == 0)
		{
			i++;
			j++;
		}
		else if (number[i] - int_max[j] < 0)
		{
			i++;
			j++;
		}
		else
			return (1);
	}
	return (0);
}

static int	count_digits(char *number)
{
	int	i;
	int	digit_count;

	i = 0;
	digit_count = 0;
	while (number[i] >= '0' && number[i] <= '9')
	{
		i++;
		digit_count++;
	}
	return (digit_count);
}

static int	not_greater_than_int_max(char *number)
{
	int	digit_count;

	digit_count = count_digits(number);
	if (digit_count >= 11)
	{
		return (false);
	}
	if (digit_count == 10)
	{
		if (strcmp_int_max(number) == 1)
		{
			return (false);
		}
	}
	return (true);
}

bool	value_is_not_greater_than_int_max(char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (not_greater_than_int_max(argv[i]) == false)
		{
			ft_putstr_fd("Numbers should be less than ", 2);
			ft_putstr_fd("INT_MAX (= 2147483647).\n", 2);
			return (false);
		}
		i++;
	}
	return (true);
}
