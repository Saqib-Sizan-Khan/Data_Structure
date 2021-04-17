#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

struct node *head;
struct node *tail;

void init()
{
    head = 0;
    tail = 0;
}

void push(int value)
{
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));

    newnode->data = value;
    newnode->next = 0;

    newnode->prev = tail;
    if(tail == 0)
    {
        head = newnode;
    }
    else
    {
        tail->next = newnode;
    }
    tail = newnode;
}

void pop()
{
    if(head == NULL)
    {
        printf("Stack is Empty\n");
    }

    else
    {
        struct node *temp = head->next;
        head = temp;
    }
}

int peek()
{
    if(head != NULL)
    {
        return head->data;
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

    if(head == NULL)
    {
        printf("Stack is Empty\n");
    }

    else
    {
        temp = head;
        while(temp != NULL)
        {
            printf("%d ",temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main()
{
    init();
    int op;

    printf("Use this Menu for create a Queue.\n");
    printf("1.Push.\n");
    printf("2.Pop.\n");
    printf("3.Peek.\n");
    printf("4.Display.\n");
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
            int r = peek();
            if(r != NULL)
            {
                printf("%d\n",r);
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
