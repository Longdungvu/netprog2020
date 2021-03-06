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
  struct sockaddr_in saddr;
  struct hostent *h;
  int sockfd;
  unsigned short port = 443;

  if ((sockfd=socket(AF_INET, SOCK_STREAM, 0)) < 0) {
    printf("Error creting socket\n");
    return -1;
  }

  if (( h = gethostbyname("dns.google")) == NULL) {
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

  }






}
