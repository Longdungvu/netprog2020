#include <stdio.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <stdio.h>
#include <arpa/inet.h>


int isDelimiter(char* x) {
  for (int i = 0; i < strlen(x); i++) {
    if (x[i] == ' ') {
      return 1;
    }
  }
  return 0;
 }

int main() {
  struct sockaddr_in saddr;
  struct hostent *h;
  int sockfd, receive;
  unsigned short port = 1234;   //443 https default port
  char buffer[1024] = {0};
  char data[2024] = {0};
  char apd = ' ';
  if ((sockfd=socket(AF_INET, SOCK_STREAM, 0)) < 0) {
    printf("Error creting socket\n");
    exit(0);
  }

  if (( h = gethostbyname("127.0.0.1")) == NULL) {
    printf("unknown host\n");
    return -1;
  }

  memset(&saddr, 0 , sizeof(saddr));
  saddr.sin_family = AF_INET;
  memcpy((char *) &saddr.sin_addr.s_addr, h->h_addr_list[0], h->h_length);
  saddr.sin_port = htons(port);
  if (connect (sockfd, (struct sockaddr *) &saddr, sizeof(saddr)) < 0) {
    printf("Cannot connect\n");
    return -1;
  } else {
    printf("connection successful\n");
    printf("hostname is %s\n", h->h_name);
    struct in_addr *in = (int*) h->h_addr_list[0];
    printf("ip address is %s\n",inet_ntoa(*in));

    while (1) {
      //send messages to server
      memset(&buffer, 0 , sizeof(buffer));
      memset(&data, 0 , sizeof(data));
      printf("[Client]: ");
      scanf("%s",buffer);
      strncat(&buffer,&apd,1); //add Delimiter to messages
      send(sockfd,buffer, sizeof(buffer), 0);
      //receive server messages
      memset(&buffer, 0 , 1024);
      memset(&data, 0 , 2024);
      while(isDelimiter(buffer) == 0) {
      receive = recv(sockfd, buffer, sizeof(buffer), 0);
      strncat(&data,&buffer,strlen(buffer));
      }
      printf("[Server]: %s\n",data );
    }
  }




}
