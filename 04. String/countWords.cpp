#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    char A[100];
    int word = 0, i;

    printf("Enter the string: ");
    scanf("%[^\n]s", A);
    for (i = 0; A[i] != '\0'; i++)
    {
        if (A[i] == ' ' && A[i + 1] != ' ')
            word++;
    }
    printf("Number of words in given string are: %d\n", word + 1);
    return 0;
}