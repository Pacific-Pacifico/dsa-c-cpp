#include<iostream>
#include<string.h>
#include<math.h>
#define MAX 50
using namespace std;

char infix[MAX],prefix[MAX];
long stack[MAX];
int top=-1;

int isWhitespace(char ch)
{
    if(ch=='\t' || ch==' ' || ch=='\n')
        return 1;
    return 0;
}

int isEmpty()
{
    if(top==-1)
        return 1;
    return 0;
}

void push(long ch)
{
    if(top==MAX-1)
    {
        cout<<"Stack overflow!!!"<<endl;
        return;
    }
    stack[++top]=ch;
}

long pop()
{
    if(isEmpty())
    {
        cout<<"Stack underflow!!!"<<endl;
        return -1;
    }
    return stack[top--];
}

int inStackPriority(char ch)
{
    switch(ch)
    {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
        case '%':
            return 2;
        case '^':
            return 4;
    }
    return 0;
}

int incomingPriority(char ch)
{
    switch(ch)
    {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
        case '%':
            return 2;
        case '^':
            return 3;
    }
    return 0;
}

void reverseInfix(char exp[])
{
    int i;
    char ch;
    for(i=0;i<strlen(exp);i++)
    {
        ch=exp[i];
        if(ch=='(')
            push(')');
        else if(ch==')')
            push('(');
        else
            push(ch);
    }
    for(i=0;i<strlen(exp);i++)
        exp[i]=pop();
}

void reverse(char exp[])
{
    int i;
    char ch;
    for(i=0;i<strlen(exp);i++)
            push(exp[i]);
    for(i=0;i<strlen(exp);i++)
        exp[i]=pop();
}

void infixToPrefix()
{
    int i,p=0;
    char ch,next;
    for(i=0;i<strlen(infix);i++)
    {
        ch=infix[i];
        if(isWhitespace(ch))
            continue;
        switch(ch)
        {
            case '(':
                push(ch);
                break;

            case ')':
                while((next=pop())!='(') 
                    prefix[p++]=next;
                break;
            
            case '^':
            case '/':
            case '*':
            case '%':
            case '+':
            case '-':
                while(!isEmpty() && incomingPriority(ch) < inStackPriority(stack[top]))
                    prefix[p++]=pop();
                push(ch);
                break;
            
            default:
                prefix[p++]=ch;
        }
    }
    while(!isEmpty())
        prefix[p++]=pop();
    prefix[p]='\0';
}

int evaluatePrefix()
{
    int i;
    long op1,op2,result;
    char ch;
    for(i=0;i<strlen(prefix);i++)
    {
        ch=prefix[i];
        if(ch>='0' && ch<='9')
            push(ch-'0');
        else
        {
            op1=pop();
            op2=pop();
            switch(ch)
            {
                case '+':
                    result=op1+op2;
                    break;
                
                case '-':
                    result=op1-op2;
                    break;
                
                case '*':
                    result=op1*op2;
                    break;
                
                case '/':
                    result=op1/op2;
                    break;
                
                case '%':
                    result=op1%op2;
                    break;
                
                case '^':
                    result=pow(op1,op2);
                    break;
            }
            push(result);
        }
    }
    result=pop();
    return result;
}

int main()
{
    int i,p=0;
    char ch,next;
    cout<<"Enter an infix expression=";
    fgets(infix,MAX,stdin);
    cout<<"Infix expression:";
    puts(infix);
    cout<<"Reversed infix expression=";
    reverseInfix(infix);
    puts(infix);
    infixToPrefix();
    reverse(prefix);
    cout<<"Prefix expression:";
    puts(prefix);
    reverse(prefix);
    cout<<"Value of prefix expression="<<evaluatePrefix()<<endl;
    return 0;
}