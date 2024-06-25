/**
 *A C program to demonstrate working of fork(), process table entries, and zombies.
 **/

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int main()
{
    int i;
    int pid = fork();
    if (pid == 0){
        //raise(SIGKILL);
        // kill(getpid(), SIGKILL);
        for (i=0; i<20; i++)
            printf("I am Child\n");
            
        printf("This is the main program running before the exec syscall");
        const char *file = "/home/davidkebo/2024_summer/week4/exec/operations/math_factorial";
        const char *arg2 = "Hello world!\n\nToday is Wednesday.";
        const char *arg1 = "-e";
        execl(file, file, arg1, arg2, NULL); // Executable + Path to the Binary + Rest of the options ... + NULL
    }
    else
    {
        //signal(SIGCHLD,SIG_IGN);  // LISTEN to a SIGCHLD signal and then do nothing
        printf("I am Parent\n");
        //while(1);
    }
}