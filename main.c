/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngobert <ngobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 14:04:26 by ngobert           #+#    #+#             */
/*   Updated: 2022/09/15 17:15:45 by ngobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*

	pthread_create && join return 0 si le thread s'est bien crée

*/

int	main(int argc, char **argv)
{
	t_general	general;

	if (args_are_correct(argc, argv))
	{
		if (init_structs(&general, argv))
		{
			if (general.number_of_philo != 1)
			{
				begin_routine(&general);
				begin_monitoring(&general);
				join_threads(&general);
				free_philos(&general);
			}
			else
			{
				begin_one_philo(&general);
				free_philos(&general);
			}
		}
	}
}
