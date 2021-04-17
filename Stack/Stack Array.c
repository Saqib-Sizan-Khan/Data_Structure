#include<stdio.h>
#define MAXSIZE 101

int A[MAXSIZE];
int top = -1;

void Push(int x)
{
    if(top == MAXSIZE-1)
    {
        printf("Error: Stack Overflow\n");
        return;
    }
    A[++top] = x;
}

void Pop()
{
    if(top == -1)
    {
        printf("Error: Stack Underflow");
        return;
    }
    top--;
}

int Top()
{
    return top;
}

int IsEmpty()
{
    if(top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void Print()
{
    int i;
    printf("Stack: ");

    for(i=0;i<=top;i++)
    {
        printf("%d ",A[i]);
    }
    printf("\n");
}

int main()
{
    Push(2);Print();
    Push(4);Print();
    Push(6);Print();
    Pop();Print();
    Push(9);Print();
}
