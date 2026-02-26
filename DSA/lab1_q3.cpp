#include <iostream>
using namespace std;

void twoSum(int arr[], int n, int target) {
    int left = 0;
    int right = n - 1;

    while (left < right) {
        if (arr[left] + arr[right] == target) {
            cout << "Indices: " << left << " " << right;
            return;
        }
        else if (arr[left] + arr[right] < target) {
            left++;
        }
        else {
            right--;
        }
    }

    cout << "No valid pair found";
}

int main() {
    int arr[50], n, target;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter sorted array elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter target sum: ";
    cin >> target;

    twoSum(arr, n, target);

    return 0;
}
