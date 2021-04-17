#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *link;
};

Node *top;

void Push(int x)
{
    Node *newnode = new Node();

    newnode->data = x;
    newnode->link = top;
    top = newnode;
}

void Pop()
{
    Node *temp;

    if(top==NULL)
    {
        cout<<"Stack is Empty"<<endl;
        return;
    }

    temp = top;
    top = top->link;
    delete temp;
}

void Top()
{
    cout<<top->data<<endl;
}

void IsEmpty()
{
    if(top == NULL)
    {
        cout<<"True"<<endl;
    }
    else
    {
        cout<<"False"<<endl;
    }
}

void Print()
{
    Node *temp = top;

    while(temp != NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->link;
    }
    cout<<endl;
}

int main()
{
    top = NULL;

    Push(2);
    Push(5);
    Print();
    Top();
    IsEmpty();
}
