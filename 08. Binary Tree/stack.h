#include "queue.h"
#ifndef stack_h
#define stack_h

struct stack
{
    int size;
    int top;
    struct Node **s;
};

void createStack(struct stack *st, int size)
{
    st->size = size;
    st->top = -1;
    st->s = (struct Node **)malloc(st->size * sizeof(struct Node *));
}

void push(struct stack *st, struct Node *x)
{
    if (st->top == st->size - 1)
    {
        printf("Stack is over flow");
    }
    else
    {
        st->top++;
        st->s[st->top] = x;
    }
}

struct Node *pop(struct stack *st)
{
    struct Node *x = NULL;
    if (st->top == -1)
    {
        printf("Stack is under flow");
    }
    else
    {
        x = st->s[st->top--];
    }
    return x;
}

int isFullStack(struct stack st)
{
    return st.top == st.size - 1;
}

// 5.Check Empty Condition

int isEmptyStack(struct stack st)
{
    if (st.top == -1)
        return 1;
    return 0;
}
#endif /* stack_h */