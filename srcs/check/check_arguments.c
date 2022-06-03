/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngobert <ngobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 21:19:22 by ngobert           #+#    #+#             */
/*   Updated: 2022/06/03 13:34:45 by ngobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*

?	number_of_philosophers
?	time_to_die
?	time_to_eat
?	time_to_sleep
*	[number_of_times_each_philosopher_must_eat]

*/

int	right_amount_of_args(int argc)
{
	if (argc == 5 || argc == 6)
		return (1);
	else
		return (0);
}

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

int	all_args_are_nums(char **argv)
{
	int	i;

	i = 0;
	while (argv[++i])
	{
		if (the_string_is_numeric(argv[i]))
			;
		else
			return (FALSE);
	}
	return (TRUE);
}

int	arg_outside_limits(char *str)
{
	if (ft_atol(str) > INT_MAX || ft_atol(str) < INT_MIN)
		return (TRUE);
	return (FALSE);
}

int	no_args_outside_limits(char **argv)
{
	int	i;

	i = 0;
	while (argv[++i])
	{
		if (arg_outside_limits(argv[i]))
			return (FALSE);
	}
	return (TRUE);
}

int	args_are_correct(int argc, char **argv)
{
	if (right_amount_of_args(argc) && all_args_are_nums(argv))
	{
		if (no_args_outside_limits(argv))
			return (TRUE);
		return (print_limits_error(), FALSE);
	}
	return (print_right_syntax(), FALSE);
}
