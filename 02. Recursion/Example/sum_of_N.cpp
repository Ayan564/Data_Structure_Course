#include <iostream>
#include <stdio.h>
using namespace std;

// using Recursion
int sum1(int n)
{
    if (n == 0)
        return 0;
    else
        return sum1(n - 1) + n;
}

// using formula
int sum2(int n)
{
    return n * ((n + 1) / 2);
}

// using loop

int sum3(int n)
{
    int i, s = 0;
    for (i = 0; i <= n; i++)
    {
        s = s + i;
    }
    return s;
}

int main()
{
    printf("%d\n", sum1(5));
    printf("%d\n", sum2(5));
    printf("%d\n", sum3(5));
    return 0;
}