#ifndef PHILO_H

#define PHILO_H

#include "sys/time.h"
#include "stdio.h"
#include <unistd.h>
#include <pthread.h>
 # define EATING 2
 # define SLEAPING 3
 # define THINKING 4
 # define DEAD 0
 # define ALIVE 1
// # define TRUE 1
// # define FALSE 0

typedef struct s_thread_philo{
	int			num;
	int			status;
	int			left_hand;
	int			right_hand;
	pthread_t	thread_ph;
}				t_thread_philo;

typedef struct s_philo{
	int				num_philos;
	t_thread_philo	*thread_ph;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print;
}				t_philo;

void	*ft_calloc(size_t nmemb, size_t size);

#endif