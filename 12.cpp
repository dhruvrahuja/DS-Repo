#include <iostream>
using namespace std;
void sort(int arr[], int start, int end);
void merge(int arr[], int start, int end);
int main()
{
    int arr[5] = {5, 4, 3, 2, 1};
    int n = 5;
    sort(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}
void sort(int arr[], int start, int end)
{
    if (start < end)
    {
        int mid = (start + end) / 2;
        sort(arr, start, mid);
        sort(arr, mid + 1, end);
        merge(arr, start, end);
    }
}
void merge(int arr[], int start, int end)
{
    int mid = (start + end) / 2;
    int l1 = mid - start + 1;
    int l2 = end - mid;
    int k = start;
    int arr1[l1];
    int arr2[l2];
    for (int i = 0; i < l1; i++)
    {
        arr1[i] = arr[k++];
    }
    for (int i = 0; i < l2; i++)
    {
        arr2[i] = arr[k++];
    }
    k = start;
    int i1 = 0;
    int i2 = 0;
    while (i1 < l1 && i2 < l2)
    {
        if (arr1[i1] > arr2[i2]) 
        {
            arr[k++] = arr2[i2++];
        }
        else
        {
            arr[k++] = arr1[i1++];
        }
    }
    while (i1 < l1)
    {
        arr[k++] = arr1[i1++];
    }
    while (i2 < l2)
    {
        arr[k++] = arr2[i2++];
    }
}
