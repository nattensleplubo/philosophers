/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngobert <ngobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 13:55:25 by ngobert           #+#    #+#             */
/*   Updated: 2022/09/15 14:45:17 by ngobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_len(int n)
{
	int	i;

	i = (n < 0);
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char			*dest;
	int				i;
	unsigned int	cpy;

	i = ft_len(n) - 1;
	dest = malloc(sizeof(char) * i + 2);
	dest[i + 1] = '\0';
	if (!dest)
		return (NULL);
	if (n < 0)
		dest[0] = '-';
	cpy = n * (1 - (2 * (n < 0)));
	while (i >= (n < 0))
	{
		dest[i] = (cpy % 10) + 48;
		cpy /= 10;
		i--;
	}
	return (dest);
}
