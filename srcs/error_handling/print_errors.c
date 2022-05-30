/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngobert <ngobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 21:32:33 by ngobert           #+#    #+#             */
/*   Updated: 2022/05/30 10:52:47 by ngobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_putstr(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		write(1, &str[i], 1);
}

void	print_right_syntax(void)
{
	ft_putstr(BRED"\nPlease use : [num_of_philos] [time_to_die] [time_to_eat] \
[time_to_sleep]\n\n"CRESET);
}
