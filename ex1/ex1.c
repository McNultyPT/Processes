// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    int x = 100;

    printf("PID before fork is %d\n", (int) getpid());
    printf("Parent value for x is %d\n", x);

    int rc = fork();

    if (rc < 0) {
        printf(stderr, "Fork failed\n");
    } else if (rc == 0) {
        printf("If rc == 0 child PID is %d\n", (int) getpid());
        printf("Child value for x if rc == 0 is %d\n", x);
    } else {
       int x = 500;
       printf("If rc > 0 this is the parent PID %d of child %d\n", (int) getpid(), rc);
       printf("If rc > 0 the child value for x is %d\n", x); 
    }

    return 0;
}

// gcc -Wall -Wextra -o ex1 ex1.c
