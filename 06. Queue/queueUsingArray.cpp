#include <stdio.h>
#include <stdlib.h>
int queue[50], n, front, rear;
void enqueue()
{
    int element;
    if (rear == n - 1)
        printf("Queue is Full\n");
    else
    {
        if (rear == -1)
            front = 0;
        printf("Enter the element: ");
        scanf("%d", &element);
        rear++;
        queue[rear] = element;
        printf("Enter the element into the queue sucessfully\n");
    }
}
int dequeue()
{
    int x = -1;
    if (front == -1 || front > rear)
        printf("Queue is Empty\n");
    else
    {
        printf("Element deleted from queue is : %d", queue[front]);
        front++;
        x = front;
    }
    return x;
}
void display()
{
    int i;
    if (front == -1 || front > rear)
        printf("Queue is empty \n");
    else
    {
        printf("Queue is: ");
        for (i = front; i <= rear; i++)
            printf("%d ", queue[i]);
        printf("\n");
    }
}

int main()
{
    int choice;
    front = rear = -1;
    printf("Enter the size of the queue: ");
    scanf("%d", &n);

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