#include<iostream.h>
#include<conio.h>

class Sum
{
    public:
        Sum(double a,double b)
        {
            cout<<"sum of two numbers="<<a+b<<endl;
        }

        Sum(double a,double b,double c)
        {
            cout<<"sum of three numbers="<<a+b+c<<endl;
        }

        Sum(double a,double b,double c,double d)
        {
            cout<<"sum of four numbers="<<a+b+c+d<<endl; 
        }
};

int main()
{
    double a,b,c,d;
    int option;
    clrscr();
    cout<<"Select the required option:"<<endl;
    cout<<"1.Sum of two numbers"<<endl;
    cout<<"2.Sum of three numbers"<<endl;
    cout<<"1.Sum of four numbers"<<endl;
    cout<<"Enter the option"<<endl;
    cin>>option;
    switch(option)
    {
        case 1:
            cout<<"Enter two numbers=";
            cin>>a>>b;
            Sum(a,b);
            break;
        
        case 2:
            cout<<"Enter three numbers=";
            cin>>a>>b>>c;
            Sum(a,b,c);
            break;
        
        case 3:
            cout<<"Enter four numbers=";
            cin>>a>>b>>c>>d;
            Sum(a,b,c,d);
            break;
        
        default:
            cout<<"Invalid input!!!"<<endl;
    }
    getch();
    return 0;
}