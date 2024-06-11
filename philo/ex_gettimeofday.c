#include <stdio.h>
#include <sys/time.h>

int main() {
    struct timeval tv;

    // Get the current time
    if (gettimeofday(&tv, NULL) == -1) {
        perror("gettimeofday");
        return 1;
    }

    // Print the current time in seconds and microseconds
    printf("Seconds: %ld, Microseconds: %d\n", tv.tv_sec, tv.tv_usec);

    return 0;
}
