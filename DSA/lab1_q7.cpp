/*********************************************************
The relative order of the elements should be kept the same. Return the number of
unique elements k. The first k elements of nums should contain the unique
elements in their original order. The remaining elements beyond k do not matter.
e.g. nums = [1, 1, 2, 2, 3]
k = 3
nums = [1, 2, 3, _, _]
********************************************************/



#include <iostream>
using namespace std;

int uniqueCount(int nums[], int n) {
    int k = 1;

    for (int i = 1; i < n; i++) {
        if (nums[i] != nums[i - 1]) {
            nums[k] = nums[i];
            k++;
        }
    }
    return k;
}

int main() {
    int nums[50], n;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int k = uniqueCount(nums, n);

    cout << "k = " << k << endl;
    for (int i = 0; i < k; i++) {
        cout << nums[i] << " ";
    }

    return 0;
}

