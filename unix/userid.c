//#include <ourhdr.h>
#include <unistd.h>
#include <stdio.h>

int main()
{
    printf("uid is %d, gid is %d\n", getuid(), getgid());
}
