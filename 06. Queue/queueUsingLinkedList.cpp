#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
} *front = NULL, *rear = NULL;
void enqueue()
{
    int x;
    printf("Enter the element: ");
    scanf("%d", &x);
    struct Node *t;
    t = (struct Node *)malloc(sizeof(struct Node));
    if (t == NULL)
        printf("Queue is FUll\n");
    else
    {
        t->data = x;
        t->next = NULL;
        if (front == NULL)
            front = rear = t;
        else
        {
            rear->next = t;
            rear = t;
        }
        printf("Enter the element into the queue sucessfully\n");
    }
}
int dequeue()
{
    int x = -1;
    struct Node *t;
    if (front == NULL)
        printf("Queue is Empty\n");
    else
    {
        printf("Element deleted from queue is : %d", front->data);
        x = front->data;
        t = front;
        front = front->next;
        free(t);
    }
    return x;
}
void display()
{
    struct Node *p = front;
    printf("Queue is: ");
    while (p)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}
int main()
{
    int choice;
    while (1)
    {
        printf("\n 1.Enqueue \n 2.Dequeue \n 3.Display \n 4.Exit \n");
        printf("Enter the Choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
        {
            enqueue();
            break;
        }
        case 2:
        {
            dequeue();
            break;
        }
        case 3:
        {
            display();
            break;
        }
        case 4:
        {
            exit(0);
            break;
        }
        default:
        {
            printf("Incorrect Choice.");
        }
        }
    }
    return 0;
}