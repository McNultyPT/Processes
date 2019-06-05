// Write a program that opens the text.txt file (with the `fopen()` library call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define FILENAME "text.txt"

int main(void)
{
    FILE *fp;

    fp = fopen(FILENAME, "r+");

    printf("%d\n", (int) getpid());

    int rc = fork();

    if (rc < 0) {
        fprintf(stderr, "Fork failed\n");
        exit(1);
    } else if (rc == 0) {
        printf("Child: %d\n", (int) getpid());
        fprintf(fp, "%s %s %s", "writing", "in", "child");
    } else {
        printf("Parent %d of child %d\n", (int) getpid(), rc);
        fprintf(fp, "%s %s %s", "writing", "in", "parent");
    }
    fclose(fp);
    
    return 0;
}

// gcc -Wall -Wextra -o ex2 ex2.c