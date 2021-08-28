#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <pthread.h>
#include <signal.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <ctype.h>
#include <errno.h>

#define MAX_CLIENTS 10
#define MAX_LEN 1 << 11
#define MAX_NAME_LEN 16
#define BUF_SIZE (1 << 10)

#define print_ip_addr(s) printf("%d.%d.%d.%d", \
                                s.sin_addr.s_addr & 0xff, \
                                (s.sin_addr.s_addr & 0xff00) >> 8, \
                                (s.sin_addr.s_addr & 0xff0000) >> 16, \
                                (s.sin_addr.s_addr & 0xff0000) >> 24)

void dumpString(char *s) {
  size_t arraySize = strlen(s) + 1;

  printf("Character: %s\n", s);
  printf("# of bytes: %d\n", arraySize);

  for (size_t i = 0; i < arraySize; i++)
    printf("[%2d] 0x%02X\n", i, *(s+i));
}

static _Atomic unsigned int cli_count = 0;
static _Atomic int uid = 10;

struct client {
    struct sockaddr_in address;
    int sockfd;
    int uid;
    char name[MAX_NAME_LEN + 1];
};

struct client *clients[MAX_CLIENTS];
pthread_mutex_t clients_mutex = PTHREAD_MUTEX_INITIALIZER;

void str_overwrite_stdout() {
    printf("\r%s", "> ");
    fflush(stdout);
}

void queue_add(struct client *cli)
{
    pthread_mutex_lock(&clients_mutex);
    for(int i = 0; i < MAX_CLIENTS; i++)
    {
        if(!clients[i]) {
            clients[i] = cli;
            break;
        }
    }
    pthread_mutex_unlock(&clients_mutex);
}

void queue_remove(int uid)
{
    pthread_mutex_lock(&clients_mutex);
    for(int i = 0; i < MAX_CLIENTS; i++)
    {
        if(clients[i] && clients[i]->uid == uid)
        {
            clients[i] = NULL;
            break;
        }
    }
    pthread_mutex_unlock(&clients_mutex);
}

void send_message(char *s, int uid) {
    pthread_mutex_lock(&clients_mutex);
    for(int i = 0; i < MAX_CLIENTS; i++)
    {
        if(clients[i] && clients[i]->uid != uid)
        {
            while(write(clients[i]->sockfd, s, strlen(s) + 1) < 0)
            {
                if (errno == EINTR)
                    continue;
                else
                {
                    perror("Sending message failed: ");
                    break;
                }
            }
        }
    }
    pthread_mutex_unlock(&clients_mutex);
}

void *client_handler (void *aux)
{
    char buffer[BUF_SIZE];
    char name[MAX_NAME_LEN];
    int flag = 0;

    char msg1[] = "Please enter your name : ";
    char msg2[] = "Wrong name, type again : ";
    size_t received_bytes;

    cli_count++;

    struct client *cli = (struct client *)aux;

    while (1)
    {
        send(cli->sockfd, msg1, strlen(msg1), 0);
        memset(name, 0, MAX_NAME_LEN);
        while((received_bytes = recv(cli->sockfd, name, MAX_NAME_LEN - 1, 0)) == -1)
        {
            if(errno == EINTR)
                continue;
            else
            {
                perror("receive failed : ");
                goto done;
            }
        }

        if(received_bytes == 0)
            goto done;

        dumpString(name);
        name[received_bytes - 2] = '\0';
        if(strlen(name) < 1 || strlen(name) > MAX_NAME_LEN)
        {
            send(cli->sockfd, msg2, strlen(msg2), 0);
            continue;
        }
        else
        {
            strncpy(cli->name, name, received_bytes);
            sprintf(buffer, "%s has joined.\n", cli->name);
            printf("%s", buffer);
            send_message(buffer, cli->uid);

            break;
        }
    }

    memset(buffer, 0, BUF_SIZE);

    while(1)
    {
        if(flag)
            break;
        
        int receive;
        while((receive = recv(cli->sockfd, buffer, BUF_SIZE - 1, 0)) == -1)
        {
            if(errno == EINTR)
                continue;
            else
            {
                perror("receive failed: ");
                goto done;
            }
        }

        if(receive > 0 && strlen(buffer) > 0)
        {
            buffer[receive] = '\0';

            if(strcmp(buffer, "exit") == 0)
            {
                sprintf(buffer, "%s has left.\n", cli->name);
                printf("%s", buffer);
                send_message(buffer, cli->uid);

                goto done;
            }

            send_message(buffer, cli->uid);
            printf("%s -> %s", buffer, cli->name);
        }

        else if(receive == 0)
        {
            sprintf(buffer, "%s has left.\n", cli->name);
            printf("%s", buffer);
            send_message(buffer, cli->uid);
            
            goto done;
        }
        else
        {
            printf("Error!\n");
            goto done;
        }

        memset (buffer, 0, BUF_SIZE);
    }

done:
    //exit
    close(cli->sockfd);
    queue_remove(cli->uid);
    free(cli);
    cli_count--;

    pthread_detach(pthread_self());
    return NULL;
}

int main(int argc, char const *argv[])
{
    if(argc != 2)
    {
        printf("Usage : %s <port>\n", argv[0]);
        return EXIT_FAILURE;
    }

    int port = atoi(argv[1]);
    if(port == 0)
    {
        printf("Wrong port number : %s\n", argv[1]);
        return EXIT_FAILURE;
    }

    int option = 1;
    int listenfd = 0, connfd = 0;
    struct sockaddr_in serv_addr;
    struct sockaddr_in cli_addr;

    pthread_t tid;

    //Socket Settings
    listenfd = socket(AF_INET, SOCK_STREAM, 0);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(port);

    //Signals
    signal(SIGPIPE, SIG_IGN);

    if((setsockopt(listenfd, SOL_SOCKET, SO_REUSEPORT, (char *)&option, sizeof(option)) < 0)
        || (setsockopt(listenfd, SOL_SOCKET, SO_REUSEADDR, (char *)&option, sizeof(option)) < 0))
    {
        perror("setsockopt failed ");
        return EXIT_FAILURE;
    }

    if(bind(listenfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) 
    {
        perror("bind failed ");
        return EXIT_FAILURE;
    }

    if(listen(listenfd, 10) < 0)
    {
        perror("listen failed ");
        return EXIT_FAILURE;
    }

    printf("=== WELCOME TO CHATROOM ===\n");

    while(1)
    {
        socklen_t len_client = sizeof(cli_addr);
        connfd = accept(listenfd, (struct sockaddr *)&cli_addr, &len_client);

        // Check for MAX Clients
        if((cli_count + 1) == MAX_CLIENTS) {
            printf("Connection rejected : Maximum clients connected\n");
            close(connfd);
            continue;
        }

        // Client Settings
        struct client *client = (struct client *) malloc (sizeof (struct client));
        *client = (struct client) {
            .address = cli_addr,
            .sockfd = connfd,
            .uid = uid++,
        };

        queue_add(client);
        pthread_create(&tid, NULL, client_handler, (void *)client);
    }

    return 0;
}

