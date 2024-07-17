#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>  // Include this header for wait()

int main()
{
    pid_t pid;
    pid = fork();
    if (pid < 0)
    {
        fprintf(stderr, "Fork Failed");  // Corrected "stdeer" to "stderr"
        return 1;
    }
    else if (pid == 0)
    {
        execlp("/bin/ls", "ls", NULL);  // Corrected typo: "ls". NULL to "ls", NULL
    }
    else
    {
        wait(NULL);  // Correctly wait for the child process to complete
        printf("Child Complete\n");  // Added newline character for better formatting
    }
    return 0;
}
