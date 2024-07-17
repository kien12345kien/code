#include <stdio.h>
#include <unistd.h>   // for getpid()

int main() {
    pid_t pid;

    // Get the PID of the current process
    pid = getpid();

    // Print the PID
    printf("PID of the current process: %d\n", pid);

    return 0;
}
ß
