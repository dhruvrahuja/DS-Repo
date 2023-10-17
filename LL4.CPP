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
node* sortTwoLists(node* first, node* second) {
    node* third = new node(-1);
    node* temp = third;
    while (first != NULL && second != NULL) {
        if (first->data <= second->data) {
            node* insi = new node(first->data);
            temp->next = insi;
            first = first->next;
        }
        else {
            node* insi = new node(second->data);
            temp->next = insi;
            second = second->next;
        }
        temp = temp->next;
    }
    while (first != NULL) {
        node* insi = new node(first->data);
        temp->next = insi;
        temp = temp->next;
        first = first->next;
    }
    while (second != NULL) {
        node* insi = new node(second->data);
        temp->next = insi;
        temp = temp->next;
        second = second->next;
    }
    return third->next;
}
int main()
{
    node* ans = new node(5);
    node* head = ans;
    node* tail = ans;
}