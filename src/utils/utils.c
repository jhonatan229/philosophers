/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 23:30:36 by coder             #+#    #+#             */
/*   Updated: 2021/12/15 19:55:38 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long int	ft_time(void)
{
	long int		milliseconds;
	struct timeval	time;

	gettimeofday(&time, NULL);
	milliseconds = time.tv_sec * 1000 + time.tv_usec / 1000;
	return (milliseconds);
}

int	verify_time(t_thread_philo *philo)
{
	if (philo->main_struct->status == DEAD)
		return (1);
	if (philo->num_eats == 0 && philo->status == ACTIVE)
	{
		philo->status = INATIVE;
		philo->main_struct->philo_needs_eat--;
		return (1);
	}
	if (ft_time() - philo->time >= philo->main_struct->t_die
		&& philo->status == ACTIVE)
	{
		philo->main_struct->status = DEAD;
		drop_fork(philo);
		print_line(philo, DEAD);
		return (1);
	}
	return (0);
}

void	print_line(t_thread_philo *philo, int status)
{
	long int	t;

	pthread_mutex_lock(&philo->main_struct->print);
	t = ft_time() - philo->main_struct->t_start;
	if (status == EATING)
		printf("%lu %i is eating\n", t, philo->num + 1);
	else if (status == SLEAPING)
		printf("%lu %i is sleeping\n", t, philo->num + 1);
	else if (status == THINKING)
		printf("%lu %i is thinking\n", t, philo->num + 1);
	else if (status == GET_FORK)
		printf("%lu %i has taken a fork\n", t, philo->num + 1);
	else if (status == DEAD)
		printf("%lu %i died\n", t, philo->num + 1);
	pthread_mutex_unlock(&philo->main_struct->print);
}

void	free_all(t_philo *philo)
{
	int	count;

	count = 0;
	pthread_mutex_destroy(&philo->print);
	while (count < philo->num_philos)
	{
		pthread_mutex_destroy(&philo->forks[count]);
		count++;
	}
	if (philo->forks)
		free(philo->forks);
	if (philo->thread_ph)
		free(philo->thread_ph);
}
