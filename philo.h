#ifndef PHILO_H

#define PHILO_H

#include "sys/time.h"
#include "stdio.h"
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>

 # define EATING 2
 # define SLEAPING 3
 # define THINKING 4
 # define GET_FORK 5
 # define DEAD 0
 # define ALIVE 1
// # define TRUE 1
// # define FALSE 0


typedef struct s_thread_philo{
	int			num;
	int			status;
	long int	time;
	int			left_hand;
	int			right_hand;
	pthread_t	thread;
	struct s_philo		*main_struct;
}				t_thread_philo;

typedef struct s_philo{
	int				num_philos;
	t_thread_philo	*thread_ph;
	long int		t_eat;
	struct timeval	t_start;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print;
}				t_philo;

void		*ft_calloc(size_t nmemb, size_t size);
int			try_eat(t_thread_philo *philo);
int			try_sleep(t_thread_philo *philo);
int			try_think(t_thread_philo *philo);
long int	verify_time(t_thread_philo *philo);
void		reset_time(t_thread_philo *philo);
void 		print_line(t_thread_philo *philo, int status);
#endif