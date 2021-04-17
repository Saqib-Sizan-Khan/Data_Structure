#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *link;
};

Node *head;

void Insert(int x)
{
    Node *newnode = new Node();
    (*newnode).data = x;
    newnode->link = NULL;

    if(head!=NULL)
    {
        newnode->link = head;
    }
    head = newnode;
}

void InsertAnyPos(int data,int n)
{
    Node *temp1 = new Node();
    temp1->data = data;
    temp1->link = NULL;

    if(head == NULL)
    {
        head = temp1;
        return;
    }

    if(n==1)
    {
        temp1->link = head;
        head = temp1;
        return;
    }

    Node *temp2 = head;
    for(int i=0;i<n-2;i++)
    {
        temp2 = temp2->link;
    }
    temp1->link = temp2->link;
    temp2->link = temp1;
}

void InsertLast(int val)
{
    Node *newnode = new Node();
    newnode->data = val;
    newnode->link = NULL;

    if(head==NULL)
    {
        head = newnode;
        return;
    }

    Node *temp = head;
    while(temp->link != NULL)
    {
        temp = temp->link;
    }
    temp->link = newnode;
}

void Delete(int n)
{
    Node *temp1 = head;

    if(n==1)
    {
        head = temp1->link;
        delete temp1;
        return;
    }

    for(int i=0;i<n-2;i++)
    {
        temp1 = temp1->link;
    }
    Node *temp2 = temp1->link;
    temp1->link = temp2->link;
    delete temp2;
}

void Print()
{
    Node *temp = head;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp = temp->link;
    }
    printf("\n");
}

void Reverse()
{
    if(head==NULL)return;

    stack<struct Node*> s;
    Node *temp = head;
    while(temp != NULL)
    {
        s.push(temp);
        temp = temp->link;
    }

    temp = s.top();
    head = temp;
    s.pop();
    while(!s.empty())
    {
        temp->link = s.top();
        s.pop();
        temp = temp->link;
    }
    temp->link = NULL;
}

int main()
{
    head = NULL;
    printf("press 1 for Insert\n");
    printf("press 2 for Insert at Any position\n");
    printf("press 3 for Insert at Last\n");
    printf("press 4 for Display\n");
    printf("press 5 for Delete\n");
    printf("press 6 for Reverse\n");

    while(1)
    {
        int op;
        cin>>op;

        if(op==1)
        {
            cout<<"Enter the value"<<endl;
            int v;
            cin>>v;
            Insert(v);
        }

        else if(op==2)
        {
            cout<<"Enter the value & position"<<endl;
            int v,i;
            cin>>v>>i;
            InsertAnyPos(v,i);
        }

        else if(op==3)
        {
            int v;
            cin>>v;
            InsertLast(v);
        }

        else if(op==4)
        {
            Print();
        }

        else if(op==5)
        {
            int pos;
            cin>>pos;
            Delete(pos);
        }

        else if(op==6)
        {
            Reverse();
        }
    }
}

