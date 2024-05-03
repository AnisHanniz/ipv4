CC = gcc
CFLAGS = -c

all: ipv4 ipv6

ipv4: ipv4.c
	$(CC) $(CFLAGS) ipv4.c
	$(CC) -o ipv4 ipv4.o

ipv6: ipv6.c
	$(CC) $(CFLAGS) ipv6.c
	$(CC) -o ipv6 ipv6.o

clean:
	rm -f ipv4 ipv6
	rm *.o
