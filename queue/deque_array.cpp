#include<iostream>
#define MAX 5
using namespace std;

int queue[MAX];
int front=-1,rear=-1;

int isEmpty()
{
    if(front==-1)
        return 1;
    return 0;
}

int isFull()
{
    if((front==0 && rear==MAX-1) || (front==rear+1))
        return 1;
    return 0;
}

void insert_front(int data)
{
    if(isFull())
    {
        cout<<"Queue overflow!!!"<<endl;
        return;
    }
    if(front==-1)
        front=rear=0;
    else if(front==0)
        front=MAX-1;
    else
        front--;
    queue[front]=data;
}

void insert_rear(int data)
{
    if(isFull())
    {
        cout<<"Queue overflow!!!"<<endl;
        return;
    }
    if(front==-1)
        front=rear=0;
    else if(rear==MAX-1)
        rear=0;
    else
        rear++;
    queue[rear]=data;
}

void delete_front()
{
    int data;
    if(isEmpty())
    {
        cout<<"Queue underflow!!!"<<endl;
        return;        
    }
    data=queue[front];
    if(front==rear)
        front=rear=-1;
    else if(front==MAX-1)
        front=0;
    else
        front++;
    cout<<"Deleted element= "<<data<<endl;
}

void delete_rear()
{
    int data;
    if(isEmpty())
    {
        cout<<"Queue underflow!!!"<<endl;
        return;        
    }
    data=queue[rear];
    if(front==rear)
        front=rear=-1;
    else if(rear==0)
        rear=MAX-1;
    else
        rear--;
    cout<<"Deleted element= "<<data<<endl;
}

void display()
{
    int i;
    if(isEmpty())
    {
        cout<<"Queue empty!!!"<<endl;
        return;        
    }
    cout<<"Queue: ";
    if(front<=rear)
    {
        for(i=front;i<=rear;i++)
            cout<<queue[i]<<" ";
    }
    else
    {
        for(i=front;i<MAX;i++)
            cout<<queue[i]<<" ";
        for(i=0;i<=rear;i++)
            cout<<queue[i]<<" ";
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
        cout<<"1.Insert at the front end"<<endl;
        cout<<"2.Insert at the rear end"<<endl;
        cout<<"3.Delete from front end"<<endl;
        cout<<"4.Delete from rear end"<<endl;
        cout<<"5.Display all elements"<<endl;
        cout<<"6.Exit"<<endl;
        cout<<"Enter the option="<<endl;
        cin>>option;
        switch(option)
        {
            case 1:
                cout<<"Enter element=";
                cin>>n;
                insert_front(n);
                break;

            case 2:
                cout<<"Enter element=";
                cin>>n;
                insert_rear(n);
                break;
            
            case 3:
                delete_front();
                break;
            
            case 4:
                delete_rear();
                break;
                
            case 5:
                display();
                break;
            
            case 6:
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