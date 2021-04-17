#include<bits/stdc++.h>
using namespace std;

int EvaluatePostfix(string exp);
bool IsOperator(char c);
bool IsOperand(char c);
int Operation(char e,int op1,int op2);

int main()
{
    string exp;
    cout<<"Enter an Expression:"<<endl;

    getline(cin,exp);

    int result = EvaluatePostfix(exp);
    cout<<result<<endl;

}

int EvaluatePostfix(string exp)
{
    stack<int> s;

    for(int i=0;i<exp.size();i++)
    {
        if(exp[i]==' ' || exp[i]==',')continue;

        else if(IsOperator(exp[i]))
        {
            int op2 = s.top(); s.pop();
            int op1 = s.top(); s.pop();

            int result = Operation(exp[i],op1,op2);
            s.push(result);
        }

        else if(IsOperand(exp[i]))
        {
            int operand = 0;

            while(i<exp.size() && IsOperand(exp[i]))
            {
                operand = (operand*10) + (exp[i]-'0');
                i++;
            }
            i--;
            s.push(operand);
        }
    }

    return s.top();
}

bool IsOperator(char c)
{
    if(c=='+' || c=='-' || c=='*' || c=='/')return true;

    return false;
}

bool IsOperand(char c)
{
    if(c>='0' && c<='9')return true;

    return false;
}

int Operation(char e,int op1,int op2)
{
    if(e == '+')return op1+op2;
    else if(e == '-')return op1-op2;
    else if(e == '*')return op1*op2;
    else if(e == '/')return op1/op2;

    else
    {
        cout<<"Error"<<endl;
        return -1;
    }
}
