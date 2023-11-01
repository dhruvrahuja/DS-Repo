#include <iostream>
#include <stack>
using namespace std;
class MinStack {
private:
    stack<int> mainStack;
    stack<int> minStack;
public:
    void push(int x) {
        mainStack.push(x);
        if (minStack.empty() || x <= minStack.top()) {
            minStack.push(x);
        }
    }
    void pop() {
        if (!mainStack.empty()) {
            if (mainStack.top() == minStack.top()) {
                minStack.pop();
            }
            mainStack.pop();
        }
    }
    int top() {
        if (!mainStack.empty()) {
            return mainStack.top();
        }
        return -1; // Return some error value in case of empty stack
    }
    int getMin() {
        if (!minStack.empty()) {
            return minStack.top();
        }
        return -1; // Return some error value in case of empty stack
    }
};
int main() {
    MinStack minStack;
    minStack.push(3);
    minStack.push(5);
    minStack.push(2);
    minStack.push(1);
    cout << "Minimum element: " << minStack.getMin() << endl; // Output: 1
    minStack.pop();
    cout << "Top element: " << minStack.top() << endl; // Output: 2
    cout << "Minimum element: " << minStack.getMin() << endl; // Output: 2
    return 0;
}
