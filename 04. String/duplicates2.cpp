#include <stdio.h>
#include <string.h>

// Find duplicates using hashtable

int main()
{
    char A[100];
    printf("Enter a string: ");
    scanf("%[^\n]s", A);
    printf("\nString is %s", A);
    int H[26] = {0};
    int i;
    for (i = 0; A[i] != '\0'; i++)
    {
        if (A[i] >= 97 && A[i] <= 122)
            H[A[i] - 97] += 1;
        else if (A[i] >= 65 && A[i] <= 90)
            H[A[i] - 65] += 1;
    }
    for (i = 0; i < 26; i++)
    {
        if (H[i] > 1)
            printf("\n%c is appearing: %d times", i + 65, H[i]);
    }
    return 0;
}