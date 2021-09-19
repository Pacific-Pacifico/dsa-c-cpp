#include<iostream>
using namespace std;

class Item
{
    char icode[50],iname[50];
    int qty;
    double rate,total;

    public:
        void input()
        {
            cout<<"Enter item code:";
            fgets(icode,50,stdin);
            cout<<"Enter item name:";
            fgets(iname,50,stdin);
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
    i.input();
    i.output();
    return 0;
}