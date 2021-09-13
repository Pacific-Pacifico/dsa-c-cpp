#include<iostream>
using namespace std;

struct node 
{
    node *prev;
    int info;
    node *next;
};

void display(node *last)
{
    if(last==NULL)
    {
        cout<<"List is empty!!"<<endl;
        return;
    }
    cout<<"List: ";
    node *p=last->next;
    do
    {
        cout<<p->info<<" ";
        p=p->next;
    } while (p!=last->next);
    cout<<endl;
}

int count(node *last)
{
    node *p=NULL;
    int c=0;
    if(last==NULL)
        return 0;
    p=last->next;
    do
    {
        c++;
        p=p->next;
    }while(p!=last->next);
    return c;
}

int search(node *last,int ser)
{
    node *p=last->next;
    int pos=-1;
    do
    {
        pos++;
        if(p->info==ser)
            return pos;
        p=p->next;
    }while(p!=last->next);
    return -1;
}

node *insert_empty(node *last,int data)
{
    node *temp;
    temp=new node;
    temp->info=data;
    last=temp;
    last->next=last;
    return last;
}

node *insert_beg(node *last,int data)
{
    node *temp;
    temp=new node;
    temp->info=data;
    temp->next=last->next;
    last->next=temp;
    return last;
}

node *insert_end(node *last,int data)
{
    node *temp;
    temp=new node;
    temp->info=data;
    temp->next=last->next;
    last->next=temp;
    last=temp;
    return last;
}

node *create_list(node *last)
{
    int num,data;
    cout<<"Enter number of nodes=";
    cin>>num;
    cout<<"Enter data for node 1= ";
    cin>>data;
    last=insert_empty(last,data);
    for(int i=2;i<=num;i++)
    {
        cout<<"Enter data for node "<<i<<"= ";
        cin>>data;
        last=insert_end(last,data);
    }
    return last;
}

node *insert_after(node *last,int data,int n)
{
    node *p,*temp;
    p=last->next;
    do
    {
        if(p->info==n)
        {
            temp=new node;
            temp->info=data;
            temp->next=p->next;
            p->next=temp;
            if(p==last)
                last=temp;
            return last;
        }
        p=p->next;
    } while (p!=last->next);
    cout<<n<<" not found in the list"<<endl;
    return last;
}

node *insert_before(node *last,int data,int n)
{
    node *p,*temp;
    if(last==NULL)
    {
        cout<<"Empty list!!!"<<endl;
        return last;
    }
    if(last->next->info==n)
    {
        temp=new node;
        temp->info=data;
        temp->next=last->next;
        last->next=temp;
        return last;
    }
    p=last->next;
    do
    {
        if(p->next->info==n)
        {
            temp=new node;
            temp->info=data;
            temp->next=p->next;
            p->next=temp;
            return last;
        }
        p=p->next;
    } while (p->next!=last->next);
    cout<<n<<" not found in the list"<<endl;
    return last;
}

node *insert_pos(node *last,int data,int pos)
{
    return last;
}

node *delete_node(node *last,int data)
{
    node *temp,*p;
    if(last==NULL)
    {
        cout<<"Empty list!!!"<<endl;
        return last;
    }
    if(last->next==last && last->info==data)
    {
        temp=last;
        last=NULL;
        delete temp;
        return last;
    }
    if(last->next->info==data)
    {
        temp=last->next;
        last->next=temp->next;
        delete temp;
        return last;
    }
    p=last->next;
    while(p->next!=last)
    {
        if(p->next->info==data)
        {
            temp=p->next;
            p->next=temp->next;
            delete temp;
            return last;
        }
        p=p->next;
    }
    if(last->info==data)
    {
        temp=last;
        p->next=last->next;
        last=p;
        delete temp;
        return last;
    }
    cout<<data<<" not found in the list."<<endl;
    return last;
}

node *reverse(node *last)
{
    return last;
}

void clear();

int main()
{
    node *last=NULL;
    int option,data,n;
    char ch;
    do
    {
        clear();
        cout<<"Circular Singly linked list"<<endl;
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
                last=create_list(last);
                break;
            
            case 2:
                display(last);
                break;

            case 3:
                cout<<"Number of elements="<<count(last)<<endl;
                break;

            case 4:
                int ser,pos;
                cout<<"Enter element to search=";
                cin>>ser;
                pos=search(last,ser);
                if(pos==-1)
                    cout<<"Not found!!!"<<endl;
                else
                    cout<<"found at position="<<pos+1<<endl;
                break;
            
            case 5:
                cout<<"Enter data=";
                cin>>data;
                last=insert_empty(last,data);
                break;

            case 6:
                cout<<"Enter data=";
                cin>>data;
                last=insert_beg(last,data);
                break;

            case 7:
                cout<<"Enter data=";
                cin>>data;
                last=insert_end(last,data);
                break;

            case 8:
                cout<<"Enter data=";
                cin>>data;
                cout<<"Enter data after which you want to insert=";
                cin>>n;
                last=insert_after(last,data,n);
                break;
            
            case 9:
                cout<<"Enter data=";
                cin>>data;
                cout<<"Enter data before which you want to insert=";
                cin>>n;
                last=insert_before(last,data,n);
                break;
            
            case 10:
                cout<<"Enter data=";
                cin>>data;
                cout<<"Enter position=";
                cin>>n;
                last=insert_pos(last,data,n);
                break;
            
            case 11:
                cout<<"Enter element to be deleted=";
                cin>>data;
                last=delete_node(last,data);
                break;
            
            case 12:
                last=reverse(last);
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

void clear()
{
    #if defined(__linux__) || defined(__unix__) || defined(__APPLE__)
    system("clear");
    #endif
    #if defined(_WIN32) || defined(_WIN64)
    system("cls");
    #endif
}