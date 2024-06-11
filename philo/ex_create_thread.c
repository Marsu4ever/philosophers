
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

void* thread_function(void* lock)
{
    // *(pthread_mutex_t *)lock;
	pthread_mutex_lock((pthread_mutex_t *)lock);
	// Thread work

	
	printf("hey\n");
	usleep(500000);
	printf("you\n");
	pthread_mutex_unlock((pthread_mutex_t *)lock);
	//HOLD FOR certain milliseconds
	//MUTEX stuff
    return NULL;
}

int main(void)
{
	pthread_t 		thread1, thread2;
	pthread_mutex_t lock;
	int	*result1;
	int	rv_create;
	int	rv_join;

	pthread_mutex_init(&lock, NULL);

	rv_create = pthread_create(&thread1, NULL, thread_function, (void *)&lock);
	printf("rv_create: %d\n", rv_create);

	pthread_create(&thread2, NULL, thread_function, (void *)&lock);

	rv_join = pthread_join(thread1, (void **)&result1);
	printf("rv_join: %d\n", rv_join);	

	pthread_join(thread2, (void **)&result1);

	pthread_mutex_destroy(&lock);
	return (0);
}
