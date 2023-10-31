#include<iostream>
using namespace std;
class node
{
    public:
    int data;
    node* next;
    node(int x)
    {
        this->data=x;
        this->next=NULL;
    }
};
class stack
{
    private:
        node*top;
    public:
        stack()
        {
            top=NULL;
        }
        void push(int val)
        {
            node*temp=new node(val);
            temp->next=top;
            top=temp;
        }
        bool isempty()
        {
            return(top==NULL);
        }
        void pop()
        {
            if(isempty())
            {
                cout<<"stack empty"<<endl;
                return;
            }
            node*temp=top;
            top=top->next;
            delete temp;
        }
        int TOP()
        {
            if(isempty())
            {
                return -1;
            }
            else
            {
                return top->data;
            }
        }
};
int main()
{
    stack s1;
    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.push(4);
    s1.pop();
    cout<<"element at top is "<<s1.TOP()<<endl;
    if(s1.isempty())
    {
        cout<<"stack is empty ";
    }
    else{
        cout<<"Stack is not empty ";
    }
}