/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngobert <ngobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 14:26:09 by ngobert           #+#    #+#             */
/*   Updated: 2022/05/31 15:40:46 by ngobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philo_routine(void *arg)
{
	int	*i;

	i = (int *)arg;
	int j = *i;
	printf("Hello from thread %d\n", j);
	return (arg);
}

void	begin_routine(t_general *data)
{
	int	i;
	
	i = 0;
	while (i < data->number_of_philo)
	{
		pthread_create(&data->philos[i].thread_id, NULL, &philo_routine, (void *)&data->philos[i].id);
		i++;
	}
	i = 0;
	while (i < data->number_of_philo)
	{
		pthread_join(data->philos[i].thread_id, NULL);
		i++;
	}
}