#include<bits/stdc++.h>
using namespace std;

int q[6],n=6;
int f,r;

void init()
{
    f = r = -1;
}

void Enqueue(int i)
{
    if(f==0 && r==n-1 || f==r+1)
    {
        cout<<"Queue Overflow"<<endl;
        return;
    }
    else if(f==-1)
    {
        f = r = 0;
    }
    else
    {
        r = (r+1)%n;
    }

    q[r] = i;
}

void Dequeue()
{
    if(f==-1)
    {
        cout<<"Queue Underflow"<<endl;
    }
    else if(f==r && f!=-1)
    {
        f = r = -1;
    }
    else
    {
        f = (f+1)%n;
    }
}

void Isfront()
{
    printf("Front: %d\n",q[f]);
}

void Print()
{
    int c = (r+n-f)%n+1;

    for(int i = 0; i < c; i++)
		{
			int index = (f+i) % n;
			cout<<q[index]<<" ";
		}
		cout<<"\n\n";
}

int main()
{
    init();

    Enqueue(1);
    Enqueue(2);
    Enqueue(3);
    Enqueue(4);
    Enqueue(5);
    Enqueue(6);

    Dequeue();

    Print();
    Isfront();
}
