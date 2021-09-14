#include<iostream>
#define MAX 5
using namespace std;

struct node 
{
    int info;
    node *next;
}*rear=NULL;

int isEmpty()
{
    if(rear==NULL)
        return 1;
    return 0;
}

void enqueue(int data)
{
    struct node *temp;
    temp=new node;
    if(temp==NULL)
    {
        cout<<"Not enough memory"<<endl;
        return;
    }
    temp->info=data;
    if(isEmpty())
    {
        rear=temp;
        temp->next=rear;
    }
    else
    {
        temp->next=rear->next;
        rear->next=temp;
        rear=temp;
    }
}

void dequeue()
{
    node *temp;
    int data;
    if(isEmpty())
    {
        cout<<"queue underflow!!!"<<endl;
        return;
    }
    if(rear->next==rear)
    {
        temp=rear;        
        rear=NULL;
    }
    else
    {
        temp=rear->next;
        rear->next=temp->next;
    }
    data=temp->info;
    delete temp;
    cout<<"removed element= "<<data<<endl;
}

void peek()
{
    if(isEmpty())
    {
        cout<<"queue underflow!!!"<<endl;
        return;
    }
    cout<<"Element in front= "<<rear->next->info<<endl;
}

void display()
{
    node *p;
    if(isEmpty())
    {
        cout<<"queue empty!!!"<<endl;
        return;
    }
    cout<<"Queue: ";
    p=rear->next;
    do
    {
        cout<<p->info<<" ";
        p=p->next;
    } while (p!=rear->next);
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
        cout<<"1.enqueue an element"<<endl;
        cout<<"2.dequeue an element"<<endl;
        cout<<"3.peek(display the element at the front)"<<endl;
        cout<<"4.display all elements"<<endl;
        cout<<"5.Exit"<<endl;
        cout<<"Enter the option="<<endl;
        cin>>option;
        switch(option)
        {
            case 1:
                cout<<"Enter element=";
                cin>>n;
                enqueue(n);
                break;

            case 2:
                dequeue();
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