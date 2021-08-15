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

        long get_factorial()
        {
            if(num==0)
                return 1;
            for(int i=num;i>=1;i--)
            {
                f=f*i;
            }
            return f;
        }
};

int main()
{
    int num;
    cout<<"Enter a positive integer=";
    cin>>num;
    if (num<0)
    {
        cout<<"Error: integer cannot be negative"<<endl;
        return 0;
    }
    Factorial obj=Factorial(num);
    cout<<"\nFactorial="<<obj.get_factorial()<<endl;
}