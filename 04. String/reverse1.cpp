#include <stdio.h>

// Store the reversed string in another string

int main()
{
    char A[100], B[100];
    printf("Enter the string: ");
    scanf("%[^\n]s", A);
    int i, j;
    for (i = 0; A[i] != '\0'; i++)
    {
    }
    i -= 1;
    for (j = 0; i >= 0; i--, j++)
    {
        B[j] = A[i];
    }
    B[j] = '\0';
    printf("Reverse string is:%s", B);
    return 0;
}