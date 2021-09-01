#include<iostream>
using namespace std;

struct node 
{
    int info;
    node *next;
};

void display(node *start)
{
    if(start==NULL)
    {
        cout<<"List is empty!!"<<endl;
        return;
    }
    node *p=start;
    cout<<"List: ";
    while(p!=NULL)
    {
        cout<<p->info<<" ";
        p=p->next;
    }
}

int count(node *start)
{
    node *p=start;
    int c=0;
    while(p!=NULL)
    {
        c++;
        p=p->next;
    }
    return c;
}

int search(node *start,int ser)
{
    node *p=start;
    int pos=-1;
    while(p!=NULL)
    {
        pos++;
        if(p->info==ser)
            return pos;
        p=p->next;
    }
    return -1;
}

node *insert_beg(node *start,int data)
{
    node *temp;
    temp=new node;
    temp->info=data;
    temp->next=start;
    start=temp;
    return start;
}

node *insert_end(node *start,int data)
{
    node *temp,*p=start;
    temp=new node;
    temp->info=data;
    temp->next=NULL;
    while(p->next!=NULL)
        p=p->next;
    p->next=temp;
    return start;
}

node *create_list(node *start)
{
    int num,data;
    cout<<"Enter number of nodes=";
    cin>>num;
    cout<<"Enter data for node 1= ";
    cin>>data;
    start=insert_beg(start,data);
    for(int i=2;i<=num;i++)
    {
        cout<<"Enter data for node "<<i<<"= ";
        cin>>data;
        start=insert_end(start,data);
    }
    return start;
}

node *insert_after(node *start,int data,int n)
{
    node *temp,*p=start;
    while(p!=NULL)
    {
        if(p->info==n)
        {
            temp=new node;
            temp->info=data;
            temp->next=p->next;
            p->next=temp;
            return start;
        }
        p=p->next;
    }
    return start;
}

node *insert_before(node *start,int data,int n)
{
    node *temp,*p=start;
    if(start==NULL)
    {
        cout<<"List is empty"<<endl;
        return start;
    }
    if(start->info==n)
    {
        temp=new node;
        temp->info=data;
        temp->next=start;
        start=temp;
        return start;
    }
    while(p->next!=NULL)
    {
        if(p->next->info==n)
        {
            temp=new node;
            temp->info=data;
            temp->next=p->next;
            p->next=temp;
            return start;
        }   
        p=p->next;
    }    
    return start;
}

node *insert_pos(node *start,int data,int pos)
{
    
    return start;
}

node *delete_node(node *start,int data)
{
    node *temp,*p;
    if(start==NULL)
    {
        cout<<"List is empty!!!"<<endl;
        return start; 
    }
    if(start->info==data)
    {
        temp=start;
        start=start->next;
        delete temp;
        return start;
    }
    p=start;
    while(p->next!=NULL)
    {
        if(p->next->info==data)
        {
            temp=p->next;
            p->next=temp->next;
            delete temp;
            return start;
        }
        p=p->next;
    }
    cout<<"Element "<<data<<" not found!"<<endl;
    return start;
}

node *reverse(node *start)
{
    return start;
}

int main()
{
    node *start=NULL;
    int option,data,n;
    char ch;
    do
    {
        cout<<"Singly linked list"<<endl;
        cout<<"1.create a list"<<endl;
        cout<<"2.display"<<endl;
        cout<<"3.count"<<endl;
        cout<<"4.search"<<endl;
        cout<<"5.add to empty list / add at beginning"<<endl;
        cout<<"6.add at end"<<endl;
        cout<<"7.add after node"<<endl;
        cout<<"8.add before node"<<endl;
        cout<<"9.add at position"<<endl;
        cout<<"10.delete"<<endl;
        cout<<"11.reverse"<<endl;
        cout<<"12.quit"<<endl;
        cout<<"Select the desired option:";
        cin>>option;
        switch(option)
        {
            case 1:
                start=create_list(start);
                break;
            
            case 2:
                display(start);
                break;

            case 3:
                cout<<"Number of elements="<<count(start)<<endl;
                break;

            case 4:
                int ser,pos;
                cout<<"Enter element to search=";
                cin>>ser;
                pos=search(start,ser);
                if(pos==-1)
                    cout<<"Not found!!!"<<endl;
                else
                    cout<<"found at position="<<pos+1<<endl;
                break;
            
            case 5:
                cout<<"Enter data=";
                cin>>data;
                start=insert_beg(start,data);
                break;

            case 6:
                cout<<"Enter data=";
                cin>>data;
                start=insert_end(start,data);
                break;

            case 7:
                cout<<"Enter data=";
                cin>>data;
                cout<<"Enter data after which you want to insert=";
                cin>>n;
                start=insert_after(start,data,n);
                break;
            
            case 8:
                cout<<"Enter data=";
                cin>>data;
                cout<<"Enter data before which you want to insert=";
                cin>>n;
                start=insert_before(start,data,n);
                break;
            
            case 9:
                cout<<"Enter data=";
                cin>>data;
                cout<<"Enter position=";
                cin>>n;
                start=insert_pos(start,data,n);
                break;
            
            case 10:
                cout<<"Enter element to be deleted=";
                cin>>data;
                start=delete_node(start,data);
                break;
            
            case 11:
                start=reverse(start);
                break;
            
            case 12:
                exit(1);
            
            default:
                cout<<"invalid option"<<endl;
        }
        cout<<"\nPress y/Y and enter to continue.."<<endl;
        cin>>ch;
    }while(ch=='y' || ch=='Y');
    return 0;
}