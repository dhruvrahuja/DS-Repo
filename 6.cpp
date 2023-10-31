#include<iostream>
using namespace std;
int search(int arr[],int len,int element)
{
    for(int i=0;i<len;i++)
    {
        if(arr[i]==element)
        {
            return i;
        }
    }
    return -1; 
}
int main()
{
    int arr[5]={1,2,3,4,5};
    int result=search(arr,5,3);
    switch(result){
        case -1:
            cout<<"element not found"<<endl;
            break;
        default:
            cout<<"element found at index "<<result;
            break;
    }
}