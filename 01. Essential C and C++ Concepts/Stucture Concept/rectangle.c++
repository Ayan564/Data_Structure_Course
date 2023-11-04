#include <iostream>
#include <stdio.h>
using namespace std;
struct rectangle
{
    int length;
    int bredth;
    char x;
};

int main()
{
    struct rectangle r1 = {10, 5};
    printf("%d\n", sizeof(r1));
    cout << r1.length << endl;
    cout << r1.bredth << endl;
    r1.length = 15;
    r1.bredth = 7;
    cout << r1.length << endl;
    cout << r1.bredth << endl;
    cout << "area of the rectangle is = " << r1.length*r1.bredth;
    return 0;
}