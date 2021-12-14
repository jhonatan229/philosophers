/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 00:52:33 by coder             #+#    #+#             */
/*   Updated: 2021/12/14 01:03:01 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	start_struct(t_philo *philo)
{
	int count;

	count = -1;
	philo->thread_ph = ft_calloc(philo->num_philos, sizeof(t_thread_philo));
	philo->forks = malloc(sizeof(pthread_mutex_t) * philo->num_philos);
	philo->status = ALIVE;
	pthread_mutex_init(&philo->print, NULL);
	while(++count < philo->num_philos)
	{
		pthread_mutex_init(&philo->forks[count], NULL);
		philo->thread_ph[count].num_eats = philo->count_eat;
		if (philo->count_eat == 0)
			philo->thread_ph[count].num_eats = -1;
		philo->thread_ph[count].status = ACTIVE;
		philo->thread_ph[count].num = count;
		philo->thread_ph[count].left_hand = count;
		philo->thread_ph[count].right_hand = count + 1;
		philo->thread_ph[count].main_struct = philo;
		if (count == philo->num_philos - 1)
		 	philo->thread_ph[count].right_hand = 0;
	}
	philo->t_start = ft_time();
}

int	set_args_to_struct(t_philo *philo, char **argv)
{
	if (ft_isdigit(argv[1]) == 0 && argv[1])
		philo->num_philos = ft_atoi(argv[1]);
	if (ft_isdigit(argv[2]) == 0 && argv[2])
		philo->t_die = ft_atoi(argv[2]);
	if (ft_isdigit(argv[3]) == 0 && argv[3])
		philo->t_eat = ft_atoi(argv[3]);
	if (ft_isdigit(argv[4]) == 0 && argv[4])
		philo->t_sleep = ft_atoi(argv[4]);
	if (ft_isdigit(argv[5]) == 0 && argv[5])
		philo->count_eat = ft_atoi(argv[5]);
	
	philo->philo_needs_eat = philo->num_philos;
	return (0);
}

void	creating_philos(t_philo *philo)
{
	int count;
	
	count = 0;
	while (count < philo->num_philos)
	{
		pthread_create(&philo->thread_ph[count].thread, NULL, action, (void *)&philo->thread_ph[count]);
		philo->t_start = ft_time();
		count++;
	}
}