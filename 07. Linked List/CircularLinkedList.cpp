#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct Node
{
    int data;
    struct Node *next;
} list;

list *Head, *p;

// 1.Creating a Linked List

void create()
{

    list *ptr1 = (list *)malloc(sizeof(list));
    printf("Enter data: ");
    scanf("%d", &ptr1->data);
    ptr1->next = Head;

    if (Head != NULL)
    {
        list *temp = Head;
        while (temp->next != Head)
            temp = temp->next;
        temp->next = ptr1;
    }
    else
    {
        ptr1->next = ptr1;
    }
    Head = ptr1;
}

// 2.Display of Linked List

void display()
{
    p = Head;
    printf("The Nodes are: ");
    if (Head != NULL)
    {
        do
        {
            printf("%d ", p->data);
            p = p->next;
        } while (p != Head);
    }

    printf("\n");
}

// 3.Counting Nodes in a Linked List

int count()
{
    p = Head;
    int c = 0;
    do
    {
        c++;
        p = p->next;
    } while (p != Head);
    return c;
}

// 4.Sum of elements in Linked List

int sum()
{
    p = Head;
    int sum = 0;
    do
    {
        sum = sum + p->data;
        p = p->next;
    } while (p != Head);
    return sum;
}

// 5.Max element in Linked List

int max()
{
    p = Head;
    int m = INT_MIN;
    do
    {
        if (p->data > m)
        {
            m = p->data;
        }
        p = p->next;
    } while (p != Head);
    return m;
}

// 6.Searching of element in Linked List

struct Node *search()
{
    int key;
    printf("Enter the key element: ");
    scanf("%d", &key);
    p = Head;
    do
    {
        if (key == p->data)
        {
            return p;
        }
        p = p->next;
    } while (p != Head);

    return NULL;
}

// 7.Insert at any position full function

void insertAnyPos()
{
    struct Node *t;
    p = Head;
    int index, num, i;
    printf("Enter the index and number: ");
    scanf("%d%d", &index, &num);
    if (index < 1 || index > count())
    {
        return;
    }
    if (index == 1)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = num;
        if (Head == NULL)
        {
            Head = t;
            Head->next = Head;
        }
        else
        {
            p = Head;
            while (p->next != Head)
                p = p->next;
            p->next = t;
            t->next = Head;
            Head = t;
        }
    }
    else
    {
        p = Head;
        for (i = 1; i < index - 1; i++)
        {
            p = p->next;
        }
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = num;
        t->next = p->next;
        p->next = t;
    }
}

// 8.Delete from any position full function

int deleteAnyPos()
{
    int i, x, index;
    p = Head;
    printf("Enter the index: ");
    scanf("%d", &index);
    struct Node *q;
    if (index < 0 || index > count())
        return -1;
    if (index == 1)
    {
        while (p->next != Head)
            p = p->next;
        x = Head->data;
        if (Head == p)
        {
            free(Head);
            Head = NULL;
        }
        else
        {
            p->next = Head->next;
            free(Head);
            Head = p->next;
        }
    }
    else
    {
        for (i = 0; i < index - 2; i++)
            p = p->next;
        q = p->next;
        p->next = q->next;
        x = q->data;
        free(q);
    }
    return x;
}

int main()
{

    int choice;
    while (1)
    {
        printf("\n 1.Create \n 2.Display \n 3.Count \n 4.Sum \n 5.Max \n 6.Search \n 7.Insert at any position \n 8.Delete from any position \n 9.To exit \n");
        printf("Enter Choice :\n");

        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            create();
            break;
        case 2:
            display();
            break;
        case 3:
            printf("The number of elements present in Linked List are: %d", count());
            break;
        case 4:
            printf("The sum of elements present in Linked List are: %d", sum());
            break;
        case 5:
            printf("The max element present in Linked List is: %d", max());
            break;
        case 6:
            search() ? printf("Element is present.") : printf("Element not present.");
            break;
        case 7:
            insertAnyPos();
            printf("Value inserted\n");
            break;
        case 8:
            deleteAnyPos();
            printf("Node deleted\n");
            break;
        case 9:
            exit(1);
        default:
            printf("Incorrect Choice\n");
        }
    }

    return 0;
}