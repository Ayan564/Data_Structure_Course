#include <stdio.h>
#include <string.h>

// It's an appropriate duplicate finding, but not find how many times it'll occur

int main()
{
    char A[100];
    int H = 0, x = 0, i;
    printf("Enter a string: ");
    scanf("%[^\n]s", A);
    printf("String is %s\n", A);
    for (i = 0; A[i] != '\0'; i++)
    {
        x = 1;
        x = x << (A[i] - 97);
        if ((x & H) > 0)
        {
            printf("%c is duplicate\n", A[i]);
        }
        else
            H = x | H;
    }
    return 0;
}