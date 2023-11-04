#include <iostream>
#include <stdio.h>
using namespace std;

struct card
{
    int face;
    int shape;
    int color;
};

int main()
{
    struct card c;
    cout << sizeof(c) << endl;
    c.face = 3;
    c.shape = 2;
    c.color = 0;
    printf("%d\n", c.face);
    printf("%d\n", c.shape);
    printf("%d\n", c.color);

    return 0;
}