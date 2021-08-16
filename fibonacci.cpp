#include<iostream>
using namespace std;

class Fibonacci
{
    int n,n1,n2,n3;

    public:
        Fibonacci(int n)
        {
            this->n=n;
            n1=0;
            n2=1;
        }

        void fib()
        {
            for(int i=1;i<=n-2;i++)
            {
                n3=n1+n2;
                cout<<n3<<", ";
                n1=n2;
                n2=n3;
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
    obj.fib();
    cout<<endl;
    return 0;
}