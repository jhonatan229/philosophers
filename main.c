#include "sys/time.h"
#include "stdio.h"
#include <unistd.h>
#include <pthread.h>

int number;
pthread_mutex_t mut;

void *print_hello(void *arg)
{
	int coun = 0;
	int *n = (int *)arg;
	while (coun++ < 1000)
	{
		//pthread_mutex_lock(&mut);
		printf("hello word!\n");
		if (*n == 2)
			printf("first\n");
		if (*n == 4)
			printf("second\n");
		number++;
		//pthread_mutex_unlock(&mut);
	}
	return NULL;
}

int main()
{
	pthread_t point;
	pthread_t point_two;
	struct timeval start, end;
	int a1 = 2;
	int a2 = 4; 
	//pthread_mutex_init(&mut, NULL);
	gettimeofday(&start, NULL);
	// while (1){
		pthread_create(&point, NULL, print_hello, (void *)&a1);
		pthread_create(&point_two, NULL, print_hello, (void *)&a2);
		pthread_join(point, NULL);
		pthread_join(point_two, NULL);
		gettimeofday(&end, NULL);
		printf("start: %ld\n end: %ld\nTime taken to count to 10^5 is : %ld micro seconds\n",(start.tv_sec + start.tv_usec), (end.tv_sec + end.tv_usec),
    	((end.tv_usec) -
    	(start.tv_usec)));
		//sleep(2);
		printf("final status %d\n", number);
	// }
}