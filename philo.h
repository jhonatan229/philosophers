#ifndef PHILO_H

#define PHILO_H

#include "sys/time.h"
#include "stdio.h"
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>

 # define EATING 2
 # define SLEAPING 3
 # define THINKING 4
 # define GET_FORK 5
 # define DROP_FORK 6
 # define DEAD 0
 # define ALIVE 1
// # define TRUE 1
// # define FALSE 0


typedef struct s_thread_philo{
	int			num;
	long int	time;
	int			left_hand;
	int			right_hand;
	pthread_t	thread;
	struct s_philo		*main_struct;
}				t_thread_philo;

typedef struct s_philo{
	t_thread_philo	*thread_ph;
	int				num_philos;
	int				status;
	long int		t_eat;
	long int		t_die;
	long int		t_start;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print;
}				t_philo;

void		*ft_calloc(size_t nmemb, size_t size);
int			try_eat(t_thread_philo *philo);
int			try_sleep(t_thread_philo *philo);
int			try_think(t_thread_philo *philo);
long int	ft_time(void);
int			verify_time(t_thread_philo *philo);
void 		print_line(t_thread_philo *philo, int status);
void		free_all(t_philo *philo);
void		drop_fork(t_thread_philo *philo);

#endif