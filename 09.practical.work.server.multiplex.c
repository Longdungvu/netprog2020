#include <stdio.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <stdio.h>
#include <arpa/inet.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/select.h>
#include <poll.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/select.h>
#define MAX_CLIENT 5

int isDelimiter(char* x) {
  for (int i = 0; i < strlen(x); i++) {
    if (x[i] == '\n') {
      return 1;
    }
  }
  return 0;
 }

int main() {
  int sockfd, clen , clientfd, receive, sockopt, fl ;
  char buffer[1024] = {0};
  char data[2024] = {0};
  char apd = '\n';
  struct sockaddr_in saddr, caddr;
  unsigned short port = 1234;
  int clientfds[100];
  memset(clientfds,0,sizeof(clientfds));
  if ((sockfd = socket (AF_INET, SOCK_STREAM, 0)) < 0) {
    printf("error creating socket\n");
    exit(0);
  }

  sockopt = setsockopt (sockfd, SOL_SOCKET, SO_REUSEADDR, &(int){ 1 }, sizeof(int));

  fl = fcntl(sockfd, F_GETFL, 0);
  fl |= O_NONBLOCK;
  fcntl(sockfd, F_SETFL, fl);


  memset(&saddr, 0 , sizeof(saddr));
  saddr.sin_family = AF_INET;
  saddr.sin_addr.s_addr = htonl(INADDR_ANY);
  saddr.sin_port = htons(port);


  if ((bind(sockfd, (struct sockaddr *) &saddr, sizeof(saddr))) < 0 ) {
    printf("error listening\n");
    exit(0);
  }


  if (listen(sockfd, 5) < 0) {
    printf("error listening\n");
    exit(0);
  }

  while (1) {
    fd_set set;
    FD_ZERO(&set);
    FD_SET(sockfd, &set);
    int maxfd = sockfd;
    for (int i = 0; i < 100; i++) {
      if (clientfds[i] > 0) FD_SET(clientfds[i], &set);
      if (clientfds[i] > maxfd) maxfd = clientfds[i];
    }
    select(maxfd+1, &set, NULL, NULL, NULL);

    if (FD_ISSET(sockfd, &set)) {
      clientfd = accept(sockfd, (struct sockaddr *) &saddr, &clen);

      fl = fcntl(clientfd, F_GETFL, 0);
      fl |= O_NONBLOCK;
      fcntl(clientfd, F_SETFL, fl);

      for (int i = 0; i < MAX_CLIENT; i++) {
        if (clientfds[i] == 0) {
          clientfds[i] = clientfd;
          break;
        }
      }
    }

    for (int i = 0; i < MAX_CLIENT; i++) {
      if (clientfds[i] > 0 && FD_ISSET(clientfds[i], &set)) {
        if (recv(clientfds[i], buffer, sizeof(buffer), 0) > 0) {
          printf("client %d says: %s\nserver>",clientfds[i], buffer);
        } else {
          printf("client %d has disconnected\n", clientfds[i]);
          clientfds[i] = 0;
        }
      }
    }

  }
}
