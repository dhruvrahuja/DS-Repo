#include<iostream>
using namespace std;
bool search(int arr[],int len,int element)
{
    for(int i=0;i<len;i++)
    {
        if(arr[i]==element)
        {
            return true;
        }
    }
    return false; 
}
int main()
{
    int arr[5]={1,2,3,4,5};
    if(search(arr,5,2))
    {
        cout<<"element found";
    }
    else
    {
        cout<<"not found";
    }
}