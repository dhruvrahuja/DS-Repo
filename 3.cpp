#include <iostream>
using namespace std;
void insertElement(int arr[], int& size, int location, int value) {
    if(size >= 100) {
        cout << "Array is full. Cannot insert more elements.\n";
        return;
    }
    if(location < 0 || location > size) {
        cout << "Invalid location for insertion.\n";
        return;
    }
    for(int i = size; i > location; i--) {
        arr[i] = arr[i - 1];
    }
    arr[location] = value;
    size++;
}
void deleteElement(int arr[], int& size, int location) {
    if(size <= 0) {
        cout << "Array is empty. Cannot delete elements.\n";
        return;
    }
    if(location < 0 || location >= size) {
        cout << "Invalid location for deletion.\n";
        return;
    }
    for(int i = location; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    size--;
}
int main() {
    int arr[100] = {1, 2, 3, 4, 5};
    int size = 5;
    insertElement(arr, size, 2, 10);
    for(int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    deleteElement(arr, size, 3);
    for(int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
