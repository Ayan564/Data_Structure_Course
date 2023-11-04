#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
int main()
{
    int *A;
    // p = (int *)malloc((5 * sizeof(int)));    in c language
    A = new int[5]; // in c++ language
    A[0] = 10;
    A[1] = 15;
    A[2] = 14;
    A[3] = 21;
    A[4] = 31;
    for (int i = 0; i < 5; i++)
    {
        cout << A[i] << endl;
    }
    return 0;
}