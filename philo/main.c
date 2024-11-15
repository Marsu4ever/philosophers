/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorpela <mkorpela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 17:40:04 by mkorpela          #+#    #+#             */
/*   Updated: 2024/07/25 06:44:32 by mkorpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{	
	t_data	data;
	t_philo	*philos;

	data = (t_data){};
	if (check_arguments(argc, argv) == 1)
		return (1);
	if (initialize(&data, &philos, argc, argv) == 1)
		return (1);
	if (init_threads_and_simulation(&philos) == 1)
		return (1);
	free_memory_resources(&philos);
	return (0);
}
