#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *link;
};

struct node *front;

void init()
{
    front = NULL;
}

void push(int value)
{
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));

    newnode->data = value;
    newnode->link = NULL;

    if(front != NULL)
    {
        struct node *temp = front;
        while(temp->link != NULL)
        {
            temp = temp->link;
        }
        temp->link = newnode;
    }

    else
    {
        front = newnode;
    }
}

void pop()
{
    if(front == NULL)
    {
        printf("Queue is Empty\n");
    }

    else
    {
        struct node *temp = front;
        temp = temp->link;
        front = temp;
    }
}

int peek()
{
    if(front != NULL)
    {
        return front->data;
    }
    else
    {
        printf("Queue is Empty\n");
        return 0;
    }
}

void display()
{
    struct node *temp = front;
    while(temp != NULL)
    {
        printf("%d ",temp->data);
        temp = temp->link;
    }
    printf("\n");
}

int main()
{
    init();
    int op;
    printf("1.push\n");
    printf("2.pop\n");
    printf("3.peek\n");
    printf("4.display\n");
    printf("5.Stop\n");

    while(1)
    {
        scanf("%d",&op);
        if(op==1)
        {
            int val;
            scanf("%d",&val);
            push(val);
        }
        else if(op==2)
        {
            pop();
        }
        else if(op==3)
        {
            int val = peek();
            if(val != 0)
            {
                printf("Top Element of Queue %d\n",val);
            }
        }
        else if(op==4)
        {
            display();
        }
        else if(op==5)
        {
            break;
        }
    }
    return 0;
}
