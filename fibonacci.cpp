#include<iostream>
using namespace std;

class Fibonacci
{
    int num,f;

    public:
        Fibonacci(int num)
        {
            this->num=num;
        }

        int fib(int num)
        {
            if (num<=1)
                return num;
            else
                return fib(num-1) + fib(num-2);
        }

        void get_fib()
        {
            f=fib(num);
            cout<<"fibonacci="<<f<<endl;
        }
};

int main()
{
    int num;
    cout<<"Enter a positive integer=";
    cin>>num;
    Fibonacci obj=Fibonacci(num);
    obj.get_fib();
    return 0;
}