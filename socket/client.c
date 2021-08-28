#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

#define PORT 8080
#define MAX_LEN 1 << 10

int main(int argc, char const *argv[])
{
    int sock = 0, valread;
    struct sockaddr_in server_addr;
    char greeting[MAX_LEN];
    scanf("%s", greeting);
    char buffer[MAX_LEN] = {0};

    if((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        printf("socket creation failed\n");
        return -1;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons (PORT);

    if(inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr) <= 0)
    {
        printf("Address Not Supported\n");
        return -1;
    }

    printf("%x\n", server_addr.sin_addr);

    if(connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
    {
        printf("Connection Failed\n");
        return -1;
    }

    send(sock, greeting, strlen(greeting), 0);
    printf("Greeting has been sent from client\n");
    valread = read(sock, buffer, MAX_LEN);
    printf("%s", buffer);

    return 0;
}
