/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 02:06:25 by coder             #+#    #+#             */
/*   Updated: 2021/12/09 03:34:41 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	drop_fork(t_thread_philo *philo)
{
	if (pthread_mutex_unlock(&philo->main_struct->forks[philo->left_hand]))
		try_think(philo);
	if (pthread_mutex_unlock(&philo->main_struct->forks[philo->right_hand]))
		try_think(philo);
}

void	get_fork(t_thread_philo *philo)
{
	pthread_mutex_lock(&philo->main_struct->forks[philo->left_hand]);
	pthread_mutex_lock(&philo->main_struct->forks[philo->right_hand]);
}

int	try_eat(t_thread_philo *philo)
{
	if (verify_time(philo) > philo->main_struct->t_eat)
		return (1);
	get_fork(philo);
	print_line(philo, GET_FORK);
	if (verify_time(philo) > philo->main_struct->t_eat)
		return (1);
	print_line(philo, EATING);
	usleep(philo->main_struct->t_eat * 1000);
	drop_fork(philo);
	reset_time(philo);
	return (0);
}

int	try_sleep(t_thread_philo *philo)
{
	if (verify_time(philo) > philo->main_struct->t_eat)
		return (1);
	print_line(philo, SLEAPING);
	usleep(philo->main_struct->t_eat * 1000);
	if (verify_time(philo) > philo->main_struct->t_eat)
		return (1);
	return (0);
}

int	try_think(t_thread_philo *philo)
{
	if (verify_time(philo) > philo->main_struct->t_eat)
		return (1);
	if (philo->status == THINKING)
		return (0);
	philo->status = THINKING;
	print_line(philo, THINKING);
	return (0);
}