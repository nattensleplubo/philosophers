/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_t_general.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngobert <ngobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 10:43:50 by ngobert           #+#    #+#             */
/*   Updated: 2022/06/03 13:35:16 by ngobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_mutex(t_general *general)
{
	int	i;

	i = -1;
	general->fork_mutex
		= malloc(sizeof(pthread_mutex_t) * general->number_of_philo);
	if (!general->fork_mutex)
		return (FAILURE);
	while (++i < general->number_of_philo)
		pthread_mutex_init(&general->fork_mutex[i], NULL);
	pthread_mutex_init(&general->mutex, NULL);
	return (SUCCESS);
}

int	init_philos(t_general *general)
{
	int	i;

	i = 0;
	general->philos = malloc(sizeof(t_philo) * general->number_of_philo);
	if (!general->philos)
		return (FAILURE);
	while (i < general->number_of_philo)
	{
		general->philos[i].id = i + 1;
		general->philos[i].left_fork = &general->fork_mutex[i];
		general->philos[i].right_fork = &general->fork_mutex[(i + 1)
			% general->number_of_philo];
		general->philos[i].general = general;
		general->philos[i].time_to_die = general->time_to_die;
		general->philos[i].time_to_eat = general->time_to_eat;
		general->philos[i].time_to_sleep = general->time_to_sleep;
		general->philos[i].last_meal = 0;
		general->philos[i].is_eating = 0;
		general->philos[i].number_of_meals = 0;
		i++;
	}
	return (SUCCESS);
}

int	init_structs(t_general *general, char **argv)
{
	general->number_of_philo = ft_atoi(argv[1]);
	general->time_to_die = ft_atoi(argv[2]);
	general->time_to_eat = ft_atoi(argv[3]);
	general->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		general->number_of_meals = ft_atoi(argv[5]);
	else
		general->number_of_meals = -1;
	general->is_dead = 0;
	if (init_mutex(general) == FAILURE)
		return (FAILURE);
	if (init_philos(general) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}
