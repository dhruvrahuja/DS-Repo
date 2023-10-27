#include <iostream>
using namespace std;
void insertElement(int arr[], int& size, int value) {
    if(size >= 100) {
        cout << "Array is full. Cannot insert more elements.\n";
        return;
    }
    arr[size] = value;
    size++;
}
void deleteElement(int arr[], int& size) {
    if(size <= 0) {
        cout << "Array is empty. Cannot delete elements.\n";
        return;
    }
    size--;
}
int main() {
    int arr[100] = {1, 2, 3, 4, 5};
    int size = 5;
    insertElement(arr, size, 2);
    for(int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    deleteElement(arr, size);
    for(int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
