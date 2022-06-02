/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_death.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngobert <ngobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 10:59:08 by ngobert           #+#    #+#             */
/*   Updated: 2022/06/02 11:02:32 by ngobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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