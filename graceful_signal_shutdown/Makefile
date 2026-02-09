CC=gcc
CFLAGS=-Wall -Wextra -O2

all: graceful_signal_shutdown

graceful_signal_shutdown: graceful_signal_shutdown.c
	$(CC) $(CFLAGS) -o graceful_signal_shutdown graceful_signal_shutdown.c

clean:
	rm -f graceful_signal_shutdown
