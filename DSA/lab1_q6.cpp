/**************************************************
You are given a sorted integer array nums of length n. Remove the duplicates inplace such that each unique element appears only once.
***************************************************/


#include <iostream>
using namespace std;

int remove(int arr[], int n) {
    if (n == 0)
        return 0;

    int k = 1;

    for (int i = 1; i < n; i++) {
        if (arr[i] != arr[i - 1]) {
            arr[k] = arr[i];
            k++;
        }
    }
    return k;
}

int main() {
    int arr[50], n;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter sorted array elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int k = remove(arr, n);

    cout << "Number of unique elements: " << k << endl;
    cout << "Array after removing duplicates:\n";
    for (int i = 0; i < k; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}

