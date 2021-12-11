/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 00:42:03 by coder             #+#    #+#             */
/*   Updated: 2021/12/11 01:40:04 by coder            ###   ########.fr       */
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

void	start_struct(t_philo *philo)
{
	int count;

	count = 0;
	philo->thread_ph = ft_calloc(philo->num_philos, sizeof(t_thread_philo));
	philo->forks = malloc(sizeof(pthread_mutex_t) * philo->num_philos);
	philo->status = ALIVE;
	pthread_mutex_init(&philo->print, NULL);
	while(count < philo->num_philos)
	{
		pthread_mutex_init(&philo->forks[count], NULL);
		philo->thread_ph[count].num = count;
		philo->thread_ph[count].left_hand = count;
		philo->thread_ph[count].right_hand = count + 1;
		philo->thread_ph[count].main_struct = philo;
		if (count == philo->num_philos - 1)
		 	philo->thread_ph[count].right_hand = 0;
		count++;
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
	return (0);
}

int main(int argc, char **argv)
{
	int count;

	count = 0;
	t_philo philo;
	if (argc < 5)
		return (1);
	printf("args %i, char %i", argc, philo.num_philos);
	memset(&philo, 0, sizeof(t_philo));
	set_args_to_struct(&philo, argv);
	start_struct(&philo);
	while (count < philo.num_philos)
	{
		pthread_create(&philo.thread_ph[count].thread, NULL, print_hello, (void *)&philo.thread_ph[count]);
		count++;
	}
	printf("args %i, char %i", argc, philo.num_philos);
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