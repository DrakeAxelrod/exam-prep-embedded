# define the C compiler to use
CC=gcc
# define any compile-time flags
CFLAGS=-Wall -g
# define any directories containing header files other than /usr/include
# INCLUDES = -I/home/newhall/include  -I../include
# define library paths in addition to /usr/lib
#   if I wanted to include libraries not in /usr/lib I'd specify
#   their path using -Lpath, something like:
# LFLAGS=
# define any libraries to link into executable:
#   if I want to link in libraries (libx.so or libx.a) I use the -llibname 
#   option, something like (this will link in libmylib.so and libm.so:
LIBS=-lws2_32
FILE=server # change this to be client if you wanna build client

.PHONY: build run clean

build:
	$(CC) $(CFLAGS) $(FILE).c -o $(FILE) $(LIBS)

run:
	./$(FILE).exe

clean:
	del .\$(FILE).exe