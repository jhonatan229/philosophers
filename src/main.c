/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 00:42:03 by coder             #+#    #+#             */
/*   Updated: 2021/12/09 03:42:38 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void *print_hello(void *arg)
{
	t_thread_philo *philo = (t_thread_philo *)arg;
	philo->time = philo->main_struct->t_start.tv_usec * 1000;
	if (philo->num / 2 == 0)
		usleep(1);
	while (philo->status != DEAD)
	{
		if (try_eat(philo))
			break;
		if (try_sleep(philo))
			break;
	}
	return NULL;
}

void	start_struct(t_philo *philo, int num_philo, int time_eat)
{
	int count;

	count = 0;
	philo->thread_ph = ft_calloc(sizeof(t_thread_philo), num_philo);
	philo->forks = ft_calloc(sizeof(pthread_mutex_t), num_philo);
	philo->t_eat = time_eat;
	philo->num_philos = num_philo;
	pthread_mutex_init(&philo->print, NULL);
	while(count < num_philo)
	{
		pthread_create(&philo->thread_ph[count].thread, NULL, print_hello, (void *)&philo->thread_ph[count].thread);
		pthread_mutex_init(&philo->forks[count], NULL);
		philo->thread_ph->num = count;
		philo->thread_ph->status = ALIVE;
		philo->thread_ph->left_hand = count;
		philo->thread_ph->right_hand = count + 1;
		philo->thread_ph->main_struct = philo;
		if (count == num_philo - 1)
			philo->thread_ph->right_hand = count;
		count++;
	}
	gettimeofday(&philo->t_start, NULL);
}

int main()
{
	int count;

	count = 0;
	t_philo philo;
	start_struct(&philo, 3, 30);
	
	while(count < philo.num_philos)
	{
		if (!pthread_join(philo.thread_ph[count].thread, NULL))
		{
			printf("finish\n");
			exit(0);
		}
		count++;
	}
	printf("congrats!!\n");
	// pthread_t point;
	// pthread_t point_two;
	// struct timeval start, end;
	// int a1 = 2;
	// int a2 = 4; 
	// pthread_mutex_init(&mut, NULL);
	// gettimeofday(&start, NULL);
	// 	pthread_create(&point, NULL, print_hello, (void *)&a1);
	// 	pthread_create(&point_two, NULL, print_hello, (void *)&a2);
	// 	pthread_join(point, NULL);
	// 	pthread_join(point_two, NULL);
	// 	gettimeofday(&end, NULL);
	// 	printf("start: %ld\n end: %ld\nTime taken to count to 10^5 is : %ld micro seconds\n",(start.tv_sec + start.tv_usec), (end.tv_sec + end.tv_usec),
    // 	((end.tv_usec) -
    // 	(start.tv_usec)));
	// 	printf("final status %d\n", number);
}