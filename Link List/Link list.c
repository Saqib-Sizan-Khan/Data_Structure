#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head;

void init()
{
    head=NULL;
}

void insertItem(int value)
{
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));

    temp->data=value;
    temp->next=head;
    head=temp;
}

void insertAnyPos(int item,int pos)
{
    if(pos==1)
    {
        insertItem(item);
        return;
    }

    struct node *temp;
    temp = (struct node*)malloc(sizeof(struct node));
    temp->data = item;
    temp->next = NULL;

    struct node *temp2 = head;

    int i;
    for(i=0;i<pos-2;i++)
    {
        temp2 = temp2->next;
    }

    temp->next = temp2->next;
    temp2->next = temp;
}

void print()
{
    struct node *temp;
    temp=head;
    while(temp != NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

struct node* search(int val)
{
    struct node *temp;
    temp=head;
    while(temp != NULL)
    {
        if(temp->data==val)
        {
            return temp;
        }
        temp=temp->next;
    }
    return 0;
}

void removeItem(int val)
{
    struct node *temp=head;
    struct node *prev=0;
    while(temp != 0)
    {
        if(temp->data==val)
            break;
        prev=temp;
        temp=temp->next;
    }
    if(temp==0)
        return;
    else if(temp==head)
    {
        head=head->next;
        free(temp);
    }
    else
    {
        prev->next=temp->next;
        free(temp);
    }
}

void deleteAnyPos(int pos)
{
    struct node *temp = head;
    int i;
    for(i=0;i<pos-2;i++)
    {
        temp = temp->next;
    }

    struct node *temp2 = temp->next;
    temp->next = temp2->next;
    free(temp2);
}

/// Complete the following functions and also add them in main function

void deleteFirst() /// The function will delete the first item of the list
{
    head = head->next;
}
void deleteLast() /// The function will delete the last item of the list
{
    struct node *temp=head;
    struct node *prev=0;
    while(temp->next != 0)
    {
        prev=temp;
        temp=temp->next;
    }
    if(temp == head)
    {
        head = NULL;
    }
    else
    {
        prev->next = NULL;
    }
}

void insertLast(int value) /// The function will insert the value at the end of the list
{
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));

    newnode->data = value;
    newnode->next = NULL;

    if(head != NULL)
    {
        struct node *temp = head;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }

    else
    {
        head = newnode;
    }
}

struct node* findLargest() /// The function will find the largest item of the list and return it
{
    int max = 0;
    struct node *temp=head;
    while(temp != 0)
    {
        if(temp->data > max)
        {
            max = temp->data;
        }
        temp = temp->next;
    }
    printf("%d\n",max);
    return 0;
}

struct node* findMiddle() /**The function will return the middle element of the list. If the list has 6 elements,
                          it will return the 3rd element. If the list has 7 elements, it will also return the 3rd element.
                          **/
{
    int c=0,val;
    struct node *temp=head;

    while(temp != 0)
    {
        temp = temp->next;
        c++;
    }

    c/=2;
    temp=head;

    while(c--)
    {
        val = temp->data;
        temp = temp->next;
    }
    printf("%d\n",val);
    return 0;
}


int main()
{
    init();
    int op;
    printf("1.insert\n");
    printf("2.print\n");
    printf("3.search\n");
    printf("4.remove\n");
    printf("5.RemoveFirst\n");
    printf("6.RemoveLast\n");
    printf("7.FindLargest\n");
    printf("8.FindMiddle\n");
    printf("9.insertLast\n");
    printf("10.insertAnyPos\n");
    printf("11.deleteAnyPos\n");

    while(1)
    {
        scanf("%d",&op);
        if(op==1)
        {
            int val;
            scanf("%d",&val);
            insertItem(val);
        }
        else if(op==2)
        {
            print();
        }
        else if(op==3)
        {
            int val;
            scanf("%d",&val);
            struct node *temp=search(val);
            if(temp==0)
                printf("Not found.\n");
            else
                printf("Found.\n");
        }
        else if(op==4)
        {
            int val;
            scanf("%d",&val);
            removeItem(val);
        }
        else if(op==5)
        {
            deleteFirst();
        }
        else if(op==6)
        {
            deleteLast();
        }
        else if(op==7)
        {
            findLargest();
        }
        else if(op==8)
        {
            findMiddle();
        }
        else if(op==9)
        {
            int val;
            scanf("%d",&val);
            insertLast(val);
        }
        else if(op==10)
        {
            int x,n;
            scanf("%d %d",&x,&n);
            insertAnyPos(x,n);
        }
        else if(op==11)
        {
            int n;
            scanf("%d",&n);
            deleteAnyPos(n);
        }
    }
}
