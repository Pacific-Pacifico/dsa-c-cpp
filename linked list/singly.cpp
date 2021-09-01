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
    }
    return pos;
}

int main()
{
    node *start=NULL;
    int option;
    while(1)
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
                    cout<<"Notfound!!!"<<endl;
                else
                    cout<<"fount at position="<<pos+1<<endl;
                break;
            
            case 5:
                break;

            case 6:
                break;

            case 7:
                break;
            
            case 8:
                break;
            
            case 9:
                break;
            
            case 10:
                break;
            
            case 11:
                break;
            
            case 12:
                exit(1);
            
            default:
                cout<<"invalid option"<<endl;
        }
    }
    return 0;
}