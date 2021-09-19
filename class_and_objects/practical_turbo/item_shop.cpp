#include<iostream.h>
#include<conio.h>

class Item
{
    char icode[50],iname[50];
    int qty;
    double rate,total;

    public:
        void input()
        {
            cout<<"Enter item code:";
            gets(icode);
            cout<<"Enter item name:";
            gets(iname);
            cout<<"Enter rate=";
            cin>>rate;
            cout<<"Enter quantity=";
            cin>>qty;
        }

        void output()
        {
            cout<<"\nItem code=";
            puts(icode);
            cout<<"Item name=";
            puts(iname);
            cout<<"Rate="<<rate<<endl;
            cout<<"Quantity="<<qty<<endl;
            cout<<"Total="<<rate*qty<<endl;
        }
};

int main()
{
    Item i;
    clrscr();
    i.input();
    i.output();
    getch();
    return 0;
}