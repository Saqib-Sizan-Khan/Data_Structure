#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* link;
};

struct node* top;

void init()
{
    top = NULL;
}

void push(int value)
{
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));

    newnode->data = value;
    newnode->link = top;
    top = newnode;
}

void pop()
{
    if(top == NULL)
    {
        printf("Stack is Empty\n");
    }

    else
    {
        struct node* temp = top->link;
        top = temp;
    }
}

int peek()
{
    if(top != NULL)
    {
        return top->data;
    }
    else
    {
        printf("Stack is Empty\n");
        return 0;
    }
}

void display()
{
    struct node *temp;

    if(top == NULL)
    {
        printf("Stack is Empty\n");
    }

    else
    {
        temp = top;
        while(temp != NULL)
        {
            printf("%d ",temp->data);
            temp = temp->link;
        }
        printf("\n");
    }
}

int main()
{
    init();
    int op;
    printf("Use this Menu for create a Stack.\n");
    printf("1.push.\n");
    printf("2.pop.\n");
    printf("3.peek.\n");
    printf("4.display.\n");
    printf("5.Stop.\n");

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
                printf("Top Element of Stack %d\n",val);
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
