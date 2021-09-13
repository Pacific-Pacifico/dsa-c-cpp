#include<iostream>
#define MAX 10
using namespace std;

int stack[MAX];
int top=-1;

int isEmpty()
{
    if(top==-1)
        return 1;
    return 0;
}

int isFull()
{
    if(top==MAX-1)
        return 1;
    return 0;
}

void push(int data)
{
    if(isFull())
    {
        cout<<"stack overflow"<<endl;
        return;
    }
    top++;
    stack[top]=data;
}

void pop()
{
    int data;
    if(isEmpty())
    {
        cout<<"stack underflow"<<endl;
        return;
    }
    data=stack[top];
    top--;
    cout<<"Popped element= "<<data<<endl; 
}

void peek()
{
    if(isEmpty())
    {
        cout<<"stack underflow"<<endl;
        return;
    }
    cout<<"Top element= "<<stack[top]<<endl;
}

void display()
{
    if(isEmpty())
    {
        cout<<"stack underflow"<<endl;
        return;
    }
    cout<<"Stack: "<<endl;
    for(int i=top;i>=0;i--)
    {
        cout<<stack[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    int option,n;
    char ch;
    do
    {
        cout<<"Select the required option"<<endl;
        cout<<"1.push an element"<<endl;
        cout<<"2.Pop an element"<<endl;
        cout<<"3.peek(display the top element)"<<endl;
        cout<<"4.display all elements"<<endl;
        cout<<"5.Exit"<<endl;
        cout<<"Enter the option="<<endl;
        cin>>option;
        switch(option)
        {
            case 1:
                cout<<"Enter element=";
                cin>>n;
                push(n);
                break;

            case 2:
                pop();
                break;
            
            case 3:
                peek();
                break;
            
            case 4:
                display();
                break;
            
            case 5:
                exit(1);

            default:
                cout<<"invalid option selected"<<endl;
        }
        cout<<"\nPress y/Y and enter to continue.."<<endl;
        cin>>ch;
    }while(ch=='y' || ch=='Y');
    return 0;
}