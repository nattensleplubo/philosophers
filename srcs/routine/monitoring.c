/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngobert <ngobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 14:09:35 by ngobert           #+#    #+#             */
/*   Updated: 2022/09/15 16:01:10 by ngobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_last_meal(t_philo *philo)
{
	if (get_time() - philo->general->starting_time > philo->time_to_die)
	{
		philo->general->is_dead = 1;
		printf(BRED"%d %d died\n"CRESET, get_time()
			- philo->general->starting_time, philo->id);
		return (0);
	}
	else
		return (1);
}

int	meals_are_over(t_philo *philo)
{
	if (philo->general->number_of_meals != -1)
	{
		if (philo->general->number_of_meals <= philo->number_of_meals)
		{
			philo->general->is_dead = 1;
			return (SUCCESS);
		}
	}
	return (0);
}

int	check_if_one_is_dead(t_general *general)
{
	int	i;

	i = 0;
	while (i < general->number_of_philo)
	{
		if (check_last_meal(&general->philos[i]) == ERROR || meals_are_over(&general->philos[general->number_of_philo - 1]) == SUCCESS)
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
			usleep(100);
			return (pthread_mutex_unlock(&data->mutex), NULL);
		}
		pthread_mutex_unlock(&data->mutex);
		usleep(200);
	}
}
