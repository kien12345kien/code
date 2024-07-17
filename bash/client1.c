#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>

#define SERVER_IP "192.168.163.129"
#define SERVER_PORT 8080
#define BUFFER_SIZE 1024
#define HOSTNAME_SIZE 256

int main() {
    int client_socket;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    char hostname[HOSTNAME_SIZE];
    ssize_t n;

    // Create a socket
    client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // Set up the server address structure
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);

    // Convert IPv4 and IPv6 addresses from text to binary form
    if (inet_pton(AF_INET, SERVER_IP, &server_addr.sin_addr) <= 0) {
        perror("inet_pton");
        close(client_socket);
        exit(EXIT_FAILURE);
    }

    // Connect to the server
    if (connect(client_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("connect");
        close(client_socket);
        exit(EXIT_FAILURE);
    }

    printf("Connected to server %s:%d\n", SERVER_IP, SERVER_PORT);

    // Get the hostname of the client
    if (gethostname(hostname, HOSTNAME_SIZE) == -1) {
        perror("gethostname");
        close(client_socket);
        exit(EXIT_FAILURE);
    }

    printf("Client hostname: %s\n", hostname);

    // Send the hostname to the server
    if (write(client_socket, hostname, strlen(hostname)) == -1) {
        perror("write");
        close(client_socket);
        exit(EXIT_FAILURE);
    }

    // Optionally, read input from the user and send it to the server
    printf("Enter message: ");
    fgets(buffer, BUFFER_SIZE, stdin);
    if (write(client_socket, buffer, strlen(buffer)) == -1) {
        perror("write");
        close(client_socket);
        exit(EXIT_FAILURE);
    }

    // Clean up
    close(client_socket);
    return 0;
}

