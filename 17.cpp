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
        cout << "memory is released for node with data " << value << endl;
    }
};
void inserttail(node*&tail,int d)
{
    node*temp=new node(d);
    tail->next=temp;
    tail=tail->next;
}
void deletetail(node*&head,node*&tail)
{
    node*temp=head;
    node*prev=NULL;
    while(temp->next!=NULL)
    {
        prev=temp;
        temp=temp->next;
    }
    tail=prev;
    prev->next=NULL;
    delete temp;
}
void print(node *&head)//traversing a linked list
{
    node*temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;    
}
int main()
{
    node* node1= new node(10);
    node*head=node1;
    node*tail=node1;
    print(head);
    inserttail(tail,5);
    print(head);
    inserttail(tail,6);
    print(head);
    deletetail(head,tail);
    print(head);
}
