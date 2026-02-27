/*****************************************************************
You are given a sorted (non-decreasing) array of integers arr of length n
and an integer target. Find two distinct elements in the array such that their
sum is equal to target. Return their 0-based indices (i, j) such that:0 ≤ i < j < n.
You must solve the problem using constant extra space, and you may not use
the same element twice. It is guaranteed that exactly one valid pair exists.
e.g. arr = [1, 2, 4, 6, 10], target = 8.
*******************************************************************/


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

