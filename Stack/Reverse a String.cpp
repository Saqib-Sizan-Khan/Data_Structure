#include<bits/stdc++.h>
using namespace std;

Reverse(char C[],int l)
{
    stack<char> s;

    for(int i=0;i<l;i++)
    {
        s.push(C[i]);
    }

    for(int i=0;i<l;i++)
    {
        C[i] = s.top();
        s.pop();
    }
}

int main()
{
    char c[200];
    cout<<"Enter a String"<<endl;

    gets(c);

    Reverse(c,strlen(c));
    cout<<c<<endl;
}
