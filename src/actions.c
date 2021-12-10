/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 02:06:25 by coder             #+#    #+#             */
/*   Updated: 2021/12/10 03:44:24 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	drop_fork(t_thread_philo *philo)
{
	pthread_mutex_unlock(&philo->main_struct->forks[philo->left_hand]);
	print_line(philo, DROP_FORK);
	pthread_mutex_unlock(&philo->main_struct->forks[philo->right_hand]);
	print_line(philo, DROP_FORK);
}

int	get_fork(t_thread_philo *philo)
{
	pthread_mutex_lock(&philo->main_struct->forks[philo->left_hand]);
	print_line(philo, GET_FORK);
	pthread_mutex_lock(&philo->main_struct->forks[philo->right_hand]);
	print_line(philo, GET_FORK);
	return (1);
}

int	try_eat(t_thread_philo *philo)
{
	if (verify_time(philo))
		return (1);
	get_fork(philo);
	if (verify_time(philo))
		return (1);
	usleep(philo->main_struct->t_eat * 1000);
	if (verify_time(philo))
		return (1);
	print_line(philo, EATING);
	drop_fork(philo);
	philo->time = ft_time();
	return (0);
}

int	try_sleep(t_thread_philo *philo)
{
	if (verify_time(philo))
		return (1);
	print_line(philo, SLEAPING);
	usleep(philo->main_struct->t_eat * 1000);
	if (verify_time(philo))
		return (1);
	return (0);
}

int	try_think(t_thread_philo *philo)
{
	if (verify_time(philo))
		return (1);
	print_line(philo, THINKING);
	return (0);
}