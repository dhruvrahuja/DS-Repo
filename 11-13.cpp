#include <iostream>
using namespace std;
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivot = arr[high];
        int i = low - 1;

        for (int j = low; j <= high - 1; j++) {
            if (arr[j] < pivot) {
                i++;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i + 1], arr[high]);
        int pi = i + 1;
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i >= 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int main() {
    int arr1[] = {64, 34, 25, 12, 22, 11, 90};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);

    // Quick Sort
    quickSort(arr1, 0, n1 - 1);
    
    cout << "Sorted array using Quick Sort: ";
    for (int i = 0; i < n1; i++)
        cout << arr1[i] << " ";
    cout << endl;

    int arr2[] = {64, 34, 25, 12, 22, 11, 90};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);

    // Heap Sort
    heapSort(arr2, n2);

    cout << "Sorted array using Heap Sort: ";
    for (int i = 0; i < n2; i++)
        cout << arr2[i] << " ";
    cout << endl;
    return 0;
}
