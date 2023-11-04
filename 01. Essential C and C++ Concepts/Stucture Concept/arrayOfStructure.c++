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
    struct card deck[4] = {{1, 0, 0}, {2, 3, 1}};
    cout << deck[3].shape;
    return 0;
}