#include <stdio.h>
#include <stdlib.h>
struct Queue
{
    int size;
    int front;
    int rear;
    int *Q;
};
int size;
void create(struct Queue *q)
{
    q->size = size;
    q->front = q->rear = 0;
    q->Q = (int *)malloc(q->size * sizeof(int));
}
void enqueue(struct Queue *q)
{
    int x;
    if ((q->rear + 1) % q->size == q->front)
        printf("Queue is Full\n");
    else
    {
        printf("Enter the element: ");
        scanf("%d", &x);
        q->rear = (q->rear + 1) % q->size;
        q->Q[q->rear] = x;
    }
}
int dequeue(struct Queue *q)
{
    int x = -1;
    if (q->front == q->rear)
        printf("Queue is Empty\n");
    else
    {
        q->front = (q->front + 1) % q->size;
        x = q->Q[q->front];
    }
    return x;
}
void display(struct Queue q)
{
    int i = q.front + 1;
    printf("Queue is: ");
    do
    {
        printf("%d ", q.Q[i]);
        i = (i + 1) % q.size;
    } while (i != (q.rear + 1) % q.size);
    printf("\n");
}
int main()
{
    struct Queue q;
    int choice;
    while (1)
    {
        printf("\n 1.Create \n 2.Enqueue \n 3.Dequeue \n 4.Display \n 5.Exit \n");
        printf("Enter the Choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
        {
            printf("Enter the size of the queue: ");
            scanf("%d", &size);
            create(&q);
            break;
        }
        case 2:
        {
            enqueue(&q);
            break;
        }
        case 3:
        {
            printf("The deleted element from the queue is %d\n", dequeue(&q));
            break;
        }
        case 4:
        {
            display(q);
            break;
        }
        case 5:
        {
            exit(0);
            break;
        }
        default:
        {
            printf("Incorrect Choice.\n");
        }
        }
    }
    return 0;
}
/*create(&q, 5);
enqueue(&q, 10);
enqueue(&q, 20);
enqueue(&q, 30);
enqueue(&q, 40);
enqueue(&q, 50);
enqueue(&q, 60);
Display(q);
printf("%d ", dequeue(&q));
return 0;*/