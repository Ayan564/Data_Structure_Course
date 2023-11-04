#include <stdio.h>

void Insert(int A[], int n)
{
    int i = n;
    int temp = A[n];
    while (i > 0 && temp > A[i % 2 == 0 ? (i / 2) - 1 : i / 2])
    {
        A[i] = A[i % 2 == 0 ? (i / 2) - 1 : i / 2];
        i = i % 2 == 0 ? (i / 2) - 1 : i / 2;
    }
    A[i] = temp;
}

void createHeap(int A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        Insert(A, i);
    }
}

int main()
{
    printf("Array is: \n");
    int b[] = {10, 20, 30, 25, 5, 40, 35};
    for (int i = 0; i < 7; i++)
    {
        printf("%d\t", b[i]);
    }
    printf("\n");
    printf("Heap is: \n");
    createHeap(b, sizeof(b) / sizeof(b[0]));
    for (int i = 0; i < 7; i++)
    {
        printf("%d\t", b[i]);
    }
    return 0;
}