#include <iostream>
using namespace std;

typedef struct alarm
{
    int a;
}Alarm;

int main()
{
    int* (*q)[3] = new int*[2][3];

    int***p = new int**[2];
    for (int i=0; i<2; i++)
    {
        p[i] = new int*[3];
    }

    int *z;
    z = new int[2*3];

    q[0][0] = 1;
    p[0][0] = 2;
//    z[0][0] = 3;

    return 0;
}
