# define the C compiler to use
CC=gcc
# define any directories containing header files other than /usr/include
INCLUDES = -I"/home/draxel/Code/school/exam prep/embedded/LINUX/networking"
# define any compile-time flags
CFLAGS= -Wall -g
# define library paths in addition to /usr/lib
#   if I wanted to include libraries not in /usr/lib I'd specify
#   their path using -Lpath, something like:
# LFLAGS=
# define any libraries to link into executable:
#   if I want to link in libraries (libx.so or libx.a) I use the -llibname
#   option, something like (this will link in libmylib.so and libm.so:
LIBS=

.PHONY: build run clean

build:
	$(CC) $(CFLAGS) linkedlist.c server.c -o server $(INCLUDES)
	$(CC) $(CFLAGS) linkedlist.c client.c -o client $(INCLUDES)

run_server:
	./server

run_client:
	./client
clean:
	rm ./client ./server
