#include<iostream>
using namespace std;

class Reverse
{
    int num,rev;

    public:
        void set_num()
        {
            cout<<"Enter a number=";
            cin>>num;
        }

        void get_reverse()
        {
            int rem,n;
            n=num;
            rev=0;
            while(n)
            {
                rem=n%10;
                rev=rev*10+rem;
                n=n/10;
            }
            cout<<"Reverse of "<<num<<" = "<<rev<<endl;
        }
};

int main()
{
    Reverse r=Reverse();
    r.set_num();
    r.get_reverse();
    return 0;
}