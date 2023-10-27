#include <iostream>
using namespace std;
void insertbeginning(int arr[], int& size, int value) {
    if(size >= 100) {
        cout << "Array is full. Cannot insert more elements.\n";
        return;
    }
    for(int i = size; i > 0; i--) {
        arr[i] = arr[i - 1];
    }
    arr[0] = value;
    size++;
}
void deletebeginning(int arr[], int& size) {
    if(size <= 0) {
        cout << "Array is empty. Cannot delete elements.\n";
        return;
    }
    for(int i = 0; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    size--;
}
int main() {
    int arr[100] = {1, 2, 3, 4, 5};
    int size = 5;
    insertbeginning(arr, size, 2);
    for(int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    deletebeginning(arr, size);
    for(int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
