#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

struct Node
{
    struct Node *lchild;
    int data;
    struct Node *rchild;
} *root = NULL;

// Create and insert element in a BST using iteration

void create1()
{
    int key;
    printf("Enter the element: ");
    scanf("%d", &key);
    struct Node *t = root;
    struct Node *r, *p;

    if (root == NULL)
    {
        p = (struct Node *)malloc(sizeof(struct Node));
        p->data = key;
        p->lchild = p->rchild = NULL;
        root = p;
        return;
    }
    while (t != NULL)
    {
        r = t;
        if (key < t->data)
            t = t->lchild;
        else if (key > t->data)
            t = t->rchild;
        else
            return;
    }
    p = (struct Node *)malloc(sizeof(struct Node));
    p->data = key;
    p->lchild = p->rchild = NULL;

    if (key < r->data)
        r->lchild = p;
    else
        r->rchild = p;
}

// Create and insert element in a BST using recursion

struct Node *create2(struct Node *p, int key)
{
    struct Node *t;
    if (p == NULL)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = key;
        t->lchild = NULL;
        t->rchild = NULL;
        return t;
    }
    if (key < p->data)
    {
        p->lchild = create2(p->lchild, key);
    }
    else if (key > p->data)
    {
        p->rchild = create2(p->rchild, key);
    }
    return p;
}

// Search element in a BST using iteration

struct Node *search1()
{
    int key;
    printf("Enter the element: ");
    scanf("%d", &key);
    struct Node *t = root;
    while (t != NULL)
    {
        if (key == t->data)
            return t;
        else if (key < t->data)
            t = t->lchild;
        else
            t = t->rchild;
    }
    return NULL;
}

// Search element in a BST using recursion

struct Node *search2(struct Node *t, int key)
{
    if (t == NULL)
        return NULL;
    if (key == t->data)
        return t;
    else if (key < t->data)
        return search2(t->lchild, key);
    else
        return search2(t->rchild, key);
}

// Preorder traversal of BST using recursion

void preorder(struct Node *p)
{
    if (p)
    {
        printf("%d ", p->data);
        preorder(p->lchild);
        preorder(p->rchild);
    }
}

// Inorder traversal of BST using recursion

void inorder(struct Node *p)
{
    if (p)
    {
        inorder(p->lchild);
        printf("%d ", p->data);
        inorder(p->rchild);
    }
}

// Postorder traversal of BST using recursion

void postorder(struct Node *p)
{
    if (p)
    {
        postorder(p->lchild);
        postorder(p->rchild);
        printf("%d ", p->data);
    }
}

// Determine height of BST

int height(struct Node *p)
{
    int x, y;
    if (p == NULL)
        return 0;
    x = height(p->lchild);
    y = height(p->rchild);
    return x > y ? x + 1 : y + 1;
}

// Find inorder predecessor

struct Node *inpre(struct Node *p)
{
    while (p && p->rchild != NULL)
        p = p->rchild;

    return p;
}

// Find inorder succcessor

struct Node *inSucc(struct Node *p)
{
    while (p && p->lchild != NULL)
        p = p->lchild;

    return p;
}

// Delete element from BST

struct Node *Delete(struct Node *p)
{
    struct Node *q;
    int key;
    printf("Enter the element: ");
    scanf("%d", &key);
    if (p == NULL)
        return NULL;

    if (p->lchild == NULL && p->rchild == NULL)
    {
        if (p == root)
            root = NULL;
        delete p;
        return NULL;
    }
    if (key < p->data)
        p->lchild = Delete(p->lchild);
    else if (key > p->data)
        p->rchild = Delete(p->rchild);
    else
    {
        if (height(p->lchild) > height(p->rchild))
        {
            q = inpre(p->lchild);
            p->data = q->data;
            p->lchild = Delete(p->lchild);
        }
        else
        {
            q = inSucc(p->rchild);
            p->data = q->data;
            p->rchild = Delete(p->rchild);
        }
    }
    return p;
}

// Generate BST from preorder traversal

/*void createFromPreorder(int *pre, int n)
{

    // Create root node
    int i = 0;
    root = (struct Node *)malloc(sizeof(struct Node));
    root->data = pre[i++];
    root->lchild = NULL;
    root->rchild = NULL;

    // Iterative steps
    Node *t;
    Node *p = root;

    while (i < n)
    {
        // Left child case
        if (pre[i] < p->data)
        {
            t = (struct Node *)malloc(sizeof(struct Node));
            t->data = pre[i++];
            t->lchild = NULL;
            t->rchild = NULL;
            p->lchild = t;
            st.push(p);
            p = t;
        }
        else
        {
            // Right child cases
            if (pre[i] > p->data && pre[i] < st.isEmptyStack() ? 32767 : st.top()->data)
            {
                t = (struct Node *)malloc(sizeof(struct Node));
                t->data = pre[i++];
                t->lchild = NULL;
                t->rchild = NULL;
                p->rchild = t;
                p = t;
            }
            else
            {
                p = st.top();
                st.pop();
            }
        }
    }
}*/

int main()
{
    int choice, key;
    while (1)
    {
        printf("\n 1. Create BST using iteration \n 2. create BST using recursion \n 3. Search element in BST using iteration \n 4. Search element in BST using recursion \n 5. Preorder Traversal \n 6. Inorder Traversal \n 7. Postorder Traversal\n 8. Height of BST \n 9. Delete element from BST \n 10. Generate BST from preorder traversal \n 11.Exit");
        printf("\nEnter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            // 10 5 20 8 30
            create1();
            break;
        case 2:
            // 10 5 20 8 30
            printf("Enter the element: ");
            scanf("%d", &key);
            root = create2(root, key);
            break;
        case 3:
            search1() ? printf("Element is present.") : printf("Element is not present.");
            break;
        case 4:
            printf("Enter the element: ");
            scanf("%d", &key);
            search2(root, key) ? printf("Element is present.") : printf("Element is not present.");
            break;
        case 5:
            preorder(root);
            break;
        case 6:
            inorder(root);
            break;
        case 7:
            postorder(root);
            break;
        case 8:
            printf("Height of the BST is: %d", height(root));
            break;
        case 9:
            root = Delete(root);
            break;
        // case 10:
        //     printf("BST from Preorder: ");
        //     int pre[] = {30, 20, 10, 15, 25, 40, 50, 45};
        //     int n = sizeof(pre) / sizeof(pre[0]);
        //     createFromPreorder(pre, n);
        case 11:
            exit(1);
        default:
            printf("Incorrect choice.");
            break;
        }
    }
    return 0;
}