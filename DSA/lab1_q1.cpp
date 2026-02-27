/******************************************************************************
Develop a Menu driven program to demonstrate the following operations of Arrays
——MENU——-
1.CREATE
2.DISPLAY
3.INSERT
4.DELETE
5.LINEAR SEARCH
6.EXIT
*******************************************************************************/


#include <iostream>
using namespace std;

int main() {
    int arr[50];
    int n = 0, choice, pos, value, key;
    bool found;

    while (1) {
        cout << "\nMENU";
        cout << "\n1. CREATE";
        cout << "\n2. DISPLAY";
        cout << "\n3. INSERT";
        cout << "\n4. DELETE";
        cout << "\n5. LINEAR SEARCH";
        cout << "\n6. EXIT";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            cout << "Enter number of elements: ";
            cin >> n;
            for (int i = 0; i < n; i++) {
                cin >> arr[i];
            }
            break;

        case 2:
            for (int i = 0; i < n; i++) {
                cout << arr[i] << " ";
            }
            break;

        case 3:
            cout << "Enter position and value: ";
            cin >> pos >> value;
            for (int i = n; i > pos; i--) {
                arr[i] = arr[i - 1];
            }
            arr[pos] = value;
            n++;
            break;

        case 4:
            cout << "Enter position to delete: ";
            cin >> pos;
            for (int i = pos; i < n - 1; i++) {
                arr[i] = arr[i + 1];
            }
            n--;
            break;

        case 5:
            found = false;
            cout << "Enter element to search: ";
            cin >> key;
            for (int i = 0; i < n; i++) {
                if (arr[i] == key) {
                    cout << "Element found at position " << i;
                    found = true;
                    break;
                }
            }
            if (!found)
                cout << "Element not found";
            break;

        case 6:
            return 0;

        default:
            cout << "Invalid choice";
        }
    }
}

