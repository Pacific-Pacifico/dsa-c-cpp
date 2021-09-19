#include<iostream.h>
#include<conio.h>
#include<math.h>

void area(double l,double b)
{
    cout<<"Area of rectangle="<<l*b<<endl;
}

void area(double side)
{
    cout<<"Area of square="<<side*side<<endl;
}

void area(double a,double b,double c)
{
    double s,area;
    s=(a+b+c)/2;
    area=sqrt(s*(s-a)*(s-b)*(s-c));
    cout<<"Area of traingle="<<area<<endl;
}

int main()
{
    double length,breadth,s,a,b,c;
    int option;
    clrscr();
    cout<<"Select the required option"<<endl;
    cout<<"1.Area of rectangle"<<endl;
    cout<<"2.Area of square"<<endl;
    cout<<"3.Area of triangle"<<endl;
    cout<<"Enter the required option=";
    cin>>option;
    switch(option)
    {
        case 1:
            cout<<"Enter length=";
            cin>>length;
            cout<<"Enter breadth=";
            cin>>breadth;
            area(length,breadth);
            break;
        
        case 2:
            cout<<"Enter length of side=";
            cin>>s;
            area(s);
            break;
        
        case 3:
            cout<<"Enter length of sides of triangle=";
            cin>>a>>b>>c;
            area(a,b,c);
            break;
        
        default:
            cout<<"Invalid option selected"<<endl;
    }
    getch();
    return 0;
}