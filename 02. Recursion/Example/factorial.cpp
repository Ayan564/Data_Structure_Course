#include <iostream>
#include <stdio.h>
using namespace std;

// using Recursion

int fact1(int n)
{
    if (n == 0)
        return (1);
    else
        return n * fact1(n - 1);
}

// using loop

int fact2(int n)
{
    int i, m = 1;
    for (i = 1; i <= n; i++)
        m = m * i;
    return m;
}
int main()
{
    printf("%d\n", fact1(5));
    printf("%d\n", fact2(5));
    return 0;
}