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
void insert(node*& head, int position, int d)
{
    node* temp = head;
    node* ans = new node(d);
    int count = 0;
    if(position == 1)
    {
        ans->next = head;
        head = ans;
        return;
    }
    while(count < position-2){
        if (temp == NULL) {
            cout << "Invalid position. Insertion not possible." << endl;
            return;
        }
        temp = temp->next;
        count++;
    }
    if(temp->next == NULL){
        temp->next=ans;
    }
    else{
        ans->next=temp->next;
        temp->next=ans;
    }
}
void remove(node*& head, int position)
{
    node* temp = head;
    int count = 0;
    if(position == 1)
    {
        node*store=head;
        head=head->next;
        delete store;
        return;
    }
    while(count < position-2){
        if (temp->next== NULL) {
            cout << "Invalid position. Deletion not possible." << endl;
            return;
        }
        temp = temp->next;
        count++;
    }
    node*ans=temp->next;
    temp->next=ans->next;
    ans->next=NULL;
    delete ans;
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
void reverse(node*&head)
{
    if(head->next==NULL||head==NULL)
    {
        return;
    }
    node*temp=head->next;
    reverse(temp);
    head->next->next=head;
    head->next=NULL;
    head=temp;
}
node* middlell(node*head)
{
    node*slow=head;
    node*fast=head;
    while (fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
int main()
{
    node* node1= new node(1);
    node*head=node1;
    insert(head,2,2);
    insert(head,3,3);
    insert(head,4,2);
    insert(head,5,1);
    print(head);
    node*middle=middlell(head);
    node*head2=middle->next;
    middle->next=NULL;
    reverse(head2);
    node*temp1=head;
    node*temp2=head2;
    while(temp1!=NULL&&temp2!=NULL)
    {
        if(temp1->data!=temp2->data)
        {
            cout<<"not a palindrome ";
            exit(0);
        }
        temp1=temp1->next;
        temp2=temp2->next;
    }
    cout<<"its a palindrome ";
}
