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

void enqueue(int data)
{
    if(isFull())
    {
        cout<<"queue overflow!!!"<<endl;
        return;
    }
    if(front==-1)
        front=0;
    if(rear==MAX-1)
        rear=0;
    else
        rear++;
    queue[rear]=data;
}

void dequeue()
{
    int data;
    if(isEmpty())
    {
        cout<<"queue underflow!!!"<<endl;
        return;
    }
    data=queue[front];
    if(front==rear)
        front=rear=-1;
    else if(front==MAX-1)
        front=0;
    else
        front++;
    cout<<"removed element= "<<data<<endl;
}

void peek()
{
    if(isEmpty())
    {
        cout<<"queue underflow!!!"<<endl;
        return;
    }
    cout<<"element at the front="<<queue[front]<<endl;
}

void display()
{
    int i;
    if(isEmpty())
    {
        cout<<"queue is empty!!!"<<endl;
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