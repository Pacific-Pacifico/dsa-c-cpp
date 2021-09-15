#include<iostream>
#include<string.h>
#define MAX 200
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

int main()
{
    int i;
    char str[MAX];
    cout<<"Enter a string=";
    fgets(str,MAX,stdin);
    cout<<"Entered string=";
    puts(str);
    for(i=0;i<strlen(str);i++)
        push(str[i]);
    for(i=0;i<strlen(str);i++)
        str[i]=pop();
    cout<<"Reversed string=";
    puts(str);
    return 0;
}
