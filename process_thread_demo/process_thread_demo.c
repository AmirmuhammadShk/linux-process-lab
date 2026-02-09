#define _GNU_SOURCE
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

typedef struct {
    const char *role;
    int id;
} thread_arg_t;

void* thread_worker(void *arg) {
    thread_arg_t *t = (thread_arg_t*)arg;

    printf("[%s] process pid=%d thread_id=%lu worker=%d\n",
           t->role,
           getpid(),
           (unsigned long)pthread_self(),
           t->id);

    usleep(200000);
    return NULL;
}

void run_threads(const char *role) {
    pthread_t threads[3];
    thread_arg_t args[3];

    for (int i = 0; i < 3; i++) {
        args[i].role = role;
        args[i].id = i;

        if (pthread_create(&threads[i], NULL, thread_worker, &args[i]) != 0) {
            perror("pthread_create");
            exit(1);
        }
    }

    for (int i = 0; i < 3; i++) {
        pthread_join(threads[i], NULL);
    }
}

int main() {
    printf("[main] parent pid=%d\n", getpid());

    pid_t pid = fork();

    if (pid < 0) {
        perror("fork");
        exit(1);
    }

    if (pid == 0) {
        // child
        printf("[main] child pid=%d parent=%d\n", getpid(), getppid());
        run_threads("child");
        _exit(0);
    } else {
        // parent
        run_threads("parent");

        int status;
        waitpid(pid, &status, 0);

        printf("[main] child exited with status=%d\n",
               WIFEXITED(status) ? WEXITSTATUS(status) : -1);
    }

    return 0;
}
