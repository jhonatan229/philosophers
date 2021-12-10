/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 00:42:03 by coder             #+#    #+#             */
/*   Updated: 2021/12/10 03:45:05 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void *print_hello(void *arg)
{
	t_thread_philo *philo = (t_thread_philo *)arg;
	philo->time = ft_time();
	if (philo->num % 2 == 0)
		usleep(1 * 1000);
	while (philo->main_struct->status != DEAD)
	{
		if (try_eat(philo))
			break;
		if (try_sleep(philo))
			break;
		print_line(philo, THINKING);
	}
	return NULL;
}

void	start_struct(t_philo *philo, int num_philo, long int time_eat, long int time_die)
{
	int count;

	count = 0;
	philo->thread_ph = ft_calloc(num_philo, sizeof(t_thread_philo));
	philo->forks = malloc(sizeof(pthread_mutex_t) * num_philo);
	philo->t_eat = time_eat;
	philo->t_die = time_die;
	philo->num_philos = num_philo;
	philo->status = ALIVE;
	pthread_mutex_init(&philo->print, NULL);
	while(count < num_philo)
	{
		pthread_mutex_init(&philo->forks[count], NULL);
		philo->thread_ph[count].num = count;
		philo->thread_ph[count].left_hand = count;
		philo->thread_ph[count].right_hand = count + 1;
		philo->thread_ph[count].main_struct = philo;
		if (count == num_philo - 1)
		 	philo->thread_ph[count].right_hand = 0;
		count++;
	}
	philo->t_start = ft_time();

}
int main()
{
	int count;

	count = 0;
	t_philo philo;
	memset(&philo, 0, sizeof(t_philo));
	start_struct(&philo, 3, 300, 400);
	while (count < philo.num_philos)
	{
		pthread_create(&philo.thread_ph[count].thread, NULL, print_hello, (void *)&philo.thread_ph[count]);
		count++;
	}
	count = 0;
	while(count < philo.num_philos)
	{
		printf("count: %i\n", count);
		if (pthread_join(philo.thread_ph[count].thread, NULL))
		{
			printf("finish, %i\n", count);
			exit(0);
		}
		count++;
	}
	free_all(&philo);
	printf("congrats!!\n");
	return (0);
}