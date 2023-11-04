#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "stack.h"
struct Node *root = NULL;

// Create a binary tree

void create()
{
    struct Node *p, *t;
    int x;
    struct Queue q;
    create(&q, 100);
    printf("Eneter root value ");
    scanf("%d", &x);
    root = (struct Node *)malloc(sizeof(struct Node));
    root->data = x;
    root->lchild = root->rchild = NULL;
    enqueue(&q, root);
    while (!isEmpty(q))
    {
        p = dequeue(&q);
        printf("eneter left child of %d ", p->data);
        scanf("%d", &x);
        if (x != -1)
        {
            t = (struct Node *)malloc(sizeof(struct Node));
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            enqueue(&q, t);
        }
        printf("eneter right child of %d ", p->data);
        scanf("%d", &x);
        if (x != -1)
        {
            t = (struct Node *)malloc(sizeof(struct Node));
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->rchild = t;
            enqueue(&q, t);
        }
    }
}

// Preorder traversal of binary tree using iteration

void preorder1(struct Node *p)
{
    struct stack st;
    createStack(&st, 100);
    while (p != NULL || !isEmptyStack(st))
    {
        if (p != NULL)
        {
            printf("%d ", p->data);
            push(&st, p);
            p = p->lchild;
        }
        else
        {
            p = pop(&st);
            p = p->rchild;
        }
    }
}

// Preorder traversal of binary tree using recursion

void preorder2(struct Node *p)
{
    if (p)
    {
        printf("%d ", p->data);
        preorder2(p->lchild);
        preorder2(p->rchild);
    }
}

// Inorder traversal of binary tree using iteration

void inorder1(struct Node *p)
{
    struct stack st;
    createStack(&st, 100);
    while (p != NULL || !isEmptyStack(st))
    {
        if (p != NULL)
        {
            push(&st, p);
            p = p->lchild;
        }
        else
        {
            p = pop(&st);
            printf("%d ", p->data);
            p = p->rchild;
        }
    }
}

// Inorder traversal of binary tree using recursion

void inorder2(struct Node *p)
{
    if (p)
    {
        inorder2(p->lchild);
        printf("%d ", p->data);
        inorder2(p->rchild);
    }
}

// Postorder traversal of binary tree using iteration

void postorder1(struct Node *p)
{
    struct stack st;
    createStack(&st, 100);
    long int temp;
    while (p != NULL || !isEmptyStack(st))
    {
        if (p != NULL)
        {
            push(&st, p);
            p = p->lchild;
        }
        else
        {
            temp = (long int)pop(&st);
            if (temp > 0)
            {
                push(&st, (Node *)-temp);
                p = ((Node *)temp)->rchild;
            }
            else
            {
                printf("%d ", ((Node *)temp)->data);
                p = NULL;
            }
        }
    }
    printf("\n");
}

// Postorder traversal of binary tree using recursion

void postorder2(struct Node *p)
{
    if (p)
    {
        postorder2(p->lchild);
        postorder2(p->rchild);
        printf("%d ", p->data);
    }
}

// Levelorder traversal of binary tree

void levelOrder(struct Node *root)
{
    struct Queue q;
    create(&q, 100);
    printf("%d ", root->data);
    enqueue(&q, root);
    while (!isEmpty(q))
    {
        root = dequeue(&q);
        if (root->lchild)
        {
            printf("%d ", root->lchild->data);
            enqueue(&q, root->lchild);
        }
        if (root->rchild)
        {
            printf("%d ", root->rchild->data);
            enqueue(&q, root->rchild);
        }
    }
}

// Count the total no of nodes in a binary tree

int count(struct Node *p)
{
    int x, y;
    if (p != NULL)
    {
        x = count(p->lchild);
        y = count(p->rchild);
        return x + y + 1;
    }
    return 0;
}

// Sum of all nodes in a binary tree

int sum(struct Node *p)
{
    int x, y;
    if (p != NULL)
    {
        x = sum(p->lchild);
        y = sum(p->rchild);
        return x + y + p->data;
    }
    return 0;
}

// Height of a binary tree

int height(struct Node *p)
{
    int x, y;
    if (p != NULL)
    {
        x = height(p->lchild);
        y = height(p->rchild);
        if (x > y)
            return x + 1;
        else
            return y + 1;
    }
    return 0;
}

// Count the total no of leaf nodes in a binary tree (degree 0)

int countLeaf(struct Node *p)
{
    int x, y;
    if (p != NULL)
    {
        x = countLeaf(p->lchild);
        y = countLeaf(p->rchild);
        if (p->lchild == NULL && p->rchild == NULL)
        {
            return x + y + 1;
        }
        else
        {
            return x + y;
        }
    }
    return 0;
}

// Count the total no of nodes in a binary tree with degree 2

int countDeg2(struct Node *p)
{
    int x, y;
    if (p != NULL)
    {
        x = countDeg2(p->lchild);
        y = countDeg2(p->rchild);
        if (p->lchild != NULL && p->rchild != NULL)
        {
            return x + y + 1;
        }
        else
        {
            return x + y;
        }
    }
    return 0;
}

// Count the total no of nodes in a binary tree with degree 1 or 2

int countDeg1_2(struct Node *p)
{
    int x, y;
    if (p != NULL)
    {
        x = countDeg1_2(p->lchild);
        y = countDeg1_2(p->rchild);
        if (p->lchild != NULL || p->rchild != NULL)
        {
            return x + y + 1;
        }
        else
        {
            return x + y;
        }
    }
    return 0;
}

// Count the total no of nodes in a binary tree with degree 1 method 1

int countDeg1_method1(struct Node *p)
{
    int x, y;
    if (p != NULL)
    {
        x = countDeg1_method1(p->lchild);
        y = countDeg1_method1(p->rchild);
        if ((p->lchild != NULL && p->rchild == NULL) || (p->lchild == NULL && p->rchild != NULL))
        {
            return x + y + 1;
        }
        else
        {
            return x + y;
        }
    }
    return 0;
}

// Count the total no of nodes in a binary tree with degree 1 method 2

int countDeg1_method2(struct Node *p)
{
    int x, y;
    if (p != NULL)
    {
        x = countDeg1_method2(p->lchild);
        y = countDeg1_method2(p->rchild);
        if ((p->lchild != NULL ^ p->rchild != NULL))
        {
            return x + y + 1;
        }
        else
        {
            return x + y;
        }
    }
    return 0;
}

int main()
{
    int choice;
    while (1)
    {
        printf("\n 1. Create a binary tree \n 2. Preorder Traversal using iteration \n 3. Preorder Traversal using recursion \n 4. Inorder Traversal using iteration \n 5. Inorder Traversal using recursion \n 6. Postorder Traversal using iteration \n 7. Postorder Traversal using recursion \n 8. Levelorder Traversal \n 9. Count no of nodes \n 10. Sum of all nodes \n 11. Height of the tree \n 12. Count no of leaf nodes \n 13. Count no of nodes with degree 2 \n 14. Count no of nodes with degree 1 or 2 \n 15. Count no of nodes with degree 1 (method 1) \n 16. Count no of nodes with degree 1 (method 2) \n 17.Exit");
        printf("\nEnter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            create();
            break;
        case 2:
            preorder1(root);
            break;
        case 3:
            preorder2(root);
            break;
        case 4:
            inorder1(root);
            break;
        case 5:
            inorder2(root);
            break;
        case 6:
            postorder1(root);
            break;
        case 7:
            postorder2(root);
            break;
        case 8:
            levelOrder(root);
            break;
        case 9:
            printf("Total no of nodes in the tree is: %d", count(root));
            break;
        case 10:
            printf("Sum of all nodes in the tree is: %d", sum(root));
            break;
        case 11:
            printf("Height of the tree is: %d", height(root));
            break;
        case 12:
            printf("Total no of leaf nodes in the tree is: %d", countLeaf(root));
            break;
        case 13:
            printf("Total no of nodes in the tree with degree 2 is: %d", countDeg2(root));
            break;
        case 14:
            printf("Total no of nodes in the tree with degree 1 or 2 is: %d", countDeg1_2(root));
            break;
        case 15:
            printf("Total no of nodes in the tree with degree 1 (method 1) is: %d", countDeg1_method1(root));
            break;
        case 16:
            printf("Total no of nodes in the tree with degree 1 (method 2) is: %d", countDeg1_method2(root));
            break;
        case 17:
            exit(1);
        default:
            printf("Incorrect choice.");
            break;
        }
    }
    return 0;
}