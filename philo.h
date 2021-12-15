/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 18:04:03 by coder             #+#    #+#             */
/*   Updated: 2021/12/15 18:05:25 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H

# define PHILO_H

# include "sys/time.h"
# include "stdio.h"
# include <unistd.h>
# include <pthread.h>
# include <stdlib.h>
# include <string.h>

# define EATING 2
# define SLEAPING 3
# define THINKING 4
# define GET_FORK 5
# define DEAD 0
# define ALIVE 1
# define ACTIVE 6
# define INATIVE 7

typedef struct s_thread_philo{
	int					num;
	long int			time;
	int					status;
	int					num_eats;
	int					left_hand;
	int					right_hand;
	pthread_t			thread;
	struct s_philo		*main_struct;
}				t_thread_philo;

typedef struct s_philo{
	t_thread_philo	*thread_ph;
	int				num_philos;
	int				status;
	long int		t_eat;
	long int		t_sleep;
	long int		t_die;
	long int		t_start;
	int				count_eat;
	int				philo_needs_eat;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print;
}				t_philo;

int			verify_time(t_thread_philo *philo);
void		print_line(t_thread_philo *philo, int status);
void		drop_fork(t_thread_philo *philo);

//UTILS
void		*ft_calloc(size_t nmemb, size_t size);
void		free_all(t_philo *philo);
int			ft_atoi(const char *nptr);
int			ft_isdigit(char *str);
long int	ft_time(void);

//ACTIONS
int			try_eat(t_thread_philo *philo);
int			try_sleep(t_thread_philo *philo);
int			try_think(t_thread_philo *philo);

//INITIALIZE
void		start_struct(t_philo *philo);
int			set_args_to_struct(t_philo *philo, char **argv);
void		creating_philos(t_philo *philo);
int			valid_args(t_philo *philo);

//OPEN HOUSE
void		*action(void *arg);
void		start_dinner(t_philo *philo);
#endif