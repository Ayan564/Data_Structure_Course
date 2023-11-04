#include <stdio.h>

// Reverse the string in the same string

int main()
{
    char A[100], t;
    printf("Enter the string: ");
    scanf("%[^\n]s", A);
    int i, j;
    for (j = 0; A[j] != '\0'; j++)
    {
    }
    j -= 1;
    for (i = 0; i < j; i++, j--)
    {
        t = A[i];
        A[i] = A[j];
        A[j] = t;
    }
    printf("Reverse string is: %s", A);
    return 0;
}