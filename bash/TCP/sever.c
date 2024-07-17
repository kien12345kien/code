#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <strings.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define SERV_PORT 9877
#define LISTENQ 1024
#define SA struct sockaddr

void str_echo(int sockfd) {
    ssize_t n;
    char buf[1024];
again:
    while ((n = read(sockfd, buf, 1024)) > 0)
        write(sockfd, buf, n);
    if (n < 0)
        goto again;
}

int main(int argc, char **argv) {
    int listenfd, connfd;
    pid_t childpid;
    socklen_t clilen;
    struct sockaddr_in cliaddr, servaddr;

    if ((listenfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket error");
        exit(1);
    }

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(SERV_PORT);

    if (bind(listenfd, (SA *) &servaddr, sizeof(servaddr)) < 0) {
        perror("bind error");
        exit(1);
    }

    if (listen(listenfd, LISTENQ) < 0) {
        perror("listen error");
        exit(1);
    }

    for (;;) {
        clilen = sizeof(cliaddr);
        if ((connfd = accept(listenfd, (SA *) &cliaddr, &clilen)) < 0) {
            perror("accept error");
            continue;
        }

        if ((childpid = fork()) == 0) { /* child process */
            close(listenfd);  /* close listening socket */
            str_echo(connfd); /* process the request */
            exit(0);
        }
        close(connfd); /* parent closes connected socket */
    }
}

