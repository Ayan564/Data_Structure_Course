#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Node
{
    int data;
    struct Node *next;
};
struct Node *first, *p, *second, *third, *q = NULL;
;

// 1.Creating a Linked List

void create()
{
    struct Node *temp;

    temp = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter data: ");
    scanf("%d", &temp->data);
    temp->next = NULL;
    if (first == NULL)
    {
        first = temp;
    }
    else
    {
        struct Node *p = first;
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = temp;
    }
}

// 29.Create List for concatination

void createConcatinate()
{
    struct Node *temp;

    temp = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter data: ");
    scanf("%d", &temp->data);
    temp->next = NULL;
    if (second == NULL)
    {
        second = temp;
    }
    else
    {
        struct Node *p = second;
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = temp;
    }
}

// 30.Display List for concatination

void displayConcatinate()
{
    p = second;
    printf("The Nodes are: ");
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

// 2.Display of Linked List

void display()
{
    p = first;
    printf("The Nodes are: ");
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

// 33.Display of Linked List for Marging

void displayMarging()
{
    p = third;
    printf("The Nodes are: ");
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

// 3.Display of Linked List using Recursion

void RDisplay(struct Node *p)
{
    if (p != NULL)
    {
        printf("%d ", p->data);
        RDisplay(p->next);
    }
}

// 4.Counting Nodes in a Linked List

int count()
{
    p = first;
    int c = 0;
    while (p != 0)
    {
        c++;
        p = p->next;
    }
    return c;
}

// 5.Counting Nodes in a Linked List using Recursion

int Rcount(struct Node *p)
{
    if (p == 0)
    {
        return 0;
    }
    else
    {
        return Rcount(p->next) + 1;
    }
}

// 6.Sum of elements in Linked List

int sum()
{
    p = first;
    int sum = 0;
    while (p)
    {
        sum = sum + p->data;
        p = p->next;
    }
    return sum;
}

// 7.Sum of elements in Linked List using Recursion

int Rsum(struct Node *p)
{
    if (p == 0)
    {
        return 0;
    }
    else
    {
        return Rsum(p->next) + p->data;
    }
}

// 8.Max element in Linked List

int max()
{
    p = first;
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

// 9.Max element in Linked List usingn Recursion

int Rmax(struct Node *p)
{
    int x = 0;
    if (p == 0)
    {
        return INT_MIN;
    }
    else
    {
        x = Rmax(p->next);
        if (x > p->data)
        {
            return x;
        }
        else
        {
            return p->data;
        }
    }
}

// 10.Searching of element in Linked List

struct Node *search()
{
    int key;
    printf("Enter the key element: ");
    scanf("%d", &key);
    p = first;
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

// 11.Searching of element in Linked List using Recursion

struct Node *Rsearch(struct Node *p, int key)
{
    if (p == NULL)
        return NULL;

    if (key == p->data)
        p = p->next;
    return Rsearch(p->next, key);
}

// 12.Improve searching in Linked List using "Move to Head"

struct Node *impSearch()
{
    int key;
    printf("Enter the key element: ");
    scanf("%d", &key);
    p = first;
    struct Node *q = NULL;
    while (p != NULL)
    {
        if (key == p->data)
        {
            q->next = p->next;
            p->next = first;
            first = p;
            return p;
        }
        q = p;
        p = p->next;
    }
}

// 13.Sorting of a Linked List

void sorting()
{
    struct Node *ptr, *cpt;
    int temp;
    ptr = first;
    while (ptr != NULL)
    {
        cpt = ptr->next;
        while (cpt != NULL)
        {
            if (ptr->data > cpt->data)
            {
                temp = ptr->data;
                ptr->data = cpt->data;
                cpt->data = temp;
            }
            cpt = cpt->next;
        }
        ptr = ptr->next;
    }
    printf("Sorting is complete.\n");
    return display();
}

// 14.Insert at first

void insertFirst()
{
    int num;
    p = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter value to insert: ");
    scanf("%d", &num);
    p->data = num;
    p->next = first;
    first = p;
    printf("Value inserted\n");
}

// 15.Insert at last

void insertLast()
{
    p = (struct Node *)malloc(sizeof(struct Node));
    struct Node *temp = first;
    int num;
    printf("Enter value to insert: ");
    scanf("%d", &num);
    p->data = num;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = p;
    p->next = NULL;
    printf("Value inserted\n");
}

// 16.Insert after a given node

void afterInsert()
{
    struct Node *temp, *q;
    int node, num;
    printf("Enter the node after which the Node will be inserted and the value to be inserted: ");
    scanf("%d%d", &node, &num);
    q = (struct Node *)malloc(sizeof(struct Node));
    q->data = num;
    q->next = NULL;
    temp = first;
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
        temp->next = q;
        printf("Value inserted\n");
    }
}

// 17.Insert before a given node

void brforeInsert()
{
    struct Node *temp, *q, *p;
    int node, num;
    printf("Enter the node before which the Node will be inserted and the value to be inserted: ");
    scanf("%d%d", &node, &num);
    q = (struct Node *)malloc(sizeof(struct Node));
    q->data = num;
    q->next = NULL;
    temp = first;
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
        q->next = p->next;
        p->next = q;
        printf("Value inserted\n");
    }
}

// 18.Insert at any position full function

void insertAnyPos()
{
    struct Node *t;
    p = first;
    int index, num, i;
    printf("Enter the index and number: ");
    scanf("%d%d", &index, &num);
    if (index < 1 || index > count())
    {
        return;
    }
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = num;

    if (index == 1)
    {
        t->next = first;
        first = t;
    }
    else
    {
        p = first;
        for (i = 1; i < index - 1; i++)
        {
            p = p->next;
        }
        t->next = p->next;
        p->next = t;
    }
    printf("Value inserted\n");
}

// 19.Insert in a sorted Linked List

void sortedInsert()
{
    p = first;
    int num;
    printf("Enter value to insert: ");
    scanf("%d", &num);
    struct Node *t, *q = NULL;
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = num;
    t->next = NULL;

    if (first == NULL)
    {
        first = t;
    }
    else
    {
        while (p && p->data < num)
        {
            q = p;
            p = p->next;
        }
        if (p == first)
        {
            t->next = first;
            first = t;
        }
        else
        {
            t->next = q->next;
            q->next = t;
        }
    }
    printf("Value inserted\n");
}

// 20.Delete first node

void deleteFirst()
{
    p = first;
    int num;
    first = first->next;
    num = p->data;
    delete p;
    printf("Node deleted\n");
}

// 21.Delete last node

void deletelast()
{
    p = first;
    if (first == NULL)
        return;

    if (first->next == NULL)
    {
        delete (first);
        printf("Node deleted\n");
        return;
    }

    struct Node *q = first;
    while (q->next->next != NULL)
        q = q->next;

    delete (q->next);
    printf("Node deleted\n");

    q->next = NULL;

    return;
}

// 22.Delete element after a given node

void afterDelete()
{
    int key;
    struct Node *q, *temp, *t;
    printf("Enter the node after which the Node will be deleted: ");
    scanf("%d", &key);
    q = (struct Node *)malloc(sizeof(struct Node));
    q->data = key;
    q->next = NULL;
    temp = first;
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
        else
        {
            t = temp->next;
            temp->next = t->next;
            delete p;
            printf("Node Deleted\n");
        }
    }
}

// 23.Delete element beore a given node

void beforeDelete()
{
    int key;
    struct Node *temp, *p;
    printf("Enter the node before which the Node will be deleted: ");
    scanf("%d", &key);
    temp = first;
    while (temp != NULL && temp->next->data != key)
    {
        p = temp;
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("Key is not found.");
    }
    else
    {
        if (temp == first)
        {
            deleteFirst();
        }
        else
        {
            p->next = temp->next;
            delete temp;
            printf("Node Deleted\n");
        }
    }
}

// 24.Delete from any position full function

void deleteAnyPos()
{
    p = first;
    struct Node *q;
    int i, index;
    printf("Enter the index: ");
    scanf("%d", &index);
    if (index < 1 || index > count())
    {
        printf("Index is invalid.");
    }

    if (index == 1)
    {
        first = first->next;
        delete p;
        printf("Node deleted\n");
    }
    else
    {
        p = first;
        q = NULL;
        for (i = 0; i < index - 1 && p; i++)
        {
            q = p;
            p = p->next;
        }
        if (p)
        {
            q->next = p->next;
            delete p;
            printf("Node deleted\n");
        }
    }
}

// 25.Check a Linked List is sorted

int checkSorted()
{
    int x = INT_MIN;
    struct Node *p = first;
    while (p != NULL)
    {
        if (p->data < x)
        {
            return 0;
        }
        x = p->data;
        p = p->next;
    }
    return 1;
}

// 26.Remove duplicate from a Linked List

void removeDuplicate()
{
    struct Node *ptr1, *ptr2, *dup;
    ptr1 = first;

    while (ptr1 != NULL && ptr1->next != NULL)
    {
        ptr2 = ptr1;
        while (ptr2->next != NULL)
        {
            if (ptr1->data == ptr2->next->data)
            {
                dup = ptr2->next;
                ptr2->next = ptr2->next->next;
                delete (dup);
            }
            else
                ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
    }
    printf("All duplicates are removed.\n");
    display();
}

// 27.Reversing of a Linked List

void reverseElement()
{
    struct Node *curr, *n;
    p = NULL;
    curr = first;
    while (curr != NULL)
    {
        n = curr->next;
        curr->next = p;
        p = curr;
        curr = n;
    }
    first = p;
    printf("Reverse complete");
}

// 28.Reversing of a Linked List using Recursion

void RReverseElement(struct Node *q, struct Node *p)
{
    if (p != NULL)
    {
        RReverseElement(p, p->next);
        p->next = q;
    }
    else
        first = q;
}
// 31.Concatenating if two Linked List

void concatination()
{
    p = first;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = second;
    second = NULL;
    printf("Two List are Concatinated");
}

// // 32.Marging of two Linked List

void marging()
{
    struct Node *last;
    if (first->data < second->data)
    {
        third = last = first;
        first = first->next;
        third->next = NULL;
    }
    else
    {
        third = last = second;
        second = second->next;
        third->next = NULL;
    }
    while (first != NULL && second != NULL)
    {
        if (first->data < second->data)
        {
            last->next = first;
            last = first;
            first = first->next;
            last->next = NULL;
        }
        else
        {
            last->next = second;
            last = second;
            second = second->next;
            last->next = NULL;
        }
    }
    if (first != NULL)
    {
        last->next = first;
    }
    else
    {
        last->next = second;
    }
    printf("Marging is complete.");
}

// 33.Check for loop in Linked List

int checkLoop()
{
    struct Node *p, *q;
    p = q = first;
    do
    {
        p = p->next;
        q = q->next;
        q = q ? q->next : q;
    } while (p && q);
    return p == q ? printf("List is in Loop.") : printf("List is not in Loop.");
}

int main()
{

    int choice;
    while (1)
    {
        printf("\n 1.Create \n 2.Display \n 3.Display using Recursion \n 4.Count \n 5.Count using Recursion \n 6.Sum \n 7.Sum using Recursion \n 8.Max \n 9.Max using Recursion \n 10.Search \n 11.Search using Recursion \n 12.ImpSearch \n 13.Sorting of element \n 14.Insert at first \n 15.Inser at last \n 16.Inser element after a given node \n 17.Insert element before a given node \n 18.Insert at any position \n 19.Insert in a sorted Linked List \n 20.Delete from first \n 21.Delete from last \n 22.Delete element after a given node \n 23.Delete element before a given node \n 24.Delete from any position \n 25.Check a linked list is sorted \n 26.Remove duplicate from a Linked list \n 27.Reverse of Linked list \n 28.Reverse of a Linked list using Recursion \n 29.Create list for concatination and Marging \n 30.Display list for Concatination \n 31.Concatenating two Linked list \n 32.Marging two Linked List \n 33.Display list for Marging \n 34.Check for loop in Linked List \n 35.To exit \n");
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
            printf("The Nodes are: ");
            RDisplay(first);
            break;
        case 4:
            printf("The number of elements present in Linked struct Node are: %d", count());
            break;
        case 5:
            printf("The number of elements present in Linked struct Node are: %d", Rcount(first));
            break;
        case 6:
            printf("The sum of elements present in Linked struct Node are: %d", sum());
            break;
        case 7:
            printf("The sum of elements present in Linked struct Node are: %d", Rsum(first));
            break;
        case 8:
            printf("The max element present in Linked struct Node is: %d", max());
            break;
        case 9:
            printf("The max element present in Linked struct Node is: %d", Rmax(first));
            break;
        case 10:
            search() ? printf("Element is present.") : printf("Element not present.");
            break;
        case 11:
            int key;
            printf("Enter the key element: ");
            scanf("%d", &key);
            Rsearch(first, key) ? printf("Element is present.") : printf("Element not present.");
            break;
        case 12:
            impSearch() ? printf("Element is present.") : printf("Element not present.");
            break;
        case 13:
            sorting();
            break;
        case 14:
            insertFirst();
            break;
        case 15:
            insertLast();
            break;
        case 16:
            afterInsert();
            break;
        case 17:
            brforeInsert();
            break;
        case 18:
            insertAnyPos();
            break;
        case 19:
            sortedInsert();
            break;
        case 20:
            deleteFirst();
            break;
        case 21:
            deletelast();
            break;
        case 22:
            afterDelete();
            break;
        case 23:
            beforeDelete();
            break;
        case 24:
            deleteAnyPos();
            break;
        case 25:
            checkSorted() ? printf("Elements are sorted.") : printf("Elements are not sorted.");
            break;
        case 26:
            removeDuplicate();
            break;
        case 27:
            reverseElement();
            break;
        case 28:
            RReverseElement(q, first);
            printf("Reverse complete");
            break;
        case 29:
            createConcatinate();
            break;
        case 30:
            displayConcatinate();
            break;
        case 31:
            concatination();
            break;
        case 32:
            marging();
            break;
        case 33:
            displayMarging();
            break;
        case 34:
            checkLoop();
            break;
        case 35:
            exit(1);
            break;
        default:
            printf("Incorrect Choice\n");
        }
    }

    return 0;
}