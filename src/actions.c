/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 02:06:25 by coder             #+#    #+#             */
/*   Updated: 2021/12/14 00:15:32 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	drop_fork(t_thread_philo *philo)
{
	if (pthread_mutex_unlock(&philo->main_struct->forks[philo->left_hand]) == 0)
		print_line(philo, DROP_FORK);
	if (pthread_mutex_unlock(&philo->main_struct->forks[philo->right_hand]) == 0)
		print_line(philo, DROP_FORK);
}

int	get_fork(t_thread_philo *philo)
{
	if (philo->main_struct->status == DEAD)
		return (1);
	if(pthread_mutex_lock(&philo->main_struct->forks[philo->left_hand]) == 0)
		print_line(philo, GET_FORK);
	if (philo->main_struct->status == DEAD)
	{
		drop_fork(philo);
		return (1);
	}
	if (pthread_mutex_lock(&philo->main_struct->forks[philo->right_hand]) == 0)
		print_line(philo, GET_FORK);
	return (0);
}

int	try_eat(t_thread_philo *philo)
{
	if(get_fork(philo))
		return (1);
	if (verify_time(philo))
		return (1);
	print_line(philo, EATING);
	usleep(philo->main_struct->t_eat * 1000);
	philo->time = ft_time();
	philo->num_eats--;
	drop_fork(philo);
	if (verify_time(philo))
		return (1);
	return (0);
}

int	try_sleep(t_thread_philo *philo)
{
	if (verify_time(philo))
		return (1);
	print_line(philo, SLEAPING);
	usleep(philo->main_struct->t_sleep * 1000);
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