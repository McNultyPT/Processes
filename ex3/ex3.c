// Write another program using `fork()`. The child process should print "hello";
// the parent process should print "goodbye". You should ensure that the child
// process always prints first.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{
    int rc = fork();

    if (rc < 0) {
        printf(stderr, "Fork failed\n");
        exit(1);
    } else if (rc == 0) {
        printf("Child: %d\n", (int) getpid());
        printf("hello\n");
    } else {
        int wc = waitpid(rc, NULL, 0);
        printf("Parent %d of child %d\n", (int) getpid(), rc);
        printf("goodbye\n");
    }
    return 0;
}

// gcc -Wall -Wextra -o ex3 ex3.c
