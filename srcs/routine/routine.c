/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngobert <ngobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 14:26:09 by ngobert           #+#    #+#             */
/*   Updated: 2022/05/31 17:07:25 by ngobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philo_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (pthread_mutex_lock(philo->left_fork) == 0)
	{
		printf("%d : took a fork\n", philo->id);
		printf("%d is eating\n", philo->id);
		usleep(philo->time_to_eat);
	}
	return (arg);
}

void	begin_routine(t_general *data)
{
	int	i;
	
	i = 0;
	while (i < data->number_of_philo)
	{
		pthread_create(&data->philos[i].thread_id, NULL, &philo_routine, (void *)&data->philos[i]);
		i++;
	}
	i = 0;
	while (i < data->number_of_philo)
	{
		pthread_join(data->philos[i].thread_id, NULL);
		i++;
	}
}
