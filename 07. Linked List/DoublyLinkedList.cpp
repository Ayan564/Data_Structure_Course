#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;
} list;

list *head, *tail = NULL, *p;

// 1.Creating a Linked List

void create()
{
    list *newNode = (list *)malloc(sizeof(list));
    int x;
    printf("Enter data: ");
    scanf("%d", &x);
    newNode->data = x;

    // If list is empty
    if (head == NULL)
    {
        head = tail = newNode;
        head->prev = NULL;
        tail->next = NULL;
    }
    else
    {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
        tail->next = NULL;
    }
}

// 2.Display of Linked List

void display()
{
    p = head;
    printf("The nodes are: ");
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
}

// 3.Counting Nodes in a Linked List

int count()
{
    p = head;
    int c = 0;
    while (p != 0)
    {
        c++;
        p = p->next;
    }
    return c;
}

// 4.Sum of elements in Linked List

int sum()
{
    p = head;
    int sum = 0;
    while (p)
    {
        sum = sum + p->data;
        p = p->next;
    }
    return sum;
}

// 5.Max element in Linked List

int max()
{
    p = head;
    int m = INT_MIN;
    while (p)
    {
        if (p->data > m)
        {
            m = p->data;
        }
        p = p->next;
    }
    return m;
}

// 6.Searching of element in Linked List

list *search()
{
    int key;
    printf("Enter the key element: ");
    scanf("%d", &key);
    p = head;
    while (p != NULL)
    {
        if (key == p->data)
        {
            return p;
        }
        p = p->next;
    }
    return NULL;
}

// 7.Improve searching in Linked List using "Move to Head"

struct Node *impSearch()
{
    int key;
    printf("Enter the key element: ");
    scanf("%d", &key);
    p = head;
    list *q = NULL;
    while (p != NULL)
    {
        if (key == p->data)
        {
            q->next = p->next;
            p->next = head;
            head = p;
            return p;
        }
        q = p;
        p = p->next;
    }
}

// 8.Sorting of a Linked List

void sortingList()
{
    list *ptr1, *ptr2;
    int temp;
    ptr1 = head;
    while (ptr1 != NULL)
    {
        ptr2 = ptr1->next;
        while (ptr2 != NULL)
        {
            if (ptr1->data > ptr2->data)
            {
                temp = ptr1->data;
                ptr1->data = ptr2->data;
                ptr2->data = temp;
            }
            ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
    }
    printf("Sorting is complete.\n");
    return display();
}

// 9.Insert at first

void insertFirst()
{
    int num;
    p = (list *)malloc(sizeof(list));
    printf("Enter value to insert: ");
    scanf("%d", &num);
    p->data = num;
    p->prev = NULL;
    p->next = NULL;
    if (head == NULL)
        head = p;
    else
    {
        p->next = head;
        head->prev = p;
        head = p;
    }
    printf("Value inserted\n");
}

// 10.Insert at last

void insertLast()
{
    p = (list *)malloc(sizeof(list));
    int num;
    printf("Enter value to insert: ");
    scanf("%d", &num);
    p->data = num;
    p->prev = NULL;
    p->next = NULL;
    if (head == NULL)
        head = p;
    else
    {
        list *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        p->prev = temp;
        temp->next = p;
    }
    printf("Value inserted\n");
}

// 11.Insert after a given node

void afterInsert()
{
    list *temp, *q;
    int node, num;
    printf("Enter the node after which the Node will be inserted and the value to be inserted: ");
    scanf("%d%d", &node, &num);
    q = (list *)malloc(sizeof(list));
    q->data = num;
    q->next = NULL;
    q->prev = NULL;
    temp = head;
    while (temp != NULL && temp->data != node)
    {
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("Node is not found.");
    }
    else
    {
        q->next = temp->next;
        q->prev = temp;
        temp->next = q;
        temp->next->prev = q;
        printf("Value inserted\n");
    }
}

// 12.Insert before a given node

void brforeInsert()
{
    list *temp, *q, *p;
    int node, num;
    printf("Enter the node before which the Node will be inserted and the value to be inserted: ");
    scanf("%d%d", &node, &num);
    q = (list *)malloc(sizeof(list));
    q->data = num;
    q->next = NULL;
    q->prev = NULL;
    temp = head;
    while (temp != NULL && temp->data != node)
    {
        p = temp;
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("Node is not found.");
    }
    else
    {
        q->prev = temp->prev;
        temp->prev = q;
        q->next = temp;
        if (q->prev != NULL)
            q->prev->next = q;
        else
            head = q;
    }
    printf("Value inserted\n");
}

// 13.Insert at any position full function

void insertAnyPos()
{
    list *t;
    int index, num, i;
    printf("Enter the index and number: ");
    scanf("%d%d", &index, &num);
    if (index < 1 || index > count())
    {
        printf("Index is invalid.");
    }

    p = head;
    t = (list *)malloc(sizeof(list));
    t->data = num;

    if (index == 1)
    {
        t->prev = NULL;
        t->next = head;
        head->prev = t;
        head = t;
    }
    else
    {
        for (int i = 1; i < index - 1; i++)
        {
            p = p->next;
        }
        t->prev = p;
        t->next = p->next;
        if (p->next)
        {
            p->next->prev = t;
        }
        p->next = t;
    }
    printf("Value inserted\n");
}

// 14.Delete first node

void deleteFirst()
{
    p = head;
    int num;
    head = head->next;
    num = p->data;
    delete p;
    printf("Node deleted\n");
}

// 15.Delete last node

void deletelast()
{
    p = head;
    if (head == NULL)
        return;

    if (head->next == NULL)
    {
        delete (head);
        printf("Node deleted\n");
        return;
    }

    list *q = head;
    while (q->next->next != NULL)
        q = q->next;

    delete (q->next);
    printf("Node deleted\n");

    q->next = NULL;

    return;
}

// 16.Delete element after a given node

void afterDelete()
{
    int key, x;
    list *q, *temp, *t, *ptr;
    printf("Enter the node after which the Node will be deleted: ");
    scanf("%d", &key);
    q = (list *)malloc(sizeof(list));
    q->data = key;
    q->next = NULL;
    temp = head;
    while (temp != NULL && temp->data != key)
    {
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("Key is not found.");
    }
    else
    {
        if (temp->next == NULL)
        {
            printf("Deletion not posible because it is the last node.");
        }
        else if (temp->next->next == NULL)
        {
            temp->next = NULL;
            printf("Node Deleted\n");
        }
        else
        {
            ptr = temp->next;
            temp->next = ptr->next;
            ptr->next->prev = temp;
            delete (ptr);
            printf("Node Deleted\n");
        }
    }
}

// 17.Delete element before a given node

// void beforeDelete()
// {
//     int key;
//     struct Node *temp, *p;
//     printf("Enter the node before which the Node will be deleted: ");
//     scanf("%d", &key);
//     temp = head;
//     while (temp != NULL && temp->next->data != key)
//     {
//         p = temp;
//         temp = temp->next;
//     }
//     if (temp == NULL)
//     {
//         printf("Key is not found.");
//     }
//     else
//     {
//         if (temp == head)
//         {
//             deleteFirst();
//         }
//         else
//         {
//             p->next = temp->next;
//             delete temp;
//             printf("Node Deleted\n");
//         }
//     }
// }

// 18.Delete from any position full function

void deleteAnyPos()
{
    p = head;
    int i, index;
    printf("Enter the index: ");
    scanf("%d", &index);
    if (index < 1 || index > count())
    {
        printf("Index is invalid.");
    }
    if (index == 1)
    {
        head = head->next;
        if (head != NULL)
        {
            head->prev = NULL;
        }
        delete p;
        printf("Node deleted\n");
    }
    else
    {
        p = head;
        for (int i = 0; i < index - 1; i++)
        {
            p = p->next;
        }
        p->prev->next = p->next;
        if (p->next != NULL)
        {
            p->next->prev = p->prev;
        }
        delete p;
        printf("Node deleted\n");
    }
}

// 19.Reversing of a Linked List

void reverseElement()
{
    Node *p = head;
    Node *temp;
    while (p != NULL)
    {
        temp = p->next;
        p->next = p->prev;
        p->prev = temp;
        p = p->prev;

        // Need to check the following condition again
        if (p->next == NULL)
        {
            p->next = p->prev;
            p->prev = NULL;
            head = p;
            break;
        }
    }
    printf("Reverse complete");
}

int main()
{
    int choice;
    while (1)
    {
        printf("\n 1.Create \n 2.Display \n 3.Count \n 4.Sum \n 5.Max \n 6.Search \n 7.ImpSearch \n 8.Sorting of element \n 9.Insert at first \n 10.Inser at last \n 11.Inser element after a given node \n 12.Insert element before a given node \n 13.Insert at any position \n 14.Delete from first \n 15.Delete from last \n 16.Delete element after a given node \n 17.Delete element before a given node \n 18.Delete from any position \n 19.Reverse of Linked List \n 20.To exit \n");
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
            impSearch() ? printf("Element is present.") : printf("Element not present.");
            break;
        case 8:
            sortingList();
            break;
        case 9:
            insertFirst();
            break;
        case 10:
            insertLast();
            break;
        case 11:
            afterInsert();
            break;
        case 12:
            brforeInsert();
            break;
        case 13:
            insertAnyPos();
            break;
        case 14:
            deleteFirst();
            break;
        case 15:
            deletelast();
            break;
        case 16:
            afterDelete();
            break;
        // case 17:
        //     beforeDelete();
        //     break;
        case 18:
            deleteAnyPos();
            break;
        case 19:
            reverseElement();
            break;
        case 20:
            exit(1);
            break;
        default:
            printf("Incorrect Choice\n");
        }
    }
    return 0;
}