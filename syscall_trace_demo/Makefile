CC=gcc
CFLAGS=-Wall -Wextra -O2

all: syscall_trace_demo

syscall_trace_demo: syscall_trace_demo.c
	$(CC) $(CFLAGS) -o syscall_trace_demo syscall_trace_demo.c

clean:
	rm -f syscall_trace_demo
