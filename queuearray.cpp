#include<iostream>
using namespace std;
int n=20;
class queue
{
    int *arr;
    int front;
    int back;
    public:
        queue()
        {
            arr=new int(n);
            front=-1;
            back=-1;
        }
        void push(int x)
        {
            if(back==n-1)
            {
                cout<<"queue full";
            }
            else
            {
                arr[++back]=x;
                if(front==-1)
                {
                    front++;
                }
            }
        }
        void pop()
        {
            if(front==-1||front>back)
            {
                cout<<"empty queue";
            }
            front++;
        }
        void peek()
        {
            if(front==-1||front>back)
            {
                cout<<"empty queue";
                return;
            }
            cout<<arr[front];
        }
        bool isempty()
        {
            if(front==-1||front>back)
            {
                return true;
            }
            return false;
        }
};
int main()
{
    queue q;
    q.push(5);
    q.push(4);
    q.push(3);
    q.pop();
    q.pop();
    q.pop();
    q.peek();
}