/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngobert <ngobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 14:26:09 by ngobert           #+#    #+#             */
/*   Updated: 2022/09/15 17:11:32 by ngobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philo_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (philo->general->is_dead == 0)
	{
		if (a_philo_is_dead(philo))
			return (0);
		philo_takes_forks(philo);
		if (a_philo_is_dead(philo))
		{
			pthread_mutex_unlock(philo->left_fork);
			pthread_mutex_unlock(philo->right_fork);
			return (0);
		}
		philo_is_eating(philo);
		if (a_philo_is_dead(philo))
			return (0);
		philo_is_sleeping(philo);
		if (a_philo_is_dead(philo))
			return (0);
		philo_is_thinking(philo);
	}
	return (0);
}

void	*solo_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	pthread_mutex_lock(philo->left_fork);
	print_message(BGRN"has taken a fork"CRESET, philo);
	pthread_mutex_unlock(philo->left_fork);
	ft_sleep(philo->general->time_to_die, philo);
	printf(BRED"%d %d died\n"CRESET, get_time()
			- philo->general->starting_time, philo->id);
	return (0);
}

void	join_threads(t_general *data)
{
	int	i;

	i = 0;
	while (i < data->number_of_philo)
	{
		pthread_join(data->philos[i].thread_id, NULL);
		i++;
	}
}

void	begin_one_philo(t_general *data)
{
	data->starting_time = get_time();
	pthread_create(&data->philos[0].thread_id,
			NULL, &solo_routine, (void *)&data->philos[0]);
	pthread_join(data->philos[0].thread_id, NULL);
}

void	begin_routine(t_general *data)
{
	int	i;

	i = 0;
	data->starting_time = get_time();
	while (i < data->number_of_philo)
	{
		pthread_create(&data->philos[i].thread_id,
			NULL, &philo_routine, (void *)&data->philos[i]);
		i++;
	}
}
