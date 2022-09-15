/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnumeric.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngobert <ngobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 17:20:36 by ngobert           #+#    #+#             */
/*   Updated: 2022/09/15 17:20:54 by ngobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_numeric(int c)
{
	if (c >= 48 && c <= 57)
		return (TRUE);
	else
		return (FALSE);
}

int	the_string_is_numeric(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (is_numeric(str[i]) == FALSE)
			return (FALSE);
	}
	return (TRUE);
}
