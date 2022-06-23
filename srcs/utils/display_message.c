/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_message.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngobert <ngobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 13:24:36 by ngobert           #+#    #+#             */
/*   Updated: 2022/06/02 13:29:10 by ngobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_message(char *str, t_philo *philo)
{
	if (!a_philo_is_dead(philo))
	{
		pthread_mutex_lock(&philo->general->mutex);
			printf("%d %d %s\n", get_time()
				- philo->general->starting_time, philo->id, str);
		pthread_mutex_unlock(&philo->general->mutex);
	}
}
