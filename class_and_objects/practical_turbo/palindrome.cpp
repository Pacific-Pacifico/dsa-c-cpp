#include<iostream.h>
#include<conio.h>

void isPalindrome(int num)
{
    int n,r,rev=0;
    n=num;
    while(n>0)
    {
        r=n%10;
        rev=rev*10+r;
        n=n/10;
    }
    if(num==rev)
        cout<<"Palindrome number"<<endl;
    else
        cout<<"Not Palindrome number"<<endl;
}

int main()
{
    int num;
    clrscr();
    cout<<"Enter a number=";
    cin>>num;
    isPalindrome(num);
    getch();
    return 0;
}