#include<bits/stdc++.h>
using namespace std;

bool CheckPair(char open,char colse)
{
    if(open=='(' && colse==')')return true;
    else if(open=='{' && colse=='}')return true;
    else if(open=='[' && colse==']')return true;

    return false;
}

bool CheckBalance(string exp)
{
    stack<char> s;
    for(int i=0; i<exp.size(); i++)
    {
        if(exp[i]=='(' || exp[i]=='{' || exp[i]=='[')
        {
            s.push(exp[i]);
        }

        else if(exp[i]==')' || exp[i]=='}' || exp[i]==']')
        {
            if(s.empty() || !CheckPair(s.top(),exp[i]))
            {
                return false;
            }
            else
            {
                s.pop();
            }
        }
    }

    return s.empty() ? true:false;
}

int main()
{
    string exp;
    cout<<"Enter an Expression"<<endl;

    cin>>exp;

    if(CheckBalance(exp))
    {
        cout<<"Expression is Balanced"<<endl;
    }

    else
    {
        cout<<"Expression is not Balanced"<<endl;
    }
}
