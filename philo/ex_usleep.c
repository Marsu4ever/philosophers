#include <stdio.h>
#include <unistd.h> // Include the header file containing usleep

int main() {
    printf("Start\n");

    // Suspend execution for 1 second (1,000,000 microseconds)
    usleep(1000000);

    printf("After delay\n");

    return 0;
}
