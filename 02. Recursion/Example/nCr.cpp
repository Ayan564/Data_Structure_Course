#include <iostream>
#include <stdio.h>
using namespace std;

// using Formula

int fact(int n)
{
    if (n == 0)
        return (1);
    else
        return n * fact(n - 1);
}

int c1(int n, int r)
{
    int num, den;
    num = fact(n);
    den = fact(r) * fact(n - r);

    return num / den;
}

// using Recursion

int c2(int n, int r)
{
    if (r == 0 || r == n)
    {
        return (1);
    }
    else
    {
        return (c2(n - 1, r - 1) + c2(n - 1, r));
    }
}
int main()
{
    cout << c1(5, 3) << endl;
    cout << c2(5, 3) << endl;

    return 0;
}