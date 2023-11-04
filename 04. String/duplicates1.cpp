#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Find duplicates compare with other element

int main()
{
    char A[100];
    printf("Enter a string: ");
    scanf("%[^\n]s", A);
    printf("\nString is %s", A);
    for (int i = 0; i <= strlen(A); i++)
    {
        int count = 1;
        for (int j = i + 1; A[j] != '\0'; j++)
        {
            if (A[i] == A[j])
            {
                count++;
                A[j] = -1;
            }
        }
        if (count > 1 && A[i] != -1)
        {
            printf("\n%c is appearing: %d times", A[i], count);
        }
    }
    return 0;
}