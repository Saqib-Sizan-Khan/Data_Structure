#include <stdio.h>
#include <stdlib.h>

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

void insert(int val)
{
    struct node *newNode;
    newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = val;
    newNode->prev = 0;

    newNode->next = head;
    if (head != 0)
        head->prev = newNode;
    else
        tail = newNode;

    head = newNode;
}

void insertLast(int val)
{
    struct node *newNode;
    newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = val;
    newNode->next = 0;

    newNode->prev = tail;
    if (head != 0)
        tail->next = newNode;
    else
        head = newNode;
    tail = newNode;
}

void print()
{
    struct node *temp = head;
    while (temp != 0)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

/// Complete the following functions and also add them in main function

int length() ///The function will return the length of the list
{
    struct node *temp = head;
    int c = 0;
    while (temp != 0)
    {
        temp = temp->next;
        c++;
    }
    printf("%d\n", c);
    return 0;
}

struct node *search(int value) /// The function will search the value from the list and return it
{
    struct node *temp = head;

    while (temp != 0)
    {
        if (temp->data == value)
        {
            return temp;
        }
        temp = temp->next;
    }
    return 0;
}
void deleteFirst() /// The function will delete the last item of the list
{
    head = head->next;
}

void insertAnyPos(int value, int pos)
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->next = 0;
    newnode->prev = 0;

    struct node *temp = head;
    while (--pos)
    {
        temp = temp->next;
    }

    temp->prev->next = newnode;
    newnode->prev = temp->prev;
    newnode->next = temp;
    temp->prev = newnode;
}

void deleteItem(int value) /// The function will delete the value from the list, if the value exists in the list
{
    struct node *temp = search(value);

    if (temp == head)
    {
        head = temp->next;
    }

    else if (temp == tail)
    {
        tail = tail->prev;
        tail->next = NULL;
    }

    else if (temp != 0)
    {
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
    }

    else
    {
        printf("Item not found.\n");
    }
    free(temp);
}

int main()
{
    init();
    int op;
    printf("1.insert\n");
    printf("2.insertLast\n");
    printf("3.print\n");
    printf("4.length\n");
    printf("5.search\n");
    printf("6.deleteFirst\n");
    printf("7.deleteItem\n");
    printf("8.insertAnyPosition.\n");

    while (1)
    {
        scanf("%d", &op);
        if (op == 1)
        {
            int val;
            scanf("%d", &val);
            insert(val);
        }
        else if (op == 2)
        {
            int val;
            scanf("%d", &val);
            insertLast(val);
        }
        else if (op == 3)
        {
            print();
        }
        else if (op == 4)
        {
            length();
        }
        else if (op == 5)
        {
            int val;
            scanf("%d", &val);
            int r = search(val);

            if (r != 0)
                printf("Found\n");
            else
                printf("not Found\n");
        }
        else if (op == 6)
        {
            deleteFirst();
        }
        else if (op == 7)
        {
            int val;
            scanf("%d", &val);
            deleteItem(val);
        }
        else if (op == 8)
        {
            int val, pos;
            scanf("%d %d", &val, &pos);
            insertAnyPos(val, pos);
        }
    }
}
