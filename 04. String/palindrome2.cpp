#include <stdio.h>
#include <string.h>

// Check palindrome by compare the same string from last

int main()
{
    char A[100];
    printf("Enter the string: ");
    scanf("%[^\n]s", A);
    int l = 0;
    int h = strlen(A) - 1;

    while (h > l)
    {
        if (A[l++] != A[h--])
        {
            printf("%s is not a palindrome\n", A);
            return 0;
        }
    }

    printf("%s is a palindrome\n", A);
    return 0;
}