CC = gcc
CFLAGS = -c

all: ipv4

ipv4: ipv4.c
	$(CC) $(CFLAGS) ipv4.c
	$(CC) -o ipv4 ipv4.o


clean:
	rm -f ipv4 
	rm *.o
