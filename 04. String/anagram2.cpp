#include <stdio.h>
#include <string.h>

// Checking anagram using hashtable

int main()
{
    char A[100], B[100];
    printf("Enter a string: ");
    gets(A);
    printf("Enter another string: ");
    gets(B);
    int i;
    int H[26] = {0};
    for (i = 0; A[i] != '\0'; i++)
    {
        H[A[i] - 97] += 1;
    }
    for (i = 0; B[i] != '\0'; i++)
    {
        H[A[i] - 97] -= 1;
        if (H[A[i] - 97] < 0)
        {
            printf("%s and %s are not anagrams!", A, B);
            break;
        }
    }
    if (B[i] == '\0')
        printf("%s and %s are anagrams!", A, B);

    return 0;
}