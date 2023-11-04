#include <stdio.h>
#include <string.h>
void swap(char *a, char *b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}

// Find permutations with the help of recursive method

void perm(char s[], int l, int h)
{
    int i;
    if (l == h)
        printf("%s\t", s);
    else
    {
        for (i = l; i <= h; i++)
        {
            swap(&s[l], &s[i]);
            perm(s, l + 1, h);
            swap(&s[l], &s[i]);
        }
    }
}
int main()
{
    char s[100];
    printf("Enter the string: ");
    gets(s);
    int i = strlen(s);
    perm(s, 0, i-1);
    return 0;
}