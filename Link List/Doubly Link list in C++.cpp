#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *prev;
};

Node *head;
Node *tail;

Node* GetNewNode(int x)
{
    Node *newnode = new Node();

    newnode->data = x;
    newnode->next = NULL;
    newnode->prev = NULL;

    return newnode;
}

void InsertAtHead(int x)
{
    Node *newnode = GetNewNode(x);

    if(head == NULL)
    {
        head = newnode;
        tail = newnode;
        return;
    }

    head->prev = newnode;
    newnode->next = head;
    head = newnode;
}

void InsertAtTail(int x)
{
    Node *newnode = GetNewNode(x);

    if(tail == NULL)
    {
        head = newnode;
        tail = newnode;
        return;
    }

    tail->next = newnode;
    newnode->prev = tail;
    tail = newnode;
}

void Print()
{
    Node *temp = head;

    while(temp != NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

void ReversePrint()
{
    Node *temp = tail;

    while(temp != NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->prev;
    }
    cout<<endl;
}

int main()
{
    head = NULL;
    tail = NULL;
    printf("Press 1 for Insert at Head\n");
    printf("Press 2 for Insert at Tail\n");
    printf("Press 3 for Display\n");
    printf("Press 4 for Reverse Display\n");

    while(1)
    {
        int op;
        cin>>op;

        if(op==1)
        {
            int v;
            cin>>v;
            InsertAtHead(v);
        }

        else if(op==2)
        {
            int v;
            cin>>v;
            InsertAtTail(v);
        }

        else if(op==3)
        {
            Print();
        }

        else if(op==4)
        {
            ReversePrint();
        }
    }
}
