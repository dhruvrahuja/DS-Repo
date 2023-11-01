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
node* findMergePoint(node* head1, node* head2) {
    int len1 = 0, len2 = 0;
    node* temp1 = head1;
    node* temp2 = head2;

    // Calculate the lengths of both linked lists
    while (temp1 != NULL) {
        len1++;
        temp1 = temp1->next;
    }

    while (temp2 != NULL) {
        len2++;
        temp2 = temp2->next;
    }

    // Traverse the longer linked list by the absolute difference
    int diff = abs(len1 - len2);
    temp1 = head1;
    temp2 = head2;

    if (len1 > len2) {
        for (int i = 0; i < diff; i++) {
            temp1 = temp1->next;
        }
    } else {
        for (int i = 0; i < diff; i++) {
            temp2 = temp2->next;
        }
    }

    while (temp1 != NULL && temp2 != NULL) {
        if (temp1 == temp2) {
            return temp1; 
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
    }

    return NULL; 
}

int main()
{
    node* node1= new node(10);
    node*head=node1;
    insert(head,2,3);
    insert(head,3,4);
    node*node2=new node(15);
    node*head2=node2;
    insert(head2,2,7);
    insert(head2,3,8);
    if(!findMergePoint(head,head2))
    {
        cout<<"no merge point ";
    }
    else
    {
        cout<<"intersecting at "<<findMergePoint(head,head2)->data;
    }
}
