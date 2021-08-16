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
            if(n==1)
            {
                cout<<n1<<","<<endl;
                return;
            }
            cout<<n1<<", "<<n2<<", ";
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
    cout<<"Enter number of elements=";
    cin>>num;
    if(num<1)
    {
        cout<<"number cannot be negative or zero"<<endl;
        return -1;
    }
    Fibonacci obj=Fibonacci(num);
    obj.fib();
    cout<<endl;
    return 0;
}