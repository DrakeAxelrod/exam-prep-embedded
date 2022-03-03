/****************** SERVER CODE ****************/
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <errno.h> // errorno
#include "common.h"
// Socket: Create a new communication
// Bind: Attach a local address to a socket
// Listen: Announce willingness to accept connections
// Accept: Block caller until a connection request arrives
// Connect: Actively attempt to establish a connection
// Send: Send some data over connection
// Receive: Receive some data over connection
// Close: Release the connection
#define PORT 8080

void printErrnQuit(char *);

int main()
{
  // linked list stuff
  struct node_t *head = NULL;
  Person *p1 = (Person *)malloc(sizeof(Person));
  strcpy(p1->sName, "John");
  strcpy(p1->sSurname, "Doe");
  strcpy(p1->sPnr, "19930813073948");
  strcpy(p1->sAddress, "John's street 12");
  p1->iAge = 12;
  Person *p2 = (Person *)malloc(sizeof(Person));
  strcpy(p2->sName, "Jane");
  strcpy(p2->sSurname, "Doe");
  strcpy(p2->sPnr, "19930813073925");
  strcpy(p2->sAddress, "John's street 12");
  p2->iAge = 20;
  InsertFirst(&head, p1);
  InsertFirst(&head, p2);
  printf("first: %d\n", head->person->iAge);
  printf("second: %d\n", head->next->person->iAge);
  deleteFirst(&head);
  printf("first: %d\n", head->person->iAge);
  // end

  int server_fd;                 // server file description
  int iSocket;                   // socket id
  struct sockaddr_in addrSocket; // socket's address
  int opt = 1;                   // broadcast, which is a standard protocol for IPv4

  int iAddrLen = sizeof(addrSocket);

  // Buffer for reading the message from client
  // This is the same as we will add the structure to it later on
  char strReadBuffer[1024] = {0};

  printf("\nInitialising socket\n");

  // Creating socket file descriptor
  // IPv4 and TCP
  if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    printErrnQuit("could not create socket");

  // specifying the protocols and addresses from which we accept the connections
  addrSocket.sin_family = AF_INET;         // protocol
  addrSocket.sin_addr.s_addr = INADDR_ANY; // address
  addrSocket.sin_port = htons(PORT);       // port

  // attaching socket to the port 8080
  if (bind(server_fd, (struct sockaddr *)&addrSocket, iAddrLen) < 0)
    printErrnQuit("could not bind");

  // now we just wait and listen for the connections from clients
  // the second parameter is the number of connections to be put in queue before rejecting them
  // here, we put 1
  if (listen(server_fd, 1) < 0)
    printErrnQuit("could not listen");

  // once we get a connect, we accept it
  iSocket = accept(server_fd, (struct sockaddr *)&addrSocket, (int *)&iAddrLen);

  // for fail-safe program, we check if the socket is actually created and the connection is accepted
  if (iSocket < 0)
    printErrnQuit("could not accept a connection");

  // after the accepted connection we can start the communication
  // this part is based on the fact that we wait for the message from the
  if (recv(iSocket, strReadBuffer, sizeof(strReadBuffer), 0) < 0)
    printErrnQuit("receiving the message from the client");

  // Now, here is where it gets interesting
  // we received a series of bytes, which we can print:
  printf("Message received: %s\n", strReadBuffer);

  // but we can also add the structure to it
  struct_person *sMyPerson;

  sMyPerson = (struct_person *)strReadBuffer;

  // and let's check what the name of the person is:
  printf("Person's name: %s \n", sMyPerson->name);
  printf("Person's address: %s \n", sMyPerson->address);
  printf("Person's age: %d \n", sMyPerson->iAge);
  exit(0);
}

void printErrnQuit(char *str) {
  printf("Error: %s: %s. Exiting\n", str, strerror(errno));
  exit(1);
}
