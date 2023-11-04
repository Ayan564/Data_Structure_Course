#include <iostream>
#include <string.h>
using namespace std;
int main()
{
    char A[100];
    printf("Enter the string: ");
    scanf("%[^\n]s", A);
    for (int i = 0; A[i] != '\0'; i++)
    {
        if (A[i] >= 65 && A[i] <= 90)
            A[i] += 32;
        else if (A[i] >= 97 && A[i] <= 122)
            A[i] -= 32;
    }
    printf("The result strig is: %s", A);
    return 0;
}