#include<iostream.h>
#include<stdio.h>
#include<conio.h>

class A
{
    protected:
        int roll;
        char name[50];

    public:
        void get();
        void set();
};

void A::set()
{
    cout<<"Enter name:";
    gets(name);
    cout<<"Enter roll=";
    cin>>roll;
}

void A::get()
{
    cout<<"Name=";
    puts(name);
    cout<<"Roll="<<roll<<endl;
}

class B :public A
{
    protected:
        int marks1,marks2;

    public:
        void getMarks();
        void setMarks();
};

void B::setMarks()
{
    cout<<"Enter marks for subject 1=";
    cin>>marks1;
    cout<<"Enter marks for subject 1=";
    cin>>marks2;
}

void B::getMarks()
{
    cout<<"Marks in subject 1="<<marks1<<endl;
    cout<<"Marks in subject 2="<<marks2<<endl;
}


class C : public B
{
    int total;
    float percent;

    public:
        void show();
};

void C::show()
{
    total=marks1+marks2;
    percent=(total/200.0)*100;
    get();
    getMarks();
    cout<<"total marks="<<total<<endl;
    cout<<"percent="<<percent<<endl;
}

int main()
{
    C obj;
    clrscr();
    obj.set();
    obj.setMarks();
    obj.show();
    getch();
    return 0;
}
