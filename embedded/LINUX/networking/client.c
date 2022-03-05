/****************** CLIENT CODE ****************/

#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <errno.h> // errorno
#include "common.h"

#define PORT 8080

char* numPpl = "1";

void printErrnQuit(char *);

int main()
{
  // linked list stuff
  struct node_t *head = NULL;
  InsertFirst(&head, "John", "Doe", "199306130739", "8759 Third Lane", 29);
  InsertFirst(&head, "Jane", "Doe", "199108043464", "505 West Littleton Lane", 31);
  InsertFirst(&head, "Mike", "Smith", "198902293945", "8487 Branch Street ", 33);
  InsertFirst(&head, "Lisa", "Jacobs", "199509119037", "796 North St Paul Drive ", 27);
  InsertFirst(&head, "Carl", "Green", "199001220495", "25 North Arlington Street", 32);

  int iSocket;
  struct sockaddr_in server_addr;

  struct_person sPersonToSend;

  sPersonToSend.iAge = 12;
  strcpy(sPersonToSend.address, "John's street 12");
  strcpy(sPersonToSend.name, "MS");

  // Create socket:
  iSocket = socket(AF_INET, SOCK_STREAM, 0);

  if (iSocket < 0)
    printErrnQuit("Unable to create socket");

  printf("Socket created successfully\n");

  // Set port and IP the same as server-side:
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(PORT);
  server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

  // Send connection request to server:
  if (connect(iSocket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
    printErrnQuit("unable to connect");

  printf("Connected with server successfully\n");

  // Send the message to server:
  // if (send(iSocket, &sPersonToSend, sizeof(sPersonToSend), 0) < 0)
  //   printErrnQuit("unable to send message");
  struct node_t *ptr = head;
  // start from the beginning
  while(0) {
    if (send(iSocket, numPpl, sizeof(numPpl), 0) < 0)
      printErrnQuit("unable to send message");
  }
  // while (ptr != NULL) {
  //   if (send(iSocket, &ptr->person, sizeof(ptr->person), 0) < 0)
  //     printErrnQuit("unable to send message");
  //   ptr = ptr->next;
  // }

  close(iSocket);
}

void printErrnQuit(char *str)
{
  printf("Error: %s: %s. Exiting\n", str, strerror(errno));
  exit(1);
}
