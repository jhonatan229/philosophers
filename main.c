#include "philo.h"

int pool;

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

void	start_struct(t_thread_philo *philo, int id)
{
	philo->id_philo = id;
	philo->status = THINKING;
	philo->left_hand = TRUE;
	philo->right_hand = FALSE;
}
int signal = 1;
CHAR WUOTE
int main()
{
	pool = 1;
	t_thread_philo first_philo;
	t_thread_philo second_philo;
	start_struct(&first_philo, 1);
	start_struct(&second_philo, 2);
	second_philo.status = SLEAPING;
	pthread_create(&first_philo.thread_ph, NULL, print_hello, (void *)&first_philo);
	pthread_create(&second_philo.thread_ph, NULL, print_hello, (void *)&second_philo);
	pthread_join(first_philo.thread_ph, NULL);
	pthread_join(second_philo.thread_ph, NULL);
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