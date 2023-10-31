#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node*prev;
    node*next;
    node(int d)
    {
        this->data=d;
        this->prev=NULL;
        this->next=NULL;
    }
    ~node()
    {
        cout<<"memory released for node with data "<<this->data<<endl;
    }
};
void print(node*head){
    node*temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
void inserthead(node*&head,int d)
{
    node*temp=new node(d);
    temp->next=head;
    head->prev=temp;
    head=temp;
}
void inserttail(node*&tail,int d)
{
    node*temp=new node(d);
    tail->next=temp;
    temp->prev=tail;
    tail=temp;
}
void insertmid(node*&head,int position,int d,node*&tail)
{
    if(position==1)
    {
        inserthead(head,d);
        return;
    }
    node*temp=head;
    node*ans=new node(d);
    int count=1;
    while(count<=position-2)
    {
        temp=temp->next;
        count++;
    }
    if(temp->next==NULL)
    {
        inserttail(tail,d);
        return;
    }
    ans->next=temp->next;
    ans->prev=temp;
    (temp->next)->prev=ans;
    temp->next=ans;
}
void deletenode(node*&head,int position,node*&tail)
{
    node*temp=head;
    if(position==1)
    {
        node*temp=head;
        head=head->next;
        head->prev=NULL;
        delete temp;
        return;
    }
    node*curr=head;
    node*prev=NULL;
    int count=1;
    while(count<position)
    {
        prev=curr;
        curr=curr->next;
        count++;
    }
    if(curr->next==NULL)
    {
        tail=prev;
        prev->next=NULL;
        curr->prev=NULL;
        delete curr;
        return;
    }
    prev->next=curr->next;
    curr->next=NULL;
    curr->prev=NULL;
    delete curr;
}
int main()
{
    node* ans=new node(5);
    node*head=ans;
    node*tail=ans;
    inserthead(head,7); 
    inserttail(tail,8);
    inserttail(tail,9);
    inserthead(head,4);
    inserthead(head,3);
    insertmid(head,7,1,tail);
    inserttail(tail,6);
    print(head);
    deletenode(head,4,tail);
    print(head);
}