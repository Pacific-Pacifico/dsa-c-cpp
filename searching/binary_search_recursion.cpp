// binary search

#include<iostream>
using namespace std;

//using recursion
int bsearch(int arr[],int ser,int low,int high)
{
    if(low<=high)
    {
        int mid=low+(high-low)/2;
        if(ser==arr[mid])
            return mid;
        if(ser<arr[mid])
            return bsearch(arr,ser,low,mid-1);     
        return bsearch(arr,ser,mid+1,high);   
        // for descending list swap the above return statements only 
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
    int index=bsearch(arr,ser,0,n-1);
    if(index==-1)
        cout<<"Not found!!"<<endl;
    else
        cout<<"Found at position="<<index+1<<endl;
    return 0;
}