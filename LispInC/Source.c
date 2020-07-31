#include <stdio.h>

static char input[2048];

int main(int argc, char** argv) {
    printf();
    /* Print Version and Exit Information */
    puts("Lispy Version 0.0.0.0.1");
    puts("Press Ctrl+c to Exit\n");

    while (1) {
        fputs("Lisp but bad> ", stdout);
        
        // user string input, max chars to write, file stream to read from;
        fgets(input, sizeof(input), stdin);

        /* Echo input back to user */
        printf("echo> %s", input);
    }

    return 0;
}