#include <stdio.h>
#include <stdlib.h>
int stack[100], n, top, x, i;

// 1.Push element into the Stack

void push()
{
    if (top == n - 1)
    {
        printf("Stack is over flow");
    }
    else
    {
        printf("Enter a value to be pushed: ");
        scanf("%d", &x);
        top++;
        stack[top] = x;
    }
}

// 2.Pop element from the Stack

void pop()
{
    if (top == -1)
    {
        printf("Stack is under flow");
    }
    else
    {
        printf("The popped elements is %d", stack[top]);
        top--;
    }
}

// 3.Display element of the Stack

void display()
{
    if (top >= 0)
    {
        printf("The elements in Stack: ");
        for (i = top; i >= 0; i--)
            printf("%d ", stack[i]);
    }
    else
    {
        printf("The Stack is empty");
    }
}

// 4.Check Full condition

void isFull()
{
    if (top == n - 1)
        printf("Stack is Full.");
    else
        printf("Stack is not Full.");
}

// 5.Check Empty Condition

void isEmpty()
{
    if (top == -1)
        printf("Stack is Empty.");
    else
        printf("Stack is not Empty.");
}

// 6.Peek Element from stack

void peek()
{
    int index;
    printf("Enter the index: ");
    scanf("%d", &index);
    if (top == -1)
        printf("Stack is Empty.");
    else
    {
        if (top - index + 1 < 0)
            printf("Invalid Position.");
        else
            printf("The peek element is %d", stack[top - index + 1]);
    }
}

// 7.Top element of the stack

void stackTop()
{
    if (top == -1)
        printf("Stack is empty.");
    else
        printf("Top element of the stack is %d", stack[top]);
}

int main()
{
    int choice;
    top = -1;
    printf("Enter the size of Stack[MAX=100]:");
    scanf("%d", &n);
    while (1)
    {
        printf("\n 1.Push \n 2.Pop \n 3.Display \n 4.Check full Condition \n 5.Check empty condition \n 6.Peek element \n 7.Top element of the stack \n 8.Exit \n");
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
            pop();
            break;
        }
        case 3:
        {
            display();
            break;
        }
        case 4:
        {
            isFull();
            break;
        }
        case 5:
        {
            isEmpty();
            break;
        }
        case 6:
        {
            peek();
            break;
        }
        case 7:
        {
            stackTop();
            break;
        }
        case 8:
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
