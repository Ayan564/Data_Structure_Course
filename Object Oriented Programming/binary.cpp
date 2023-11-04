#include <iostream>
#include <string>

using namespace std;

class binary
{
private:
    string s;
    int checkBinary();

public:
    void getBinary();

    void display();
};

void binary::getBinary()
{
    cout << "Enter a binary number: ";
    cin >> s;
}

int binary::checkBinary()
{
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] != '0' && s[i] != '1')
        {
            return -1;
        }
    }
}

void binary::display()
{
    if (checkBinary() == -1)
        cout << "Incorrect binary format " << endl;
    else
    {
        cout << "The binary nunmber is : ";
        for (int i = 0; i < s.length(); i++)
        {
            cout << s[i];
        }
    }
    cout << endl;
}
int main()
{
    binary b;
    b.getBinary();
    b.display();
    return 0;
}