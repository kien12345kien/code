#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
#include <sys/wait.h>

#define MAXLINE 4096
#define LISTENQ 1024

void sigchld_handler(int signo) {
    while (waitpid(-1, NULL, WNOHANG) > 0) {
        // Reap zombie processes
    }
    return;
}

void echo(int connfd) {
    char buffer[MAXLINE];
    ssize_t n;

    while ((n = read(connfd, buffer, MAXLINE)) > 0) {
        write(connfd, buffer, n);
    }
}

int main(int argc, char **argv) {
    int listenfd, connfd;
    pid_t childpid;
    socklen_t clilen;
    struct sockaddr_in cliaddr, servaddr;

    listenfd = socket(AF_INET, SOCK_STREAM, 0);

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(9877);

    bind(listenfd, (struct sockaddr *) &servaddr, sizeof(servaddr));

    listen(listenfd, LISTENQ);

    signal(SIGCHLD, sigchld_handler); // Reap zombie processes

    for (;;) {
        clilen = sizeof(cliaddr);
        if ((connfd = accept(listenfd, (struct sockaddr *) &cliaddr, &clilen)) < 0) {
            if (errno == EINTR) continue; // Recovered from interrupt
            else perror("accept error");
        }

        if ((childpid = fork()) == 0) { // Child process
            close(listenfd); // Close listening socket
            echo(connfd); // Process the request
            exit(0);
        }
        close(connfd); // Parent closes connected socket
    }
}

