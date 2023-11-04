#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *head = new Node;

void create(int A[], int n)
{
    Node *temp;
    Node *tail;

    head->data = A[0];
    head->next = NULL;
    tail = head;

    for (int i = 1; i < n; i++)
    {
        temp = new Node;
        temp->data = A[i];
        temp->next = NULL;
        tail->next = temp;
        tail = temp;
    }
}

void middleNode(Node *p)
{
    Node *q = p;
    while (q)
    {
        q = q->next;
        if (q)
        {
            q = q->next;
        }
        if (q)
        {
            p = p->next;
        }
    }
    cout << "Middle Element is : " << p->data << endl;
}

int main()
{

    int A[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21};
    create(A, sizeof(A) / sizeof(A[0]));

    cout << endl;
    middleNode(head);

    return 0;
}