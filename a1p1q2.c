#include <stdio.h>
#include <string.h>
#define MAXLINE 128
#define MAXWORD 20
char buf[MAXLINE];
char main() {
        while (fgets(buf, MAXLINE, stdin) != NULL) {
                // Remove the newline character, if present

                size_t length = strlen(buf);
                if (length > 0 && buf[length-1] == '\n') {
                        buf[length-1] = '\0';
                }
                printf("Processed line: %s\n", buf);
        }
}
