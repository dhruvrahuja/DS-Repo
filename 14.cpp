#include <iostream>
#include <vector>
using namespace std;

int findFloor(vector<int>& arr, int target) {
    int left = 0, right = arr.size() - 1;
    int floor = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return arr[mid];
        } else if (arr[mid] > target) {
            right = mid - 1;
        } else {
            floor = arr[mid];
            left = mid + 1;
        }
    }

    return floor;
}

int findCeil(vector<int>& arr, int target) {
    int left = 0, right = arr.size() - 1;
    int ceil = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return arr[mid];
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            ceil = arr[mid];
            right = mid - 1;
        }
    }

    return ceil;
}

int findPeak(vector<int>& arr) {
    int left = 0, right = arr.size() - 1;

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] > arr[mid + 1]) {
            return arr[mid];
        } else if (arr[mid] < arr[mid + 1]) {
            left = mid + 1;
        }
    }

    return arr[left]; // In case there is only one element
}

int findMinimum(vector<int>& arr) {
    int left = 0, right = arr.size() - 1;

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] > arr[right]) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }

    return arr[left];
}

int main() {
    vector<int> rotatedArray = {4, 5, 6, 7, 0, 1, 2};
    int target = 3;

    int floor = findFloor(rotatedArray, target);
    int ceil = findCeil(rotatedArray, target);
    int peak = findPeak(rotatedArray);
    int minimum = findMinimum(rotatedArray);

    cout << "Floor: " << floor << endl;
    cout << "Ceil: " << ceil << endl;
    cout << "Peak: " << peak << endl;
    cout << "Minimum: " << minimum << endl;

    return 0;
}
