// bubble sort 

#include<iostream>
using namespace std;

void bubble_sort(int arr[],int n)
{
    int flag;
    for(int i=0;i<n-1;i++)
    {
        flag=0;    // to check whether swapping occured or not
        for(int j=0;j<n-1-i;j++)
        {
            if(arr[j]>arr[j+1])   // change > to < for descending order    
            {
                swap(arr[j],arr[j+1]);
                flag=1;
            }
        }
        if(flag==0)      // if no swapping occured, no need to sort further 
        {
            break;
        }
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

    bubble_sort(arr,n);
    cout<<"Sorted Array: ";
    show(arr,n);
}