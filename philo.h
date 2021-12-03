#ifndef PHILO_H

#define PHILO_H

#include "sys/time.h"
#include "stdio.h"
#include <unistd.h>
#include <pthread.h>
# define THINKING 1
# define EATING 2
# define SLEAPING 3
# define DEAD 4
# define TRUE 1
# define FALSE 0

typedef struct s_thread_philo{
	int			id_philo;
	int			status;
	int			left_hand;
	int			right_hand;
	pthread_t	thread_ph;
}				t_thread_philo;

#endif