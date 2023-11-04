#include <iostream>
#include <string.h>
using namespace std;
int main()
{
    char A[100];
    int i;
    printf("Enter the string: ");
    scanf("%[^\n]s", A);
    for (i = 0; A[i] != '\0'; i++)
    {
    }
    printf("Length of the string is: %d", i);
    return 0;
}