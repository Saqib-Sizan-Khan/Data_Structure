#include<bits/stdc++.h>
using namespace std;

string ConvertPostfix(string exp);
bool IsOperator(char c);
bool IsOperand(char c);
int Priority(char op1,char op2);
int GetWeight(char op);
int IsRightAssociative(char op);

int main()
{
    string exp;
    cout<<"Enter an Infix Expression:"<<endl;

    getline(cin,exp);

    string postfix = ConvertPostfix(exp);
    cout<<postfix<<endl;
}

string ConvertPostfix(string exp)
{
    stack<char> s;
    string postfix = "";

    for(int i=0;i<exp.size();i++)
    {
        if(exp[i]==' ' || exp[i]==',')continue;

        else if(IsOperator(exp[i]))
        {
            while(!s.empty() && exp[i]!='(' && Priority(s.top(),exp[i]))
            {
                postfix += s.top();
                s.pop();
            }
            s.push(exp[i]);
        }

        else if(IsOperand(exp[i]))
        {
            postfix += exp[i];
        }

        else if(exp[i]==')')
        {
            while(!s.empty() && s.top()=='(')
            {
                postfix += s.top();
                s.pop();
            }
            s.pop();
        }

        else if(exp[i]=='(')
        {
            s.push(exp[i]);
        }
    }

    while(!s.empty())
    {
        postfix += s.top();
        s.pop();
    }

    return postfix;
}

bool IsOperator(char c)
{
    if(c=='+' || c=='-' || c=='*' || c=='/' || c=='$')return true;

    return false;
}

bool IsOperand(char c)
{
    if(c>='0' && c<='9')return true;
    if(c>='A' && c<='Z')return true;
    if(c>='a' && c<='z')return true;

    return false;
}

int Priority(char op1,char op2)
{
    int op1weight = GetWeight(op1);
    int op2weight = GetWeight(op2);

    if(op1weight==op2weight)
    {
        if(IsRightAssociative(op1))return false;

        else return true;
    }

    return op1weight > op2weight ? true:false;
}

int GetWeight(char op)
{
    int weight = 0;

    if(op=='+' || op=='-')return weight=1;
    else if(op=='/' || op=='*')return weight=2;
    else if(op=='$')return weight=3;
}

int IsRightAssociative(char op)
{
	if(op == '$') return true;
	return false;
}
