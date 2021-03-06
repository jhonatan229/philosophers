/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_house.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 00:57:48 by coder             #+#    #+#             */
/*   Updated: 2021/12/22 02:13:55 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*action(void *arg)
{
	t_thread_philo	*philo;

	philo = (t_thread_philo *)arg;
	philo->time = philo->main_struct->t_start;
	if (philo->num % 2 == 0)
		usleep(2 * 1000);
	while (philo->main_struct->status != DEAD)
	{
		if (try_eat(philo))
			break ;
		if (try_sleep(philo))
			break ;
		print_line(philo, THINKING);
	}
	return (NULL);
}

void	start_dinner(t_philo *philo)
{
	int	count;

	count = 0;
	while (count < philo->num_philos)
	{
		if (pthread_join(philo->thread_ph[count].thread, NULL))
			exit(0);
		count++;
	}
}
