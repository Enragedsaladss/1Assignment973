#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s (w|s)\n", argv[0]);
        return 1;
    }

    pid_t childPid = fork();
    if (childPid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (childPid == 0) {
        execlp("./myclock", "myclock", "out1", (char *) NULL);
        perror("execlp");
        exit(EXIT_FAILURE);
    }

    else {
        if (argv[1][0] == 'w') {
                int status;
                waitpid(childPid, &status, 0);

                if (WIFEXITED(status)) {
                        printf("Child process terminated with exit code: %d\n", WEXITSTATUS(status));
                }

                else if (WIFSIGNALED(status)) {
                        fprintf(stderr, "Child process terminated by signal: %d\n", WTERMSIG(status));
                }
        }

        else if (argv[1][0] == 's') {
            sleep(120);
        }

        else {
            fprintf(stderr, "Invalid option. Use 'w' or 's'.\n");
            return 1;
        }
    }

    return 0;
}
