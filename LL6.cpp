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
        cout << " memory is free for node with data " << value << endl;
    }
};
void inserthead(node*&head,int d)
{
    node*temp=new node(d);
    temp->next=head;
    head=temp;
}
void inserttail(node*&tail,int d)
{
    node*temp=new node(d);
    tail->next=temp;
    tail=tail->next;//tail=temp
}
void deletehead(node*&head)
{
    node*temp=head;
    head=head->next;
    delete temp;
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
node* findNthFromEnd(node* head, int n) {
    node* slow = head;
    node* fast = head;
    for (int i = 0; i < n; i++) {
        fast = fast->next;
    }
    while (fast != NULL) {
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}
int main()
{
    node* node1= new node(10);
    node*head=node1;
    node*tail=node1;
}
