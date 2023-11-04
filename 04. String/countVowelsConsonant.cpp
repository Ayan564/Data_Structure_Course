#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    char A[100];
    int vCount = 0, cCount = 0, i;

    printf("Enter the string: ");
    scanf("%[^\n]s", A);
    for (i = 0; A[i] != '\0'; i++)
    {
        if (A[i] == ' ')
            continue;
        if (A[i] == 'a' || A[i] == 'e' || A[i] == 'i' || A[i] == 'o' || A[i] == 'u' || A[i] == 'A' || A[i] == 'E' || A[i] == 'I' || A[i] == 'O' || A[i] == 'U')
            vCount++;
        else if ((A[i] >= 65 && A[i] <= 90) || A[i] >= 97 || A[i] <= 122)
            cCount++;
    }
    printf("Number of vowels in given string are: %d\n", vCount);
    printf("Number of consonants in given string are: %d\n", cCount);
    return 0;
}