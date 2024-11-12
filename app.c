#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 8080

void error(const char *msg) {
    perror(msg);
    exit(1);
}

int main() {
    int sockfd, newsockfd;
    socklen_t clilen;
    char buffer[256];
    struct sockaddr_in serv_addr, cli_addr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("Error opening socket");
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(PORT);

    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        error("Error on binding");
    }

    listen(sockfd, 5);
    clilen = sizeof(cli_addr);

    newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
    if (newsockfd < 0) {
        error("Error on accept");
    }

    bzero(buffer, 256);
    snprintf(buffer, sizeof(buffer), 
        "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n"
        "<html><body style='text-align:center; color: purple;'>"
        "Hello, Engineer! This is a Docker container running a C app."
        "</body></html>");

    write(newsockfd, buffer, strlen(buffer));

    close(newsockfd);
    close(sockfd);

    return 0;
}
