// linear search

#include<iostream>
using namespace std;

void lsearch(int arr[],int n,int ser)
{
    int found=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]==ser)
        {
            cout<<"Found at position="<<i+1<<endl;
            found=1;
            break;   // remove break to print all positions at which element is found
        }

    }
    if(found==0)
    {
        cout<<"Not found!"<<endl;
    }
}

void show(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    const int n=5;
    int ser;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cout<<"Enter element at index "<<i<<" = ";
        cin>>arr[i];
    }
    cout<<"Array: ";
    show(arr,n);

    cout<<"enter element to search=";
    cin>>ser;
    lsearch(arr,n,ser);
    return 0;
}