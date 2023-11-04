#include <iostream>
#include <string.h>
using namespace std;
int main()
{
    char A[100], B[100];
    int i, j;
    printf("Enter a string: ");
    // scanf("%[^\n]s", A);
    gets(A);
    printf("Enter another string: ");
    // scanf("%[^\n]s", B);
    gets(B);
    for (i = 0, j = 0; A[i] != '\0', B[i] != '\0'; i++, j++)
    {
        if (A[i] != B[j])
            break;
    }
    if (A[i] == B[j])
        printf("Both string are equal.");
    else if (A[i] < B[j])
        printf("First string is smaller.");
    else
        printf("First string is grater.");
    return 0;
}