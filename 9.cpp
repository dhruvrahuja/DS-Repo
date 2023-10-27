#include <iostream>
using namespace std;
void viewarray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void sortarray(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minindex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minindex])
            {
                minindex = j;
            }
        }
        swap(arr[i], arr[minindex]);
    }
}
int main()
{
    int n;
    cout << "enter number of elements ";
    cin >> n;
    int arr[n];
    cout << "enter elements ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sortarray(arr, n);
    viewarray(arr, n);
}