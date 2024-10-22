#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int value;
    struct Node *next;
};

typedef struct Node Nd;

Nd *head = NULL;
Nd *tail = NULL;
Nd *createNode(int value)
{
    Nd *newNode = (Nd *)malloc(sizeof(Nd));
    if (newNode != NULL)
    {
        newNode->value = value;
        newNode->next = NULL;
    }
    return newNode;
}

void Print()
{
    Nd *h = head;
    while (h != NULL)
    {
        printf("%d ", h->value);
        h = (h->next);
    }
}

void Insert_at_the_end(int v)
{
    Nd *newNode = (Nd *)malloc(sizeof(Nd));
    newNode->value = v;
    newNode->next = NULL;
    Nd *tail = NULL;
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    else
    {
        tail = head;
        while (tail->next != NULL)
            tail = tail->next;
    }

    tail->next = newNode;
    tail = newNode;

}

int main()
{
    int n, v;
    scanf("%d", &n);
    while (n--)
    {
        scanf("%d", &v);
        /*Creating Linked List Manually*/
        // Nd *newNode = createNode(v);
        // if (head == NULL)
        // {
        //     head = newNode;
        //     tail = newNode;
        // }
        // else
        // {
        //     tail->next = newNode;
        //     tail = newNode;
        // }

        /*Inserting at the end. It'll also handle the head being null case*/
        Insert_at_the_end(v);
    }
    Print();
}
