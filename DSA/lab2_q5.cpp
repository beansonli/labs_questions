/******************************************************************************
- Space required to store any two-dimensional array is number of rows x columns.
Assuming array is used to store elements of the following matrices, implement an
efficient way that reduces the space requirement.
(a) Diagonal Matrix.
(b) Tri-diagonal Matrix.
(c) Lower triangular Matrix.
(d) Upper triangular Matrix.
(e) Symmetric Matrix

*******************************************************************************/

#include <iostream>
using namespace std;

// diagonal matrix
int diagGet(int d[], int i, int j) {
    if (i == j)
        return d[i];
    return 0;
}

// tridiagonal matrix
int triGet(int t[], int i, int j, int n) {
    if (i - j == 1)
        return t[i - 1];
    else if (i == j)
        return t[n - 1 + i];
    else if (j - i == 1)
        return t[2*n - 1 + i];
    else
        return 0;
}

// lower triangular
int lowerGet(int l[], int i, int j) {
    if (i >= j)
        return l[i*(i+1)/2 + j];
    return 0;
}

// upper triangular
int upperGet(int u[], int i, int j, int n) {
    if (i <= j)
        return u[i*n - i*(i-1)/2 + (j - i)];
    return 0;
}

// symmetric matrix
int symGet(int s[], int i, int j) {
    if (i >= j)
        return s[i*(i+1)/2 + j];
    else
        return s[j*(j+1)/2 + i];
}

int main() {
    int diag[] = {1, 2, 3};
    int lower[] = {1,2,3,4,5,6};
    int sym[] = {1,2,3,4,5,6};

    cout << "Diagonal (2,2): " << diagGet(diag, 2, 2) << endl;
    cout << "Lower (2,1): " << lowerGet(lower, 2, 1) << endl;
    cout << "Symmetric (0,2): " << symGet(sym, 0, 2) << endl;

}

