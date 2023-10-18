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
int findMiddle(node* head) {
    if (head == NULL || head->next == NULL) {
        return head->data;
    }

    node* slow = head;
    node* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow->data;
}
int main()
{
    node* node1= new node(10);
    node*head=node1;
    node*tail=node1;
    inserthead(head,5);
    inserthead(head,5);
    inserttail(tail,5);
    cout<<findMiddle(head);
}
