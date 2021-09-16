#include<iostream>
#include<string.h>
#define MAX 50
using namespace std;

char stack[MAX];
int top=-1;

void push(char ch)
{
    if(top==MAX-1)
    {
        cout<<"Stack overflow!!!"<<endl;
        return;
    }
    stack[++top]=ch;
}

char pop()
{
    if(top==-1)
    {
        cout<<"Stack underflow!!!"<<endl;
        return -1;
    }
    return stack[top--];
}

int match(char a,char b)
{
    if(a=='(' && b==')')
        return 1;
    if(a=='{' && b=='}')
        return 1;
    if(a=='[' && b==']')
        return 1;
    return 0;
}

int isValid(char exp[])
{
    int i;
    char ch,temp;
    for(i=0;i<strlen(exp);i++)
    {
        ch=exp[i];
        if(ch=='(' || ch=='{' || ch=='[')
            push(ch);
        else if(ch==')' || ch=='}' || ch==']')
        {
            if(top==-1)
            {
                cout<<"Right parentheses more than left parentheses!!!"<<endl;
                return 0;
            }
            temp=pop();
            if(!match(temp,ch))       // don't change the order of temp & ch
            {
                cout<<"Mismatched parentheses are= "<<temp<<" and "<<ch<<endl;
                return 0;
            }
        }
    }
    if(top==-1)
        return 1;
    cout<<"Left parentheses more than right parentheses!!!"<<endl;
    return 0;     
}

int main()
{
    char exp[MAX];
    int valid;
    cout<<"Enter an algebraic expression=";
    fgets(exp,MAX,stdin);
    cout<<"Expression=";
    puts(exp);
    valid=isValid(exp);
    if(valid)
        cout<<"Balanced Parentheses."<<endl;
    else
        cout<<"Unbalanced Parentheses."<<endl;
    return 0;
}