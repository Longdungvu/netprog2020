#include <stdio.h>
 #include <netdb.h>
 #include <sys/socket.h>
 #include <netinet/in.h>
 #include <arpa/inet.h>
 #include <stdlib.h>
 #include <string.h>

 int main(int argc, char const *argv[]) {
   char x[999];
   if (argc == 1) {
     printf("hostname :");
     scanf("%s", x);
   } else {
     strcpy(x,argv[1]);
   }

   struct hostent *domain = gethostbyname(x);
   struct in_addr *in = (int*) domain->h_addr_list[0];
   printf("ip address is %s\n",inet_ntoa(*in));
   return 0;
 }
