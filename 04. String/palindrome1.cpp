#include <stdio.h>
#include <string>

// Check palindrome with the help of another string

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
    for (i = 0, j = 0; A[i] != '\0', B[i] != '\0'; i++, j++)
    {
        if (A[i] != B[j])
            break;
    }
    if (A[i] == B[j])
        printf("\nString is palindrome.");
    else
        printf("\nString is not palindrome.");
    return 0;
}