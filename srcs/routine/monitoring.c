/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngobert <ngobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 14:09:35 by ngobert           #+#    #+#             */
/*   Updated: 2022/06/07 17:03:45 by ngobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_if_one_is_dead(t_general *general)
{
	 int	i;

	 i = 0;
	 while (i < general->number_of_philo)
	 {
		if (check_last_meal(&general->philos[i]) == ERROR)
		i++;
	 }
}

void	*begin_monitoring(void *arg)
{
	t_general	*data;

	data = (t_general *)arg;
	while (1)
	{
		pthread_mutex_lock(&data->mutex);
		if (check_if_one_is_dead(data))
		{
			//quitter
		}
	}
}