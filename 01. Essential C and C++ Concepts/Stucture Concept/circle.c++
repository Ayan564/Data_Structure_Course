#include <iostream>
using namespace std;

struct circle
{
    int radius;
    int diameter;
};

int main()
{
    struct circle c = {4, 5};
    cout << c.radius << endl;
    cout << c.diameter << endl;
    return 0;
}