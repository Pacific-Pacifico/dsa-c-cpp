#include<iostream>
using namespace std;

struct node 
{
    node *prev;
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

node *insert_empty(node *start,int data)
{
    node *temp;
    temp=new node;
    temp->info=data;
    temp->prev=NULL;
    temp->next=NULL;
    start=temp;
    return start;
}

node *insert_beg(node *start,int data)
{
    node *temp;
    temp=new node;
    temp->info=data;
    temp->prev=NULL;
    temp->next=start;
    start->prev=temp;
    start=temp;
    return start;
}

node *insert_end(node *start,int data)
{
    node *temp,*p;
    if(start==NULL)
    {
        cout<<"Empty List"<<endl;
        return start;
    }
    p=start;
    while(p->next!=NULL)
    {
        p=p->next;
    }
    temp=new node;
    temp->info=data;
    temp->prev=p;
    temp->next=NULL;
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
    start=insert_empty(start,data);
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
    node *temp,*p;
    if(start==NULL)
    {
        cout<<"Empty list"<<endl;
        return start;
    }
    p=start;
    while(p!=NULL)
    {
        if(p->info==n)
        {
            temp=new node;
            temp->info=data;
            temp->next=p->next;
            temp->prev=p;
            if(p->next!=NULL)
                p->next->prev=temp;
            p->next=temp;
            return start;
        }
        p=p->next;
    }
    cout<<n<<" not present in list"<<endl;
    return start;
}

node *insert_before(node *start,int data,int n)
{
    node *temp,*p;
    if(start==NULL)
    {
        cout<<"Empty list"<<endl;
        return start;
    }
    if(start->info==n)
    {
        temp=new node;
        temp->info=data;
        temp->next=start;
        temp->prev=NULL;
        start->prev=temp;
        start=temp;
        return start;
    }
    p=start;
    while(p!=NULL)
    {
        if(p->info==n)
        {
            temp=new node;
            temp->info=data;
            temp->next=p;
            temp->prev=p->prev;
            p->prev->next=temp;
            p->prev=temp;
            return start;
        }
        p=p->next;
    }
    cout<<n<<" not present in list"<<endl;
    return start;
}

node *insert_pos(node *start,int data,int pos)
{
    node *temp,*p;
    if(pos<=0)
    {
        cout<<"Position cannot be zero or negative";
        return start;
    }
    if(pos==1)
    {
        temp=new node;
        temp->info=data;
        temp->next=start;
        temp->prev=NULL;
        if(start!=NULL)
            start->prev=temp;
        start=temp;
        return start;
    }
    int c=1;
    p=start;
    while(p!=NULL && c<pos-1)
    {
        p=p->next;
        c++;
    }
    if(p==NULL)
    {
        cout<<"Position not found!!!"<<endl;
    }
    else
    {
        temp=new node;
        temp->info=data;
        temp->next=p->next;
        temp->prev=p;
        if(p->next!=NULL)
            p->next->prev=temp;
        p->next=temp;
    }
    return start;
}

node *delete_node(node *start,int data)
{
    node *temp;
    if(start==NULL)
    {
        cout<<"Empty list"<<endl;
        return start;
    }
    if(start->next==NULL)
    {
        if(start->info==data)
        {
            temp=start;
            start=NULL;
            delete temp;
            return start;
        }
        else
        {
            cout<<"Element "<<data<<" not found"<<endl;
            return start;
        }
    }
    if(start->info==data)
    {
        temp=start;
        start=start->next;
        start->prev=NULL;
        delete temp;
        return start;
    }
    temp=start->next;
    while(temp->next!=NULL)
    {
        if(temp->info==data)
        {
            temp->prev->next=temp->next;
            temp->next->prev=temp->prev;
            delete temp;
            return start;
        }
        temp=temp->next;
    }
    if(temp->info==data)
    {
        temp->prev->next=NULL;
        delete temp;
        return start;
    }
    cout<<"Element "<<data<<" not found"<<endl;
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
        cout<<"Doubly linked list"<<endl;
        cout<<"1.create a list"<<endl;
        cout<<"2.display"<<endl;
        cout<<"3.count"<<endl;
        cout<<"4.search"<<endl;
        cout<<"5.add to empty list"<<endl;
        cout<<"6.add at beginning"<<endl;
        cout<<"7.add at end"<<endl;
        cout<<"8.add after node"<<endl;
        cout<<"9.add before node"<<endl;
        cout<<"10.add at position"<<endl;
        cout<<"11.delete"<<endl;
        cout<<"12.reverse"<<endl;
        cout<<"13.quit"<<endl;
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
                start=insert_empty(start,data);
                break;

            case 6:
                cout<<"Enter data=";
                cin>>data;
                start=insert_beg(start,data);
                break;

            case 7:
                cout<<"Enter data=";
                cin>>data;
                start=insert_end(start,data);
                break;

            case 8:
                cout<<"Enter data=";
                cin>>data;
                cout<<"Enter data after which you want to insert=";
                cin>>n;
                start=insert_after(start,data,n);
                break;
            
            case 9:
                cout<<"Enter data=";
                cin>>data;
                cout<<"Enter data before which you want to insert=";
                cin>>n;
                start=insert_before(start,data,n);
                break;
            
            case 10:
                cout<<"Enter data=";
                cin>>data;
                cout<<"Enter position=";
                cin>>n;
                start=insert_pos(start,data,n);
                break;
            
            case 11:
                cout<<"Enter element to be deleted=";
                cin>>data;
                start=delete_node(start,data);
                break;
            
            case 12:
                start=reverse(start);
                break;
            
            case 13:
                exit(1);
            
            default:
                cout<<"invalid option"<<endl;
        }
        cout<<"\nPress y/Y and enter to continue.."<<endl;
        cin>>ch;
    }while(ch=='y' || ch=='Y');
    return 0;
}