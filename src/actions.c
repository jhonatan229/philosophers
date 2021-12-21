/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 02:06:25 by coder             #+#    #+#             */
/*   Updated: 2021/12/21 23:08:36 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	drop_fork(t_thread_philo *philo)
{
	pthread_mutex_unlock(&philo->main_struct->forks[philo->left_hand]);
	pthread_mutex_unlock(&philo->main_struct->forks[philo->right_hand]);
	usleep(100);
}

int	get_fork(t_thread_philo *philo)
{
	if (verify_time(philo))
		return (1);
	if (pthread_mutex_lock(&philo->main_struct->forks[philo->right_hand]) == 0)
	{
		if (verify_time(philo))
		{
			drop_fork(philo);
			return (1);
		}
		print_line(philo, GET_FORK);
	}
	if (pthread_mutex_lock(&philo->main_struct->forks[philo->left_hand]) == 0)
	{
		if (verify_time(philo))
		{
			drop_fork(philo);
			return (1);
		}
		print_line(philo, GET_FORK);
	}
	return (0);
}

int	try_eat(t_thread_philo *philo)
{
	if (get_fork(philo))
		return (1);
	if (verify_time(philo))
		return (1);
	philo->time = ft_time();
	print_line(philo, EATING);
	while (ft_time() - philo->time < philo->main_struct->t_eat)
	{
		if (verify_time(philo))
			return (1);
		usleep(1 * 1000);
	}
	philo->num_eats--;
	drop_fork(philo);
	if (verify_time(philo))
		return (1);
	return (0);
}

int	try_sleep(t_thread_philo *philo)
{
	long int	t;

	if (verify_time(philo))
		return (1);
	print_line(philo, SLEAPING);
	t = ft_time();
	while (ft_time() - t < philo->main_struct->t_sleep)
	{
		if (verify_time(philo))
			return (1);
		usleep(1 * 1000);
	}
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
