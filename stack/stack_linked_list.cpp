#include<iostream>
#define MAX 10
using namespace std;

struct node
{
    int info;
    node *next;
}*top=NULL;

int isEmpty()
{
    if(top==NULL)
        return 1;
    return 0;
}

void push(int data)
{
    node *temp;
    temp=new node;
    if(temp==NULL)
    {
        cout<<"Not enough memory"<<endl;
        return;
    }
    temp->info=data;
    temp->next=top;
    top=temp;
}

void pop()
{
    node *temp;
    int data;
    if(isEmpty())
    {
        cout<<"stack underflow"<<endl;
        return;
    }
    temp=top;
    data=temp->info;
    top=top->next;
    delete temp;
    cout<<"Popped element= "<<data<<endl; 
}

void peek()
{
    if(isEmpty())
    {
        cout<<"stack underflow"<<endl;
        return;
    }
    cout<<"Top element= "<<top->info<<endl;
}

void display()
{
    node *p;
    if(isEmpty())
    {
        cout<<"stack underflow"<<endl;
        return;
    }
    cout<<"\nStack: ";
    p=top;
    while(p!=NULL)
    {
        cout<<p->info<<" ";
        p=p->next;
    }
    cout<<endl;
}

void clear();

int main()
{
    int option,n;
    char ch;
    do
    {
        clear();
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

void clear()
{
    #if defined(__linux__) || defined(__unix__) || defined(__APPLE__)
    system("clear");
    #endif
    #if defined(_WIN32) || defined(_WIN64)
    system("cls");
    #endif
}