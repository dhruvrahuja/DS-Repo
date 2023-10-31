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
void findnode(node*head,int n)
{
    node*p1=head;
    node*p2=head;
    for(int i=0;i<n;i++)
    {
        p1=p1->next;
    }
    while(p1!=NULL)
    {
        p1=p1->next;
        p2=p2->next;
    }
    cout<<n<<"th node from end of linked list is "<<p2->data;
}
int main()
{
    node* node1= new node(10);
    node*head=node1;
    insert(head,2,3);
    insert(head,3,4);
    insert(head,4,6);
    print(head);
    findnode(head,2);
}
