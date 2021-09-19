#include<iostream.h>
#include<conio.h>

int isPrime(int num)
{
    int i,f=1;
    for(i=2;i<=(num/2);i++)
    {
        if(num%i==0)
        {
            f=0;
            break;
        }
    }
    return f;
}

int main()
{
    int i,n;
    clrscr();
    for(i=2;i<=100;i++)
    {
        if(isPrime(i))
            cout<<i<<", ";
    }
    getch();
    return 0;
}