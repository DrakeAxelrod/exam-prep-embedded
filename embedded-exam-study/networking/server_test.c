#include "common.h"

const int port = 8080;

void myFunc() {
  printf("Func run once connected");
}

int main()
{
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1)
  {
    printf("socket creation failed...\n");
    exit(0);
  }
  else
  {
    printf("Socket successfully created..\n");
  }
  struct sockaddr_in server;
  server.sin_family = AF_INET; // protocol
  server.sin_addr.s_addr = INADDR_ANY; // address
  server.sin_port = htons(port); // port
  // connect the client socket to server socket
  if (connect(sockfd, (struct sockaddr *)&server, sizeof(server)) != 0)
  {
    printf("connection with the server failed...\n");
    exit(0);
  }
  else
  {
    printf("connected to the server..\n");
  }
  // your connected run this function.
  myFunc();
  close(sockfd);
  return 0;
}
