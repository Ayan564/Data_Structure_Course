#include <stdio.h>
#include <iostream>
using namespace std;
int main()
{
    int A[] = {1, 2, 3, 4, 5}; // array initialization
    printf("The elements are : ");
    for (int x : A)
    {
        printf("%d ", x);
    }

    return 0;
}