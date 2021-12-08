/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 00:42:03 by coder             #+#    #+#             */
/*   Updated: 2021/12/08 01:07:16 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void *print_hello(void *arg)
{
	t_thread_philo *philo = (t_thread_philo *)arg;
	while (philo->status != DEAD)
	{
		if (philo->status == EATING){
			printf("thread %d is EATING\n", philo->id_philo);
			sleep(2);
			philo->status = THINKING;
			philo->right_hand = FALSE;
			pool = 1;
		}
		else if (philo->status == THINKING)
		{
			printf("thread %d is THINKING\n", philo->id_philo);
			sleep(1);
			philo->status = SLEAPING;
		}
		else if (philo->status == SLEAPING)
		{
			printf("thread %d is SLEAPING\n", philo->id_philo);
			sleep(2);
			if (philo->left_hand == FALSE || philo->right_hand == FALSE)
			{
				if (philo->left_hand == FALSE && pool)
					philo->left_hand = TRUE;
				else if (philo->right_hand == FALSE && pool)
					philo->right_hand = TRUE;
				pool = 0;
			}
			philo->status = EATING;
		}
	}
	return NULL;
}

void	start_struct(t_philo *philo, int num_philo)
{
	int count;

	count = 0;
	philo->thread_ph = ft_calloc(sizeof(t_thread_philo), num_philo);
	philo->forks = ft_calloc(sizeof(pthread_mutex_t), num_philo);
	pthread_mutex_init(&philo->print, NULL);
	while(count < num_philo)
	{
		pthread_create(&philo->thread_ph[count], NULL, print_hello, (void *)&philo->thread_ph[count]);
		pthread_mutex_init(&philo->forks[count], NULL);
		philo->thread_ph->num = count;
		philo->thread_ph->status = ALIVE;
		philo->thread_ph->left_hand = count;
		philo->thread_ph->right_hand = count + 1;
		if (count == num_philo - 1)
			philo->thread_ph->right_hand = count;
		count++;
	}
}

void print_line(t_thread_philo *philo, int status)
{
	pthread_mutex_lock(philo->print);
	if (status == EATING)
		printf("tempo, philo %i, eating!", philo->num);
	else if (sttus == SLEAPING)
		printf("tempo, philo %i, SLEAPING!", philo->num);
	else if (status == THINKING)
		printf("tempo, philo %i, THINKING!", philo->num);
	pthread_mutex_unlock(philo->print);
}

int main()
{
	int count;

	count = 0;
	t_philo philo;
	philo.num_philos = 3;
	start_struct(&philo, philo.num_philos);
	while(count < philo.num_philos)
	{
		if (!pthread_join(&philo.thread_ph[count], NULL))
		{
			printf("finish\n");
			exit();
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