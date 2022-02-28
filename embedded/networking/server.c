/*
 * Example of sending information via sockets.
 * In this example I will show you how to send the strings
 */

#include <stdio.h>
#include <stdlib.h>

// the code below shows the use of preprocessor directives
// when compiling the code
// this particular code says that different libraries/headers should be included
// if the system is WIN32, i.e. Visual Studio compiler
#ifdef _WIN32 
#include <winsock2.h>							 // link to the winsock library, only for VC cl
#pragma comment(lib, "ws2_32.lib") // Winsock Library
#else
#include <sys/socket.h>
#endif

// we listen to the port 8088
#define PORT 8088

/*
 * This procedure sets up the socket at the server side.
 */
int main(int argc, char const *argv[])
{

#ifdef _WIN32
	WSADATA wsa;
#endif

	int server_fd;								 // server file description
	int iSocket;									 // socket id
	struct sockaddr_in addrSocket; // socket's address
	int opt = 1;									 // broadcast, which is a standard protocol for IPv4

	int iAddrLen = sizeof(addrSocket);

	char strReadBuffer[1024] = {0};			// Buffer for reading the message from client
	char *strReply = "REPLY: Hello!\0"; // Our reply to the client

	printf("\nInitialising Winsock...\n");

#ifdef _WIN32
	if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
	{
		printf("Failed. Error Code : %d", WSAGetLastError());
		return 1;
	}
#endif

	printf("Initialised, waiting for request from clients... \n");

	// Creating socket file descriptor
	// IPv4 and TCP
	if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
	{
		printf("Error: Could not create socket: %s. Exiting...\n", strerror(errno));
		exit(1);
	}

	// Attaching the socket to our address
	if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)))
	{
		printf("Error: Could not attach: %s. Exiting...\n", strerror(errno));
		exit(1);
	}

	// specifying the protocols and addresses from which we accept the connections
	addrSocket.sin_family = AF_INET;				 // protocol
	addrSocket.sin_addr.s_addr = INADDR_ANY; // address
	addrSocket.sin_port = htons(PORT);			 // port

	// attaching socket to the port 8080
	if (bind(server_fd, (struct sockaddr *)&addrSocket, iAddrLen) < 0)
	{
		printf("Error: Could not bind: %s. Exiting...\n", strerror(errno));
		exit(1);
	}

	// now we just wait and listen for the connections from clients
	// the second parameter is the number of connections to be put in queue before rejecting them
	// here, we put 1
	if (listen(server_fd, 1) < 0)
	{
		printf("Error: Could not listen: %s. Exiting...\n", strerror(errno));
		exit(1);
	}

	// once we get a connect, we accept it
	iSocket = accept(server_fd, (struct sockaddr *)&addrSocket, (int *)&iAddrLen);

	// for fail-safe program, we check if the socket is actually created and the connection is accepted
	if (iSocket < 0)
	{
		printf("Error: Could not accept a connection: %s. Exiting...\n", strerror(errno));
		exit(1);
	}

	// after the accepted connection we can start the communication
	// this part is based on the fact that we wait for the message from the
	if (recv(iSocket, strReadBuffer, sizeof(strReadBuffer), 0) < 0)
	{
		printf("Error receiving the message from the client %s. Exiting..\n", strerror(errno));
		exit(1);
	}

	printf("Message received: %s\n", strReadBuffer);

	// send something over the socket
	if (send(iSocket, strReply, strlen(strReply), 0) < 0)
	{
		printf("Error sending the message to the client %s. Not really a problem on our side. \n", strerror(errno));
	}

	// Close the socket
#ifdef _WIN32
	closesocket(iSocket);
	WSACleanup();
#else
	close(iSocket);
#endif

	exit(0);
}