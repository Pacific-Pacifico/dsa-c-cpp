#include<iostream>
using namespace std;

class Fibonacci
{
    int n1,n2,n3;

    public:
        Fibonacci(int num)
        {
            n1=0;
            n2=1;
        }

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
    cout<<"Enter a positive integer=";
    cin>>num;
    Fibonacci obj=Fibonacci(num);
    cout<<"0, 1, ";
    obj.fib(num-2);
    return 0;
}