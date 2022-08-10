/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_death.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngobert <ngobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 10:59:08 by ngobert           #+#    #+#             */
/*   Updated: 2022/08/10 19:49:55 by ngobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	finished_meal(t_philo *philo)
{
	pthread_mutex_lock(&philo->general->mutex);
	if (philo->number_of_meals != -1 && philo->number_of_meals == philo->general->number_of_meals)
	{
		pthread_mutex_unlock(&philo->general->mutex);
		return (1);
	}
	pthread_mutex_unlock(&philo->general->mutex);
	return (0);
}

int	a_philo_is_dead(t_philo *philo)
{
	pthread_mutex_lock(&philo->general->mutex);
	if (philo->general->is_dead == 1)
	{
		pthread_mutex_unlock(&philo->general->mutex);
		return (1);
	}
	pthread_mutex_unlock(&philo->general->mutex);
	return (0);
}
