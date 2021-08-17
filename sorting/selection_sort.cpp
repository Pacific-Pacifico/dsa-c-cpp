// selection sort 
#include<iostream>
using namespace std;

void swap(int &a,int &b)
{
    int temp;
    temp=a;
    a=b;
    b=temp;
}

// for sorting in ascending order
void selection_sort(int arr[],int n)
{
    int min;
    for(int i=0;i<n-1;i++)
    {
        min=i;
        for(int j=i+1;j<n;j++)
        {
            if(arr[j]<arr[min])    
            {
                min=j;
            }
        }
        if(i!=min)
        {
            swap(arr[i],arr[min]);
        }
    }
}

// for sorting in descending order
void selection_sort_descending(int arr[],int n)
{
    int max;
    for(int i=0;i<n-1;i++)
    {
        max=i;
        for(int j=i+1;j<n;j++)
        {
            if(arr[j]>arr[max])    
            {
                max=j;
            }
        }
        if(i!=max)
        {
            swap(arr[i],arr[max]);
        }
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

    //for ascending
    selection_sort(arr,n);
    cout<<"Sorted Array(ascending): ";
    show(arr,n);

    // for descending
    selection_sort_descending(arr,n);
    cout<<"Sorted Array(descending): ";
    show(arr,n);
    return 0;
}