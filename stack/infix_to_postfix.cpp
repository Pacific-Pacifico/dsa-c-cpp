#include<iostream>
#include<string.h>
#include<math.h>
#define MAX 50
using namespace std;

char infix[MAX],postfix[MAX],stack[MAX];
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

void push(char ch)
{
    if(top==MAX-1)
    {
        cout<<"Stack overflow!!!"<<endl;
        return;
    }
    stack[++top]=ch;
}

int pop()
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
            return 3;
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
            return 4;
    }
    return 0;
}

void infixToPostfix()
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
                    postfix[p++]=next;
                break;
            
            case '^':
            case '/':
            case '*':
            case '%':
            case '+':
            case '-':
                while(!isEmpty() && incomingPriority(ch) <= inStackPriority(stack[top]))
                    postfix[p++]=pop();
                push(ch);
                break;
            
            default:
                postfix[p++]=ch;
        }
    }
    while(!isEmpty())
        postfix[p++]=pop();
    postfix[p]='\0';
}

int evaluatePostfix()
{
    int i,op1,op2,result;
    char ch;
    for(i=0;i<strlen(postfix);i++)
    {
        ch=postfix[i];
        if(ch>='0' && ch<='9')
            push(ch-'0');
        else
        {
            op2=pop();
            op1=pop();
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
    infixToPostfix();
    cout<<"Postfix expression:";
    puts(postfix);
    cout<<"Value of postfix expression="<<evaluatePostfix()<<endl;
    return 0;
}