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

int isDelimiter(char* x) {
  // for (int i = 0; i < strlen(x); i++) {
    if (x[strlen(x) - 1] == ' ') {
      return 1;
    }
  // }
  return 0;
 }

int main() {
  int sockfd, clen , clientfd, receive ;
  char buffer[1024] = {0};
  char data[2024] = {0};
  char apd = ' ';
  struct sockaddr_in saddr, caddr;
  unsigned short port = 1234;
  if ((sockfd = socket (AF_INET, SOCK_STREAM, 0)) < 0) {
    printf("error creating socket\n");
    exit(0);
  }


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
  accept:
  clen=sizeof(caddr);
  if ((clientfd = accept(sockfd, (struct sockaddr*) &caddr,(socklen_t*) &clen)) < 0) {
    printf("error accepting connection\n");
    exit(0);
  }
  else{
   printf("connection done\n");

  char *ip = inet_ntoa(caddr.sin_addr);
  printf("ip: %s\n", ip);



  while (1) {
    //receive client messages
    memset(&buffer, 0 , sizeof(buffer));
    memset(&data, 0 , sizeof(data));

    while (isDelimiter(buffer) == 0) {
    receive = recv(clientfd, buffer, sizeof(buffer), 0);
    //ACK client disconecting
    if (receive <= 0) {
      printf("client disconnected\n");
      close(clientfd);
      goto accept;
    }

    strncat(data,buffer,strlen(buffer)); //append to buffer
    }

    printf("[Client]: %s\n",data );

    //send messages to client
    memset(buffer, 0 , 1024);
    memset(data, 0 , 2024);

    printf("[Server]: ");
    scanf("%[^\n]%*c",buffer);

    //disconecting client
    if (strcmp(buffer,"/cd") == 0) {
      printf("disconnect client\n");
      shutdown(clientfd,SHUT_RDWR);
      int count;
      char c;
      while ((count = read(clientfd, &c, sizeof(c))) > 0);
      close(clientfd);
      goto accept;
    }

    strncat(buffer,&apd,1);
    send(clientfd,buffer, sizeof(buffer), 0);

    }
  }


}
