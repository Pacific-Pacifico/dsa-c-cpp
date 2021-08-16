// insertion sort 

#include<iostream>
using namespace std;

void insertion_sort(int arr[],int n)
{
    int temp,i,j;
    for(i=1;i<n;i++)
    {
        temp=arr[i];
        j=i-1;
        while(j>=0 && arr[j]>temp)   //for descending order change > to <
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=temp;
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

    insertion_sort(arr,n);
    cout<<"Sorted Array: ";
    show(arr,n);
}