#include <iostream>
#include <stdio.h>
using namespace std;

// using Recursion

int fib1(int n)
{
    if (n <= 1)
    {
        return n;
    }
    else
    {
        return fib1(n - 2) + fib1(n - 1);
    }
}

// using Loop

int fib2(int n)
{
    int t0 = 0, t1 = 1, s = 0, i;
    if (n <= 1)
    {
        return n;
    }
    for (i = 2; i <= n; i++)
    {
        s = t0 + t1;
        t0 = t1;
        t1 = s;
    }
    return s;
}

// using Optimized Resursion(Memoization)

int F[10];
int fib3(int n)
{
    if (n <= 1)
    {
        F[n] = n;
        return n;
    }
    else
    {
        if (F[n - 2] == -1)
        {
            F[n - 2] = fib3(n - 2);
        }
        if (F[n - 1] == -1)
        {
            F[n - 1] = fib3(n - 1);
        }
        F[n] = F[n - 2] + F[n - 1];
        return F[n - 2] + F[n - 1];
    }
}
int main()
{

    cout << fib1(6) << endl;
    cout << fib2(6) << endl;
    for (int i = 0; i < 10; i++)
    {
        F[i] = -1;
    }
    cout << fib3(6) << endl;
    return 0;
}