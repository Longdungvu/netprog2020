#include <stdio.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <stdio.h>
#include <arpa/inet.h>

int main() {
  int sockfd, clen , clientfd;
  struct sockaddr_in saddr, caddr;
  unsigned short port = 8784;
  if ((sockfd = socket (AF_INET, SOCK_STREAM, 0)) < 0) {
    printf("error creating socket\n");
  }


  memset(&saddr, 0 , sizeof(saddr));
  saddr.sin_family = AF_INET;
  saddr.sin_addr.s_addr = htonl(INADDR_ANY);
  saddr.sin_port = htons(port);


  if ((bind(sockfd, (struct sockaddr *) &saddr, sizeof(saddr))) < 0 ) {
    printf("error listening\n");
  }


  if (listen(sockfd, 5) < 0) {
    printf("error listening\n");
  }


  clen=sizeof(caddr);
  if ((clientfd = accept(sockfd, (struct sockaddr*) &caddr, &clen)) < 0) {
    printf("error accepting connection\n");
  }
  else printf("[@] connection done");

  char *ip = inet_ntoa(caddr.sin_addr);
  printf("[@] ip: %s\n", ip);
}
