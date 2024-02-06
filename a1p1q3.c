#include <stdio.h>
#include <errno.h>
#include <string.h>

int main() {
        // Your code here

        // Example of system call that might set errno
        FILE *file = fopen("nonexistent_file.txt", "r");

        if ( file == NULL) {

                int errorCode = errno;
                // Print the error message corresponding to errno
                fprintf(stdout, "Error opening file: %s\n", strerror(errno));
                fprintf(stdout, "Error code: %d\n", errorCode);
        }

        // Your code continues
        return 0;
}
