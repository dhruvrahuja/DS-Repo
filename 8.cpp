#include <iostream>
using namespace std;
int main()
{
    int n, temp;
    cout << "enter array length ";
    cin >> n;
    int arr[n];
    cout << "enter elements ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j],arr[j+1]);
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}