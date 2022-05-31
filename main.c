/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngobert <ngobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 14:04:26 by ngobert           #+#    #+#             */
/*   Updated: 2022/05/31 10:59:46 by ngobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*

	pthread_create && join return 0 si le thread s'est bien crée

*/

int	main(int argc, char **argv)
{
	// t_general	general;

	if (args_are_correct(argc, argv))
	{
		if (init_structs(&general, argv))
		{
			begin_routine();
		}
	}
}

// int	main(void)
// {
// 	char	*s1 = ft_itoa(INT_MAX);
// 	char	*s2 = ft_itoa(INT_MIN);
// 	printf("\nLen de %s : %d\n\n", s1, ft_strlen(s1));
// 	printf("Len de %s : %d\n\n", s2, ft_strlen(s2));
// }