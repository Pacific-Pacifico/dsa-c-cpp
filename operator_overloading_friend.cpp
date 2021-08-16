// program to sum the length and breadth of
// two rectangles and create third rectangle
// by overloading + operator using operator() function
// as friend of class Rectangle.

#include<iostream>
using namespace std;

class Rectangle
{
    float length,breadth;

    public:
        Rectangle()
        {
        }

        Rectangle(float length,float breadth)
        {
            this->length=length;
            this->breadth=breadth;
        }

        void show()
        {
            cout<<"Length="<<length<<endl;
            cout<<"breadth="<<breadth<<endl;
        }

        friend Rectangle operator+(Rectangle,Rectangle);
};

Rectangle operator+(Rectangle r1,Rectangle r2)
{
    Rectangle obj;
    obj.length = r1.length + r2.length;
    obj.breadth = r1.breadth + r2.breadth;
    return obj;
}

int main()
{
    float l1,b1,l2,b2;
    cout<<"Enter length and breadth of rectangle 1=";
    cin>>l1>>b1;
    Rectangle r1=Rectangle(l1,b1);
    cout<<"Enter length and breadth of rectangle 2=";
    cin>>l2>>b2;
    Rectangle r2=Rectangle(l2,b2);
    Rectangle r3=r1+r2;  //operator function (friend) called here
    cout<<"Dimensions of third rectangle:"<<endl;
    r3.show();
}