#include<iostream.h>
#include<conio.h>

int main()
{
    int i,j;
    clrscr();
    for(i=1;i<=5;i++)
    {
        for(j=5;j>i;j--)
            cout<<" ";
        for(j=0;j<(2*i-1);j++)
        {
            cout<<"*";
        }
        cout<<endl;
    }
    getch();
    return 0;
}