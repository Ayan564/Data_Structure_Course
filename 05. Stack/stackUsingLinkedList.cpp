#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
} *top = NULL;

// 1.Push element into the Stack

void push()
{
    int x;
    printf("Enter a value to be pushed: ");
    scanf("%d", &x);
    struct Node *t;
    t = (struct Node *)malloc(sizeof(struct Node));
    if (t == NULL)
        printf("stack is full\n");
    else
    {
        t->data = x;
        t->next = top;
        top = t;
    }
}

// 2.Pop element from the Stack

int pop()
{
    struct Node *t;
    int x = -1;
    if (top == NULL)
        printf("Stack is Empty\n");
    else
    {
        t = top;
        top = top->next;
        x = t->data;
        free(t);
    }
    return x;
}

// 3.Display element of the Stack

void display()
{
    struct Node *p;
    p = top;
    printf("The elements are: ");
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

// 4.Peek Element from stack

void peek()
{
    int pos;
    printf("Enter the position: ");
    scanf("%d", &pos);
    struct Node *ptr = top;
    for (int i = 0; (i < pos - 1 && ptr != NULL); i++)
    {
        ptr = ptr->next;
    }
    if (ptr != NULL)
    {
        printf("The peeked element at the position is %d", ptr->data);
    }
    else
    {
        printf("Invalid position.");
    }
}

// 7.Top element of the stack

void stackTop()
{
    printf("The top element of the stack is %d", top->data);
}

int main()
{
    int choice;
    while (1)
    {
        printf("\n 1.Push \n 2.Pop \n 3.Dispaly \n 4.Peek element \n 5.Top element of the stack\n 6.Exit \n");
        printf("\n Enter the Choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
        {
            push();
            break;
        }
        case 2:
        {
            printf("The popped elements is:%d ", pop());
            break;
        }
        case 3:
        {
            display();
            break;
        }
        case 4:
        {
            peek();
            break;
        }
        case 5:
        {
            stackTop();
            break;
        }
        case 6:
        {
            exit(1);
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
