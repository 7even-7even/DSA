#include <bits/stdc++.h>
using namespace std;

void heapify(vector<int> &arr, int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = left + 1;

    if (left < n && arr[left] > arr[largest])
    {
        largest = left;
    }

    if (right < n && arr[right] > arr[largest])
    {
        largest = right;
    }

    if (i != largest)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(vector<int> &arr, int n)
{
    for(int i = n / 2 - 1; i >=0 ; i++){
        heapify(arr , n , i);
    }

    for(int i = n - 1; i >= 0 ; i++){
        swap(arr[0] , arr[i]);

        heapify(arr , n , 0);
    }

    cout << "\nThe Sorted Array is :" << endl;
    for(int i = 0; i < n ; i++){
        cout << arr[i] << "  " ;
    }
    cout << endl;

    return;
}

int main()
{
    vector<int> arr;
    int n;
    cout << "\nEnter the Size of Input Array: ";
    cin >> n;
    arr.resize(n);
    cout << "\nEnter the Input Array: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    heapSort(arr, n);

    return 0;
}