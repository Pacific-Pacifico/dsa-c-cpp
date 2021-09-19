#include<iostream>
#include<math.h>
using namespace std;

int main()
{
    int i,size,height,*tree;
    cout<<"Enter height of tree=";
    cin>>height; 
    size=pow(2,height)-1;
    tree=new int[size];
    for(i=0;i<size;i++)
    {
        cout<<"Enter element at index "<<i<<" = ";
        cin>>tree[i];
    }
    cout<<"tree array: ";
    for(i=0;i<size;i++)
    {
        cout<<tree[i]<<" ";
    }   
}