#include <unistd.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    pid_t pid;

    pid = fork();

    if (pid < 0)
    {
        printf("fork error"); 
    }
    else if (pid > 0)
    {
        printf("at father process\n"); 
    }
    else
    {
        printf("at son process\n"); 
    }
}
