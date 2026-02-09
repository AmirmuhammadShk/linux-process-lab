#define _POSIX_C_SOURCE 200809L
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

int main(int argc, char *argv[]) {
    const char *file = "/etc/hosts";

    if (argc > 1) {
        file = argv[1];
    }

    int fd = open(file, O_RDONLY);
    if (fd < 0) {
        fprintf(stderr, "open failed: %s\n", strerror(errno));
        return 1;
    }

    char buf[256];
    ssize_t n = read(fd, buf, sizeof(buf));

    if (n < 0) {
        fprintf(stderr, "read failed: %s\n", strerror(errno));
        close(fd);
        return 1;
    }

    write(STDOUT_FILENO, buf, n);

    close(fd);
    return 0;
}
