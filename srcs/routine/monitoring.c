/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngobert <ngobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 14:09:35 by ngobert           #+#    #+#             */
/*   Updated: 2022/06/17 13:37:08 by ngobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_last_meal(t_philo *philo)
{
	if (get_time() - philo->general->starting_time > philo->time_to_die)
	{
		philo->general->is_dead = 1;
		return (0);
	}
	else
		return (1);
}

int	check_if_one_is_dead(t_general *general)
{
	 int	i;

	 i = 0;
	 while (i < general->number_of_philo)
	 {
		if (check_last_meal(&general->philos[i]) == ERROR)
			return (ERROR);
		i++;
	 }
	 return (1);
}

void	*begin_monitoring(void *arg)
{
	t_general	*data;

	data = (t_general *)arg;
	while (1)
	{
		pthread_mutex_lock(&data->mutex);
		if (check_if_one_is_dead(data) == ERROR)
		{
			dprintf(2, BRED"CACA\n"CRESET);
			return (pthread_mutex_unlock(&data->mutex), NULL);
		}
		pthread_mutex_unlock(&data->mutex);
		usleep(200);
	}
}
