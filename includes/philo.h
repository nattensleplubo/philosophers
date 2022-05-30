/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngobert <ngobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 14:10:58 by ngobert           #+#    #+#             */
/*   Updated: 2022/05/30 13:39:36 by ngobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H

# define PHILO_H

/*	DEFINES	*/
#define TRUE 1
#define FALSE 0

/*	LIBRAIRIES	*/
#include <pthread.h>
#include <stdio.h>
#include <limits.h>
#include <unistd.h>
#include <stdlib.h>
#include "colors.h"

/*	PROTOTYPES	*/

/*	checker	*/
int	args_are_correct(int argc, char **argv);

/*	errors	*/
void	print_right_syntax(void);
void	print_limits_error(void);

/*	libft	*/
long	ft_atol(const char *str);
int		ft_strlen(char *str);

#endif