/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngobert <ngobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 14:10:58 by ngobert           #+#    #+#             */
/*   Updated: 2022/06/17 13:21:36 by ngobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H

# define PHILO_H

/*//! DEFINES		*/
# define TRUE 1
# define SUCCESS 1
# define FALSE 0
# define ERROR 0
# define FAILURE 0

/*//! LIBRAIRIES	*/
# include <pthread.h>
# include <stdio.h>
# include <limits.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include "colors.h"

/*//! STRUCTURES	*/
typedef struct s_philo
{
	int					id;
	int					last_meal;
	int					is_eating;
	int					time_to_die;
	int					time_to_sleep;
	int					time_to_eat;
	int					number_of_meals;

	pthread_t			thread_id;

	struct s_general	*general;

	pthread_mutex_t		*left_fork;
	pthread_mutex_t		*right_fork;
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
	pthread_mutex_t	*fork_mutex;
	pthread_mutex_t	mutex;
}	t_general;

/*//! PROTOTYPES	*/

/*//? checker		*/
int		args_are_correct(int argc, char **argv);

/*//? errors		*/
void	print_right_syntax(void);
void	print_limits_error(void);

/*//? libft			*/
long	ft_atol(const char *str);
int		ft_strlen(char *str);
char	*ft_itoa(int n);
int		ft_atoi(const char *str);

/*//? strucure initialization	*/
int		init_structs(t_general *general, char **argv);

/*//? routine		*/
void	begin_routine(t_general *data);
void	*begin_monitoring(void *arg);
void	join_threads(t_general *data);

/*//? check_death	*/
int		a_philo_is_dead(t_philo *philo);

/*//? actions		*/
int		philo_takes_forks(t_philo *philo);
void	philo_is_eating(t_philo *philo);
void	philo_is_thinking(t_philo *philo);
void	philo_is_sleeping(t_philo *philo);

/*//? utils			*/
int		get_time(void);
void	print_message(char *str, t_philo *philo);
void	ft_sleep(int time, t_philo *philo);

#endif
