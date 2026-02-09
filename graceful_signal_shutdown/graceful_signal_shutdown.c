#define _POSIX_C_SOURCE 200809L
#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

static volatile sig_atomic_t stop = 0;

void handle_signal(int sig) {
    stop = 1;
}

int main() {
    struct sigaction sa;
    sa.sa_handler = handle_signal;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;

    if (sigaction(SIGINT, &sa, NULL) < 0) {
        perror("sigaction SIGINT");
        exit(1);
    }

    if (sigaction(SIGTERM, &sa, NULL) < 0) {
        perror("sigaction SIGTERM");
        exit(1);
    }

    printf("Running... pid=%d\n", getpid());
    printf("Press Ctrl+C or run: kill -TERM %d\n", getpid());

    int counter = 0;

    while (!stop) {
        printf("working %d\n", counter++);
        sleep(1);
    }

    printf("Signal received. Cleaning up...\n");
    sleep(1);
    printf("Shutdown complete.\n");

    return 0;
}
