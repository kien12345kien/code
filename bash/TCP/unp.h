#ifndef UNP_H
#define UNP_H

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAXLINE 4096
#define SERV_PORT 9877
#define LISTENQ 1024
#define SA struct sockaddr

void err_sys(const char* x) { 
    perror(x); 
    exit(1); 
}

void err_quit(const char* x) { 
    fprintf(stderr, "%s\n", x); 
    exit(1); 
}

int Socket(int family, int type, int protocol) {
    int n;
    if ((n = socket(family, type, protocol)) < 0)
        err_sys("socket error");
    return n;
}

void Connect(int fd, const struct sockaddr *sa, socklen_t salen) {
    if (connect(fd, sa, salen) < 0)
        err_sys("connect error");
}

void Inet_pton(int family, const char *strptr, void *addrptr) {
    int n;
    if ((n = inet_pton(family, strptr, addrptr)) <= 0) {
        if (n == 0)
            err_quit("inet_pton error: invalid address");
        else
            err_sys("inet_pton error");
    }
}

ssize_t Writen(int fd, const void *vptr, size_t n) {
    size_t nleft;
    ssize_t nwritten;
    const char *ptr;

    ptr = vptr;
    nleft = n;
    while (nleft > 0) {
        if ((nwritten = write(fd, ptr, nleft)) <= 0) {
            if (nwritten < 0 && errno == EINTR)
                nwritten = 0; /* and call write() again */
            else
                return(-1); /* error */
        }
        nleft -= nwritten;
        ptr += nwritten;
    }
    return(n);
}

void str_cli(FILE *fp, int sockfd) {
    char sendline[MAXLINE], recvline[MAXLINE];
    while (fgets(sendline, MAXLINE, fp) != NULL) {
        Writen(sockfd, sendline, strlen(sendline));

        if (read(sockfd, recvline, MAXLINE) == 0)
            err_quit("str_cli: server terminated prematurely");
        
        fputs(recvline, stdout);
    }
}

#endif /* UNP_H */

