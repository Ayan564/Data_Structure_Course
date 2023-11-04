#include <iostream>
#include <stdio.h>
using namespace std;

// using Recursion

int pow1(int m, int n)
{
    if (n == 0)
        return (1);
    return m * pow1(m, n - 1);
}

// optimization of Recursion

int pow2(int m, int n)
{
    if (n == 0)
    {
        return 1;
    }

    if (n % 2 == 0)
    {
        return pow2(m * m, n / 2);
    }
    else
    {
        return m * pow2(m * m, (n - 1) / 2);
    }
}

// using loop

int pow3(int m, int n)
{
    int i, mul = 1;
    for (i = 1; i <= n; i++)
    {
        mul = mul * m;
    }
    return mul;
}
int main()
{
    printf("%d ", pow1(2, 9));
    printf("%d ", pow2(2, 9));
    printf("%d ", pow3(2, 9));
    return 0;
}