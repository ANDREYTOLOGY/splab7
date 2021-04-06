#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <time.h>

int main(int argc, char *argv[]) {
    int lstn_fd = 0, connfd = 0;
    struct sockaddr_in server_addr;

    char sendBuff[1025];
    char recvBuff[1025];

    int port = 5000;

    lstn_fd = socket(AF_INET, SOCK_STREAM, 0);
    memset(&server_addr, 0, sizeof(server_addr));
    memset(sendBuff, 0, sizeof(sendBuff));
    memset(recvBuff, 0, sizeof(recvBuff));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(port);

    bind(lstn_fd, (struct sockaddr*)&server_addr, sizeof(server_addr));
    printf("port:%d\n", port);
    listen(lstn_fd, 1);

    while(1) {
        connfd = accept(lstn_fd, (struct sockaddr*)NULL, NULL);
        read(connfd, recvBuff, sizeof(recvBuff)-1);
        printf("%s\n", recvBuff);
        snprintf(sendBuff, sizeof(sendBuff), "return_tcp");
        write(connfd, sendBuff, strlen(sendBuff));
        close(connfd);
        sleep(1);
     }
}