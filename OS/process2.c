#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void handler(int signal_num)
{
    printf("Signal %d =>", signal_num);
    switch(signal_num)
    {
        case SIGTSTP:
            printf("paise/n");
            break;
        case SIGINT:
        case SIGTERM:
            printf("end of the program/n");
            exit(0);
            break;
    }
}

int main(void)
{
    signal(SIGTSTP, handler);
    signal(SIGINT, handler);
    signal(SIGTERM, handler);
    while (1)
    {
        sleep(1);
        printf(".\n");
    }
    printf("end");
    exit(0);
}