#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

int id;
pthread_mutex_t mutex;

void	*func()
{
	int i = 0;
	while (i < 1000000)
	{
		pthread_mutex_lock(&mutex);
		id++;
		i++;
		pthread_mutex_unlock(&mutex);
	}
	// return(1);
}

int main()
{
    pthread_t philos[3];
	int i = 0;
	id = 0;

	pthread_mutex_init(&mutex, NULL);
	while (i < 3)
	{
		pthread_create(&philos[i], NULL, &func, NULL);
		i++;
	}
	i = 0;
	while (i < 3)
	{
		pthread_join(philos[i], NULL);
		i++;
	}
	printf("==== %d\n", id);
}