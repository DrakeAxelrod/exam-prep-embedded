#ifndef COMMON_H_ // header if
#define COMMON_H_ // define the header

// ======= useful libs ======= //
#include <stdio.h>  // input & output
#include <stdlib.h> // standard library
// =========================== //

// ===== networking libs ===== //
#ifdef _WIN32
#include <winsock2.h>                // link to the winsock library, only for VC cl
#pragma comment(lib,"ws2_32.lib")   // Winsock Library
#else
#include <sys/socket.h> // linux lib for sockets
#include <netinet/in.h> // sockaddr_in type
// #include <fcntl.h>      // for open
#include <unistd.h>     // for close
// #include <errno.h>      // errorno
#endif

#include <fcntl.h> // for open
#include <errno.h> // errorno
// =========================== //

// ====== Utilility libs ===== //
#include <string.h> // working with strings
// =========================== //

// ========== Macros ========= //
// lambda macro
#define lambda(ret_type, _body) ({ ret_type _ _body _; })
//   Example:
//   int (*max) (int, int) = lambda (int, (int x, int y) {return x > y ? x : y;});
//   printf("%d", max(3,7));

// length of array macro
// cast to int to deal with unsigned long int
#define _len(x) ((int)(sizeof(x) / sizeof((x)[0])))
// =========================== //

// ========= functions ======= //
int main_sock();
void main_sock_struct();
// =========================== //

#endif // end the if
