/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 23:30:36 by coder             #+#    #+#             */
/*   Updated: 2021/12/10 03:43:18 by coder            ###   ########.fr       */
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
	if (ft_time() - philo->time >= philo->main_struct->t_die)
	{
		drop_fork(philo);
		print_line(philo, DEAD);
		philo->main_struct->status = DEAD;
		return (1);
	}		
	return (0);
}

void print_line(t_thread_philo *philo, int status)
{
	long int t;
	
	pthread_mutex_lock(&philo->main_struct->print);
	t = ft_time() - philo->main_struct->t_start;
	if (status == EATING)
		printf("%lu, philo %i, eating!\n", t, philo->num);
	else if (status == SLEAPING)
		printf("%lu, philo %i, SLEAPING!\n", t, philo->num);
	else if (status == THINKING)
		printf("%lu, philo %i, THINKING!\n", t, philo->num);
	else if (status == GET_FORK)
		printf("%lu, philo %i, GET A FORK!\n", t, philo->num);
	else if (status == DROP_FORK)
		printf("%lu, philo %i, DROP A FORK!\n", t, philo->num);
	else if (status == DEAD)
		printf("%lu, philo %i, DEAD!\n", t, philo->num);
	pthread_mutex_unlock(&philo->main_struct->print);
}

void free_all(t_philo *philo)
{
	int	count;

	count = 0;
	pthread_mutex_destroy(&philo->print);
	while (count < philo->num_philos)
	{
		pthread_mutex_destroy(&philo->forks[count]);
		count++;
	}
	free(philo->forks);
	free(philo->thread_ph);
}