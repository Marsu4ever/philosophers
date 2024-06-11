/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex_calc_threads.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorpela <mkorpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 05:01:19 by mkorpela          #+#    #+#             */
/*   Updated: 2024/05/30 05:27:16 by mkorpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void* compute_part(void* arg) {
    int part = *(int*)arg;
    int* result = malloc(sizeof(int));
    *result = part * 2;  // Simple computation for demonstration
    return (void*)result;
}

int main() {
    pthread_t thread1, thread2;
    int arg1 = 1, arg2 = 2;
    int* result1;
    int* result2;

    // Create two threads
    pthread_create(&thread1, NULL, compute_part, (void*)&arg1);
    pthread_create(&thread2, NULL, compute_part, (void*)&arg2);

    // Wait for both threads to finish and retrieve their results
    pthread_join(thread1, (void**)&result1);
    pthread_join(thread2, (void**)&result2);

    // Combine results
    int final_result = *result1 + *result2;
    printf("Final result: %d\n", final_result);  // Expected: 6

    // Free allocated memory
    free(result1);
    free(result2);

    return 0;
}