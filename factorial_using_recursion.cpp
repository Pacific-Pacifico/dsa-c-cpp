#include<iostream>
using namespace std;

class Factorial
{
    int num;
    long f;

    public:
        Factorial(int num)
        {
            this->num=num;
            f=1;
        }

        //factorial using recursion
        long calc_factorial(int num)
        {
            if(num<=1)
                return 1;
            else
                return num*calc_factorial(num-1);
        }

        long get_factorial()
        {
            f=calc_factorial(num);
            return f;
        }
};

int main()
{
    int num;
    cout<<"Enter an integer=";
    cin>>num;
    if (num<0)
    {
        cout<<"Error: integer cannot be negative"<<endl;
        return 0;
    }
    Factorial obj=Factorial(num);
    cout<<"\nFactorial="<<obj.get_factorial()<<endl;
}