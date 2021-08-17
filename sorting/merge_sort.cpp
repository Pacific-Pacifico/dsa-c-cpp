// merge sort 

#include<iostream>
using namespace std;

void merge(int arr[],int lb,int mid,int ub)
{
    int i,j,k,a[ub+1];
    i=lb,j=mid+1,k=lb;
    while(i<=mid && j<=ub)
    {
        if(arr[i]<=arr[j])
        {
            a[k]=arr[i];
            i++;
        }
        else
        {
            a[k]=arr[j];
            j++;
        }
        k++;
    }
    if(i>mid)
    {
        while(j<=ub)
        {
            a[k]=arr[j];
            j++;
            k++;
        }
    }
    else
    {
        while(i<=mid)
        {
            a[k]=arr[i];
            i++;
            k++;
        }
    }
    for(k=lb;k<=ub;k++)
    {
        arr[k]=a[k];
    }
}

void merge_sort(int arr[],int lb,int ub)
{
    if(lb<ub)
    {
        int mid=(lb+ub)/2;
        merge_sort(arr,lb,mid);
        merge_sort(arr,mid+1,ub);
        merge(arr,lb,mid,ub);
    }
}

void swap(int &a,int &b)
{
    int temp;
    temp=a;
    a=b;
    b=temp;
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
    int n;
    cout<<"Enter size of array=";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cout<<"Enter element at index "<<i<<" = ";
        cin>>arr[i];
    }
    cout<<"Array: ";
    show(arr,n);

    merge_sort(arr,0,n-1);
    cout<<"Sorted Array: ";
    show(arr,n);
    return 0;
}