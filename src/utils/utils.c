/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 23:30:36 by coder             #+#    #+#             */
/*   Updated: 2021/12/09 03:34:10 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long int	verify_time(t_thread_philo *philo)
{
	struct timeval time;
	gettimeofday(&time, NULL);
	return (time.tv_usec * 1000) - philo->time;
}

void	reset_time(t_thread_philo *philo)
{
	struct timeval time;
	gettimeofday(&time, NULL);
	philo->time = time.tv_usec * 1000;
}

void print_line(t_thread_philo *philo, int status)
{
	pthread_mutex_lock(&philo->main_struct->print);
	if (status == EATING)
		printf("tempo, philo %i, eating!\n", philo->num);
	else if (status == SLEAPING)
		printf("tempo, philo %i, SLEAPING!\n", philo->num);
	else if (status == THINKING)
		printf("tempo, philo %i, THINKING!\n", philo->num);
	else if (status == GET_FORK)
		printf("tempo, philo %i, GET A FORK!\n", philo->num);
	pthread_mutex_unlock(&philo->main_struct->print);
}