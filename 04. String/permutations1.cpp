#include <stdio.h>
#include <string.h>

// Find permutations with the help of iteretive method

void perm(char s[], int k)
{
    static int A[100] = {0};
    static char Res[100];
    int i;
    if (s[k] == '\0')
    {
        Res[k] = '\0';
        printf("%s\t", Res);
    }
    else
    {
        for (i = 0; s[i] != '\0'; i++)
        {
            if (A[i] == 0)
            {
                Res[k] = s[i];
                A[i] = 1;
                perm(s, k + 1);
                A[i] = 0;
            }
        }
    }
}
int main()
{
    char s[100];
    printf("Enter the string: ");
    scanf("%[^\n]s", s);
    perm(s, 0);
    return 0;
}