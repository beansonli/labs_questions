/******************************************************************************
- Implement the Binary search algorithm regarded as a fast search algorithm with run-time
complexity of Ο(log n) in comparison to the Linear Search.
- Bubble Sort isthe simplestsorting algorithm that works by repeatedly swapping the adjacent
elements if they are in wrong order. Code the Bubble sort with the following elements:
64, 34, 25, 12, 22, 11, 90.

*******************************************************************************/

#include <iostream>
using namespace std;

// bubble sort
void sort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                int t = a[j];
                a[j] = a[j + 1];
                a[j + 1] = t;
            }
        }
    }
}

// linear search
int linear(int a[], int n, int x, int &c) {
    c = 0;
    for (int i = 0; i < n; i++) {
        c++;
        if (a[i] == x)
            return i;
    }
    return -1;
}

// binary search
int binary(int a[], int n, int x, int &c) {
    int l = 0, h = n - 1, m;
    c = 0;

    while (l <= h) {
        c++;
        m = (l + h) / 2;

        if (a[m] == x)
            return m;
        else if (a[m] < x)
            l = m + 1;
        else
            h = m - 1;
    }
    return -1;
}

int main() {
    int a[50], n, x;
    int lc, bc;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++)
        cin >> a[i];

    sort(a, n);

    cout << "Sorted array:\n";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;

    cout << "Enter element to search: ";
    cin >> x;

    linear(a, n, x, lc);
    binary(a, n, x, bc);

    cout << "Linear search comparisons: " << lc << endl;
    cout << "Binary search comparisons: " << bc << endl;


}
