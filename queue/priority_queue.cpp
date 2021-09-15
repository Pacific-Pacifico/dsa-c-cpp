// Priority queue implemented using sorted linked list
// lesser the priority number, higher its priority 
#include<iostream>
using namespace std;

struct node
{
    int priority;
    int info;
    node *next;
}*front=NULL;

int isEmpty()
{
    if(front==NULL)
        return 1;
    return 0;
}

void insert(int data,int priority)
{
    node *temp,*p;
    temp=new node;
    if(temp==NULL)
    {
        cout<<"Not enough memory!!!"<<endl;
        return;
    }
    temp->info=data;
    temp->priority=priority;
    if(isEmpty() || front->priority > priority)
    {
        temp->next=front;
        front=temp;
        return;
    }
    p=front;
    while(p->next!=NULL && p->next->priority <= priority)
        p=p->next;
    temp->next=p->next;
    p->next=temp;
}

void delete_front()
{
    struct node *temp;
    int data;
    if(isEmpty())
    {
        cout<<"Queue underflow!!!"<<endl;
        return;
    }
    temp=front;
    data=temp->info;
    front=front->next;
    delete temp;
    cout<<"Deleted element= "<<data<<endl;
}

void display()
{
    node *p;
    if(isEmpty())
    {
        cout<<"queue is empty!!!"<<endl;
        return;
    }
    cout<<"Queue: "<<endl;
    p=front;
    while(p!=NULL)
    {
        cout<<"Priority= "<<p->priority<<"  "<<"Element= "<<p->info<<endl;
        p=p->next;
    }
}

void clear();

int main()
{
    int option,n,p;
    char ch;
    do
    {
        clear();
        cout<<"Select the required option"<<endl;
        cout<<"1.insert an element"<<endl;
        cout<<"2.delete an element"<<endl;
        cout<<"3.display all elements"<<endl;
        cout<<"4.Exit"<<endl;
        cout<<"Enter the option="<<endl;
        cin>>option;
        switch(option)
        {
            case 1:
                cout<<"Enter element=";
                cin>>n;
                cout<<"Enter priority=";
                cin>>p;
                insert(n,p);
                break;

            case 2:
                delete_front();
                break;
                    
            case 3:
                display();
                break;
            
            case 4:
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