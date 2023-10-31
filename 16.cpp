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
void inserthead(node*&head,int d){
    node*temp=new node(d);
    temp->next=head;
    head=temp;
}
void deletehead(node*&head)
{
    node*temp=head;
    head=head->next;
    delete temp;
}
void print(node *&head){
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
    print(head);
    inserthead(head,5);
    print(head);
    inserthead(head,4);
    print(head);
    deletehead(head);
    print(head);
}
