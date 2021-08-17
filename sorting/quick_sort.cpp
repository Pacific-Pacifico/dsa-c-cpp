// quick sort 

#include<iostream>
using namespace std;

void swap(int &a,int &b)
{
    int temp;
    temp=a;
    a=b;
    b=temp;
}

int partition(int arr[],int lb,int ub)
{
   int pivot=arr[lb];
   int start=lb;
   int end=ub;
   while(start<end)
   {
       while(arr[start]<=pivot)
       {
           start++;
       }
       while(arr[end]>pivot)
       {
           end--;
       }
       if(start<end)
       {
           swap(arr[start],arr[end]);
       }
   }
   swap(arr[lb],arr[end]);
   return end;
}

void quick_sort(int arr[],int lb,int ub)
{
    if(lb<ub)
    {
        int index=partition(arr,lb,ub);
        quick_sort(arr,lb,index-1);
        quick_sort(arr,index+1,ub);
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
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cout<<"Enter element at index "<<i<<" = ";
        cin>>arr[i];
    }
    cout<<"Array: ";
    show(arr,n);

    quick_sort(arr,0,n-1);
    cout<<"Sorted Array: ";
    show(arr,n);
    return 0;
}