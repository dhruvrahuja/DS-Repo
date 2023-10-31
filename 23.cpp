#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* next;
    node(int data)
    {
        this->data=data;
        this->next=NULL;
    }
    ~node() {
        int value = this -> data;
        cout <<endl<< "memory is released for node with data " << value << endl;
    }
};
void insertnode(node*&tail,int element,int d)
{
    node*ans=new node(d);
    node*temp=tail;
    while((temp->data)!=element)
    {
        temp=temp->next;
    }
    ans->next=temp->next;
    temp->next=ans;
}
void view(node*&tail)
{
    if(tail==NULL)
    {
        cout<<"empty "<<endl;
    }
    node*temp=tail;
    do
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }while(temp!=tail);
}
void deletenode(node*&tail,int d)
{

    node*prev=tail;
    node*temp=tail->next;
    if(prev==temp)
    {
        tail=NULL;
        return;
    }
    while(temp->data!=d)
    {
        prev=temp;
        temp=temp->next;
    }
    if(tail==temp)
    {
        tail=prev;
    }
    prev->next=temp->next;
    temp->next=NULL;
    delete temp;
}
int main()
{
    node*tail=new node(5);
    tail->next=tail;
    insertnode(tail,5,4);
    insertnode(tail,5,2);
    view(tail);
    deletenode(tail,2);
    view(tail);
}