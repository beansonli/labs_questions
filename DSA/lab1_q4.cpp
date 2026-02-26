#include <iostream>
using namespace std;


void reverse();
void matrixMultiply();
void transpose();


int main() {
    int choice;

    while (1) {
        cout << "\nQUESTION 4 MENU";
        cout << "\n1. Reverse Array";
        cout << "\n2. Matrix Multiplication";
        cout << "\n3. Matrix Transpose";
        cout << "\n4. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                reverse();
                break;

            case 2:
                matrixMultiply();
                break;

            case 3:
                transpose();
                break;

            case 4:
                return 0;

            default:
                cout << "Invalid choice";
        }
    }
}

//reverse array
void reverse() {
    int arr[50], n, temp;

    cout << "Enter number of elements: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < n / 2; i++) {
        temp = arr[i];
        arr[i] = arr[n - i - 1];
        arr[n - i - 1] = temp;
    }

    cout << "Reversed array:\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

//matrix multiplication
void matrixMultiply() {
    int a[10][10], b[10][10], c[10][10];
    int r1, c1, r2, c2;

    cout << "Enter rows and columns of first matrix: ";
    cin >> r1 >> c1;

    cout << "Enter rows and columns of second matrix: ";
    cin >> r2 >> c2;

    if (c1 != r2) {
        cout << "Matrix multiplication not possible\n";
        return;
    }

    cout << "Enter elements of first matrix:\n";
    for (int i = 0; i < r1; i++)
        for (int j = 0; j < c1; j++)
            cin >> a[i][j];

    cout << "Enter elements of second matrix:\n";
    for (int i = 0; i < r2; i++)
        for (int j = 0; j < c2; j++)
            cin >> b[i][j];

    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            c[i][j] = 0;
            for (int k = 0; k < c1; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    cout << "Result matrix:\n";
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            cout << c[i][j] << " ";
        }
        cout << endl;
    }
}

//matrix transpose
void transpose() {
    int a[10][10], t[10][10];
    int r, c;

    cout << "Enter rows and columns: ";
    cin >> r >> c;

    cout << "Enter elements of matrix:\n";
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            cin >> a[i][j];

    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            t[j][i] = a[i][j];

    cout << "Transpose of matrix:\n";
    for (int i = 0; i < c; i++) {
        for (int j = 0; j < r; j++) {
            cout << t[i][j] << " ";
        }
        cout << endl;
    }
}