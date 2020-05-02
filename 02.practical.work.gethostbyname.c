#include <stdio.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>

int main() {
    char x[999]
	printf("hostname :")
	scanf("%s", &x);
    struct hostent *x = gethostbyname(hostname);
    struct in_addr *in = (int*) domain->h_addr_list[0];

    printf("ip address is %s\n",inet_ntoa(*in));
}
