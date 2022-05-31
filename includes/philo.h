/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngobert <ngobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 14:10:58 by ngobert           #+#    #+#             */
/*   Updated: 2022/05/31 11:06:43 by ngobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H

# define PHILO_H

/*//! DEFINES		*/
#define TRUE 1
#define SUCCESS 1
#define FALSE 0
#define ERROR 0

/*//! LIBRAIRIES	*/
#include <pthread.h>
#include <stdio.h>
#include <limits.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/time.h>
#include "colors.h"

/*//! STRUCTURES	*/
typedef struct s_philo
{
	int				id;
	int				last_meal;
	int				is_eating;

	pthread_t		thread_id;

	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
}	t_philo;

typedef struct s_general
{
	int				number_of_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	
	int				number_of_meals;
	int				starting_time;
	int				is_dead;
	
	t_philo			*philos;
}	t_general;

/*//! PROTOTYPES	*/

/*//? checker	*/
int	args_are_correct(int argc, char **argv);

/*//? errors	*/
void	print_right_syntax(void);
void	print_limits_error(void);

/*//? libft		*/
long	ft_atol(const char *str);
int		ft_strlen(char *str);
char	*ft_itoa(int n);
int		ft_atoi(const char *str);

/*//? strucure initialization	*/
int	init_structs(t_general *general, char **argv);

#endif