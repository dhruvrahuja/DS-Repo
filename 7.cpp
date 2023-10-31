#include<iostream>
using namespace std;
int binarysearch(int arr[],int n,int key)
{
    int start=0;
    int end=n-1;
    int mid=start+(end-start)/2;
    while(start<=end)
    {
        if(arr[mid]==key)
        {
            return mid;
        }
        if(key>arr[mid])
        {
            start=mid+1;
        }
        if(key<arr[mid])
        {
            end=mid-1;
        }
        mid=start+(end-start)/2;
    }
    return -1;
}
int main()
{
    int key;
    int arr1[5]={1,2,3,4,5};
    cout<<"enter element ";
    cin>>key;
        int result=binarysearch(arr1,5,key);
    switch(result){
        case -1:
            cout<<"element not found"<<endl;
            break;
        default:
            cout<<"element found at index "<<result;
            break;
    }
}