// binary search

#include<iostream>
using namespace std;

int bsearch(int arr[],int n,int ser)
{
    int low,mid,high;
    low=0,high=n-1;
    while (low<=high)
    {
        mid=(low+high)/2;
        if(ser==arr[mid])
            return mid;
        else if(ser<arr[mid])  // change < to > for descending order list      
            high=mid-1;
        else
            low=mid+1;
    }
    return -1;
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
    int index=bsearch(arr,n,ser);
    if(index==-1)
        cout<<"Not found!!"<<endl;
    else
        cout<<"Found at position="<<index+1<<endl;
    return 0;
}