#include <iostream>
#include <stdio.h>
using namespace std;

// using recursion

double e1(int x, int n)
{
    static double s;
    if (n == 0)
    {
        return s;
    }
    else
    {
        s = 1 + x * s / n;
    }
    return e1(x, n - 1);
}

// using loop

double e2(int x, int n)
{
    double s = 1;
    // int i;
    // double num = 1;
    // double den = 1;
    // for (i=1; i<n; i++){
    //     num *=x;
    //     den *=i;
    //     s += num/den;
    // }

    for (; n > 0; n--)
    {
        s = 1 + x * s / n;
    }
    return s;
}

int main()
{
    cout << e1(2, 10) << endl;
    cout << e2(2, 10) << endl;
    return 0;
}