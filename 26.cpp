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
    node* node1= new node(2);
    node*head1=node1;
    insert(head1,2,4);
    insert(head1,3,6);
    node*node2 = new node(1);
    node*head2=node2;
    insert(head2,2,3);
    insert(head2,3,5);
    node*final=sortTwoLists(head1,head2);
    print(head1);
    print(head2);
    print(final);
}
