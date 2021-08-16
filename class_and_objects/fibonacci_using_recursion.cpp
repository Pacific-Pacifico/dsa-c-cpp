#include<iostream>
using namespace std;

class Fibonacci
{
    int n1,n2,n3;

    public:
        Fibonacci()
        {
            n1=0;
            n2=1;
        }

        //using recursion
        void fib(int n)
        {
            if (n>0)
            {
                n3=n1+n2;
                cout<<n3<<", ";
                n1=n2;
                n2=n3;
                fib(n-1);
            }
        }
};

int main()
{
    int num;
    cout<<"Enter number of elements=";
    cin>>num;
    if(num<1)
    {
        cout<<"number cannot be negative or zero"<<endl;
        return -1;
    }
    Fibonacci obj=Fibonacci();
    if (num==1)
    {
        cout<<"0,"<<endl;
        return 0;
    }
    cout<<"0, 1, ";
    obj.fib(num-2);
    cout<<endl;
    return 0;
}