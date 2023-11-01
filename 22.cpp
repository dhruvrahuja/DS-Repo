#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int data)
    {
        this->data=data;
        this->next=NULL;
    }

    ~Node() {
        int value = this -> data;
        cout << "memory is released for Node with data " << value << endl;
    }
};

void insert(Node*& head, int position, int d)
{
    Node* temp = head;
    Node* ans = new Node(d);
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

void remove(Node*& head, int position)
{
    Node* temp = head;
    int count = 0;

    if(position == 1)
    {
        Node* store = head;
        head = head->next;
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

    Node* ans = temp->next;
    temp->next = ans->next;
    ans->next = NULL;
    delete ans;
}

void print(Node *&head)
{
    Node* temp = head;
    while(temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;    
}

Node* intersectionfloyd(Node* head)
{
    if(head == NULL)
    {
        return NULL;
    }

    Node* slow = head;
    Node* fast = head;

    while(slow != NULL && fast != NULL)
    {
        fast = fast->next;
        if(fast != NULL)
        {
            fast = fast->next;
        }
        slow = slow->next;

        if(fast == slow)
        {
            return slow;
        }
    }

    return NULL;
}

Node* starting(Node* head)
{
    if(intersectionfloyd(head) == NULL)
    {
        return NULL;
    }
    else
    {
        Node* temp = intersectionfloyd(head);
        Node* slow = head;
        while(slow != temp)
        {
            slow = slow->next;
            temp = temp->next;
        }
        return slow;
    }
}

void Loopremove(Node* head)
{
    if(intersectionfloyd(head) == NULL)
    {
        return;
    }   
    else
    {
        Node* temp = starting(head);
        while(temp->next != starting(head))
        {
            temp = temp->next;
        }
        temp->next = NULL;
    }
}

Node* removeLoop(Node* head)
{
    if(intersectionfloyd(head) == NULL)
    {
        return head;
    }
    else
    {
        Loopremove(head);
    }
    return head;
}

int main()
{
    Node* Node1= new Node(10);
    Node*head = Node1;
    Node*tail = Node1;

    insert(head,2,3);
    insert(head,3,4);
    tail->next = head->next;

    Node* cycleNode = intersectionfloyd(head);
    if (cycleNode != NULL) {
        cout << "Cycle detected at node with data " << cycleNode->data << endl;

        Loopremove(head);

        cout << "Linked list after removing the cycle: ";
        print(head);
    } else {
        cout << "No cycle detected." << endl;
    }
    return 0;
}
