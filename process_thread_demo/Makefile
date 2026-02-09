CC=gcc
CFLAGS=-Wall -Wextra -O2 -pthread

all: process_thread_demo

process_thread_demo: process_thread_demo.c
	$(CC) $(CFLAGS) -o process_thread_demo process_thread_demo.c

clean:
	rm -f process_thread_demo
