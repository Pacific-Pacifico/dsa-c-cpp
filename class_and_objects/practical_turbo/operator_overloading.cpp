// program to sum the length and breadth of
// two rectangles and create third rectangle
// by overloading + operator using operator() function
// as member of class Rectangle.

#include<iostream.h>
#include<conio.h>

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

        Rectangle operator+(Rectangle r)
        {
            Rectangle obj;
            obj.length = this->length + r.length;
            obj.breadth = this->breadth + r.breadth;
            return obj;
        }

        void show()
        {
            cout<<"Length="<<length<<endl;
            cout<<"breadth="<<breadth<<endl;
        }
};


int main()
{
    float l1,b1,l2,b2;
    clrscr();
    cout<<"Enter length and breadth of rectangle 1=";
    cin>>l1>>b1;
    Rectangle r1=Rectangle(l1,b1);
    cout<<"Enter length and breadth of rectangle 2=";
    cin>>l2>>b2;
    Rectangle r2=Rectangle(l2,b2);
    Rectangle r3=r1+r2;  //operator function called here
    cout<<"Dimensions of third rectangle:"<<endl;
    r3.show();
    getch();
    return 0;
}