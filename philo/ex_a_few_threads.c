/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_few_threads.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorpela <mkorpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 04:41:43 by mkorpela          #+#    #+#             */
/*   Updated: 2024/05/30 05:00:48 by mkorpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

// Define a mutex
pthread_mutex_t lock;

void* thread_function(void* arg) {
    // Lock the mutex before accessing shared resources
    pthread_mutex_lock(&lock);

    // Critical section
    printf("Thread %d is running\n", *(int*)arg);

    // Unlock the mutex after accessing shared resources
    pthread_mutex_unlock(&lock);

    pthread_exit(NULL);
}

int main() {
    pthread_t thread1, thread2;
    int thread_args1 = 1;
    int thread_args2 = 2;

    // Initialize the mutex
    pthread_mutex_init(&lock, NULL);

    // Create threads
    pthread_create(&thread1, NULL, thread_function, (void*)&thread_args1);
    pthread_create(&thread2, NULL, thread_function, (void*)&thread_args2);

    // Wait for threads to finish
	printf("a\n");
    pthread_join(thread1, NULL);
	printf("b\n");
    pthread_join(thread2, NULL);
	printf("c\n");

    // Destroy the mutex
    pthread_mutex_destroy(&lock);

    return 0;
}
