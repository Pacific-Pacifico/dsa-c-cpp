#include<iostream>
#include<math.h>
using namespace std;

int countDigits(int num)
{
    int c=0;
    while(num>0)
    {
        num=num/10;
        c++;
    }
    return c;
}

void isArmstrong(int num)
{
    int n,r,c,sum=0;
    c=countDigits(num);
    n=num;
    while(n>0)
    {
        r=n%10;
        sum=sum+pow(r,c);
        n=n/10;
    }
    if(num==sum)
        cout<<"Armstrong number"<<endl;
    else
        cout<<"Not armstrong number"<<endl;
}

int main()
{
    int num;
    cout<<"Enter a number=";
    cin>>num;
    isArmstrong(num);
    return 0;
}