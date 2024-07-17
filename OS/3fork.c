#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    printf("PID before forks: %d\n", getpid());

    fork(); // First fork
    fork(); // Second fork
    fork(); // Third fork

    printf("PID: %d, Parent PID: %d\n", getpid(), getppid());

    return 0;
}

