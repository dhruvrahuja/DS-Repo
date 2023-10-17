#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class Queue {
private:
    Node* front;
    Node* rear;
public:
    Queue() {
        front = nullptr;
        rear = nullptr;
    }
    void enqueue(int val) {
        Node* newNode = new Node(val);

        if (isEmpty()) {
            front = rear = newNode;
            return;
        }

        rear->next = newNode;
        rear = newNode;
    }
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue.\n";
            return;
        }

        Node* temp = front;
        front = front->next;
        delete temp;

        if (front == nullptr) {
            rear = nullptr; // Reset rear if queue becomes empty
        }
    }
    int peek() {
        if (isEmpty()) {
            cout << "Queue is empty. No element to peek.\n";
            return -1;
        }

        return front->data;
    }
    bool isEmpty() {
        return front == nullptr;
    }
};
int main() {
    Queue queue;
    queue.enqueue(5);
    queue.enqueue(10);
    queue.enqueue(15);
    cout << "Front element: " << queue.peek() << endl;
    queue.dequeue();
    cout << "Front element after dequeue: " << queue.peek() << endl;
    queue.dequeue();
    queue.dequeue();
    if (queue.isEmpty()) {
        cout << "Queue is empty.\n";
    } else {
        cout << "Queue is not empty.\n";
    }
    return 0;
}
