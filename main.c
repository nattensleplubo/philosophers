/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngobert <ngobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 14:04:26 by ngobert           #+#    #+#             */
/*   Updated: 2022/06/02 09:53:02 by ngobert          ###   ########.fr       */
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
			begin_routine(&general);	//boucle while qui va init les philos et leur donne la routine et apres on fou le monitoring dans un thread ou dans le thread principal ?
		}
	}
}
