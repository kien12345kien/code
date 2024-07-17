#include <iostream>
#include <unistd.h>   // for getpid()

int main() {
    pid_t pid;

    // Get the PID of the current process
    pid = getpid();

    // Print the PID
    std::cout << pid <<std::endl;

    return 0;
}