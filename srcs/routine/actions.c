/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngobert <ngobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 11:07:33 by ngobert           #+#    #+#             */
/*   Updated: 2022/06/21 15:09:09 by ngobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo_takes_forks(t_philo *philo)
{
	if (philo->id % 2 == 0)
		pthread_mutex_lock(philo->right_fork);
	else
		pthread_mutex_lock(philo->left_fork);
	if (!a_philo_is_dead(philo))
		print_message(BGRN"has taken a fork"CRESET, philo);
	if (philo->id % 2 == 0)
	{
		if (pthread_mutex_lock(philo->left_fork) != 0)
		{
			pthread_mutex_unlock(philo->right_fork);
			return (1);
		}
		if (!a_philo_is_dead(philo))
			print_message(BGRN"has taken a fork"CRESET, philo);
	}
	else
	{
		if (pthread_mutex_lock(philo->right_fork) != 0)
		{
			pthread_mutex_unlock(philo->left_fork);
			return (1);
		}
		if (!a_philo_is_dead(philo))
			print_message(BGRN"has taken a fork"CRESET, philo);
	}
	return (0);
}

void	philo_is_eating(t_philo *philo)
{
	print_message(BYEL"is eating"CRESET, philo);
	pthread_mutex_lock(&philo->general->mutex);
	philo->last_meal = get_time() - philo->general->starting_time;
	philo->time_to_die = philo->last_meal + philo->general->time_to_die;
	pthread_mutex_unlock(&philo->general->mutex);
	ft_sleep(philo->general->time_to_eat, philo);
	pthread_mutex_lock(&philo->general->mutex);
	if (philo->number_of_meals != -1)
		philo->number_of_meals++;
	pthread_mutex_unlock(&philo->general->mutex);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

void	philo_is_sleeping(t_philo *philo)
{
	print_message(BBLU"is sleeping"CRESET, philo);
	ft_sleep(philo->general->time_to_sleep, philo);
}

void	philo_is_thinking(t_philo *philo)
{
	print_message(BCYN"is thinking"CRESET, philo);
}
