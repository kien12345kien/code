#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <cstring>

int main()
{
    int sever_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (sever_fd == -1){
        std::cerr << "Socket creation failed\n";
        return 1;
    }

    sockaddr_in sever_addr;
    sever_addr.sin_family = AF_INET;
    sever_addr.sin_addr.s_addr = INADDR_ANY;
    sever_addr.sin_port = htons(8080);

    if(bind(sever_fd, (struct sockaddr*) &sever_addr, sizeof(sever_addr)) < 0){
        std::cerr << "Bind failed";
        return 1;
    }

    if (listen(sever_fd, 3) < 0){
        std::cerr << "Listen failed\n";
        return 1;
    }

    int client_fd = accept(sever_fd, nullptr, nullptr);
    if( client_fd < 0)
    {
        std::cerr << "Accept failed\n";
        return 1;
    }

    const char*hello = "hello from sever";
    send(client_fd, hello, strlen(hello), 0);

    close(client_fd);
    close(sever_fd);

    return 0;
}
