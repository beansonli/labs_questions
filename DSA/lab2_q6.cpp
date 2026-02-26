/******************************************************************************
- Write a program to implement the following operations on a Sparse Matrix, assuming the
matrix is represented using a triplet.
(a) Transpose of a matrix.
(b) Addition of two matrices.
(c) Multiplication of two matrices.

*******************************************************************************/

#include <iostream>
using namespace std;

struct Triplet {
    int row;
    int col;
    int val;
};

void inputSparse(Triplet a[]) {
    cout << "Enter rows, columns and non-zero elements: ";
    cin >> a[0].row >> a[0].col >> a[0].val;

    cout << "Enter row column value for each non-zero element:\n";
    for (int i = 1; i <= a[0].val; i++) {
        cin >> a[i].row >> a[i].col >> a[i].val;
    }
}

// display triplet matrix
void displaySparse(Triplet a[]) {
    cout << "Row Col Val\n";
    for (int i = 0; i <= a[0].val; i++) {
        cout << a[i].row << "   "
             << a[i].col << "   "
             << a[i].val << endl;
    }
}

// transpose of sparse matrix
void transposeSparse(Triplet a[], Triplet t[]) {
    t[0].row = a[0].col;
    t[0].col = a[0].row;
    t[0].val = a[0].val;

    int k = 1;
    for (int i = 0; i < a[0].col; i++) {
        for (int j = 1; j <= a[0].val; j++) {
            if (a[j].col == i) {
                t[k].row = a[j].col;
                t[k].col = a[j].row;
                t[k].val = a[j].val;
                k++;
            }
        }
    }
}

// addition of two sparse matrices
void addSparse(Triplet a[], Triplet b[], Triplet c[]) {
    if (a[0].row != b[0].row || a[0].col != b[0].col) {
        cout << "Addition not possible\n";
        c[0].val = 0;
        return;
    }

    int i = 1, j = 1, k = 1;
    c[0].row = a[0].row;
    c[0].col = a[0].col;

    while (i <= a[0].val && j <= b[0].val) {
        if (a[i].row == b[j].row && a[i].col == b[j].col) {
            c[k].row = a[i].row;
            c[k].col = a[i].col;
            c[k].val = a[i].val + b[j].val;
            i++; j++; k++;
        }
        else if (a[i].row < b[j].row ||
                (a[i].row == b[j].row && a[i].col < b[j].col)) {
            c[k++] = a[i++];
        }
        else {
            c[k++] = b[j++];
        }
    }

    while (i <= a[0].val) c[k++] = a[i++];
    while (j <= b[0].val) c[k++] = b[j++];

    c[0].val = k - 1;
}

// multiplication of two sparse matrices
void multiplySparse(Triplet a[], Triplet b[], Triplet c[]) {
    if (a[0].col != b[0].row) {
        cout << "Multiplication not possible\n";
        c[0].val = 0;
        return;
    }

    int k = 1;
    c[0].row = a[0].row;
    c[0].col = b[0].col;

    for (int i = 1; i <= a[0].val; i++) {
        for (int j = 1; j <= b[0].val; j++) {
            if (a[i].col == b[j].row) {
                c[k].row = a[i].row;
                c[k].col = b[j].col;
                c[k].val = a[i].val * b[j].val;
                k++;
            }
        }
    }
    c[0].val = k - 1;
}

int main() {
    Triplet A[50], B[50], C[50], T[50];
    int choice;

    cout << "Enter first sparse matrix\n";
    inputSparse(A);

    do{
        cout << "\n1. Transpose\n2. Addition\n3. Multiplication\n4. EXIT \nEnter choice: ";
        cin >> choice;
    
        if (choice == 1) {
            transposeSparse(A, T);
            cout << "\nTranspose matrix:\n";
            displaySparse(T);
        }
        else {
            cout << "\nEnter second sparse matrix\n";
            inputSparse(B);
    
            if (choice == 2) {
                addSparse(A, B, C);
                if (C[0].val != 0)
                    displaySparse(C);
            }
            else if (choice == 3) {
                multiplySparse(A, B, C);
                if (C[0].val != 0)
                    displaySparse(C);
            }
        }
    }while(choice!=4);


}



