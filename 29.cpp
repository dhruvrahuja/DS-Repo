#include<iostream>
using namespace std;
int n=100;
class stack
{
    int*arr;
    int top;
    public:
        stack()
        {
            arr=new int[n];
            top=-1;
        }
        void push(int x)
        {
            if(top==n-1)
            {
                cout<<" stack overflow "<<endl;
            }
            else
            {
                arr[++top]=x;
            }
        }
        void pop()
        {
            if(top==-1)
            {
                cout<<" undeflow "<<endl;
            }
            else
            {
                top--;
            }
        }
        int attop()
        {
            if(top==-1)
            {
                return -1;
            }
            return arr[top];
        }
        bool isempty()
        {
            return (top==-1);
        }
};
int main()
{
    stack st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.pop();
    cout<<"element at top is "<<st.attop()<<endl;
    if(st.isempty())
    {
        cout<<"stack empty "<<endl;
    }
    else
    {
        cout<<"stack is not empty "<<endl;
    }
}