/*******************************************************************************************
1. Develop a menu driven program demonstrating the following operations on a Stack using array:
(i) push(), (ii) pop(), (iii) isEmpty(), (iv) isFull(), (v) display(), and (vi) peek().
2. Given a string, reverse it using STACK. For example “DataStructure” should be output as
“erutcurtSataD.”
3. Write a program that checks if an expression has balanced parentheses.
4. Write a program to convert an Infix expression into a Postfix expression.
5. Write a program for the evaluation of a Postfix expression.
************************************************************************************************/
#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

#define MAX 100

//  STACK USING ARRAY 

class Stack {
    int arr[MAX];
    int top;

public:
    Stack() { top = -1; }

    bool isEmpty() { return top == -1; }

    bool isFull() { return top == MAX - 1; }

    void push(int x) {
        if (isFull())
            cout << "Stack Overflow!\n";
        else
            arr[++top] = x;
    }

    int pop() {
        if (isEmpty()) {
            cout << "Stack Underflow!\n";
            return -1;
        }
        return arr[top--];
    }

    int peek() {
        if (isEmpty()) {
            cout << "Stack is Empty!\n";
            return -1;
        }
        return arr[top];
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is Empty!\n";
            return;
        }
        for (int i = top; i >= 0; i--)
            cout << arr[i] << " ";
        cout << endl;
    }
};

//  REVERSE STRING USING STACK 

void reverseString() {
    Stack s;
    char str[MAX];

    cout << "Enter string: ";
    cin >> str;

    for (int i = 0; str[i] != '\0'; i++)
        s.push(str[i]);

    cout << "Reversed String: ";
    while (!s.isEmpty())
        cout << char(s.pop());
    cout << endl;
}

// BALANCED PARENTHESES 

bool isMatchingPair(char a, char b) {
    if (a == '(' && b == ')') return true;
    if (a == '{' && b == '}') return true;
    if (a == '[' && b == ']') return true;
    return false;
}

void checkBalanced() {
    Stack s;
    char expr[MAX];

    cout << "Enter expression: ";
    cin >> expr;

    for (int i = 0; expr[i]; i++) {
        if (expr[i] == '(' || expr[i] == '{' || expr[i] == '[')
            s.push(expr[i]);
        else if (expr[i] == ')' || expr[i] == '}' || expr[i] == ']') {
            if (s.isEmpty() || !isMatchingPair(char(s.pop()), expr[i])) {
                cout << "Not Balanced!\n";
                return;
            }
        }
    }

    if (s.isEmpty())
        cout << "Balanced Expression!\n";
    else
        cout << "Not Balanced!\n";
}

// INFIX TO POSTFIX 

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}

void infixToPostfix() {
    Stack s;
    char infix[MAX], postfix[MAX];
    int k = 0;

    cout << "Enter Infix Expression: ";
    cin >> infix;

    for (int i = 0; infix[i]; i++) {

        if (isalnum(infix[i]))
            postfix[k++] = infix[i];

        else if (infix[i] == '(')
            s.push(infix[i]);

        else if (infix[i] == ')') {
            while (!s.isEmpty() && s.peek() != '(')
                postfix[k++] = char(s.pop());
            s.pop();
        }

        else {
            while (!s.isEmpty() &&
                   precedence(infix[i]) <= precedence(s.peek()))
                postfix[k++] = char(s.pop());
            s.push(infix[i]);
        }
    }

    while (!s.isEmpty())
        postfix[k++] = char(s.pop());

    postfix[k] = '\0';

    cout << "Postfix Expression: " << postfix << endl;
}

// POSTFIX EVALUATION 

int evaluatePostfix() {
    Stack s;
    char postfix[MAX];

    cout << "Enter Postfix Expression: ";
    cin >> postfix;

    for (int i = 0; postfix[i]; i++) {

        if (isdigit(postfix[i]))
            s.push(postfix[i] - '0');

        else {
            int val2 = s.pop();
            int val1 = s.pop();

            switch (postfix[i]) {
                case '+': s.push(val1 + val2); break;
                case '-': s.push(val1 - val2); break;
                case '*': s.push(val1 * val2); break;
                case '/': s.push(val1 / val2); break;
            }
        }
    }

    return s.pop();
}


int main() {

    Stack s;
    int choice, val;

    do {
        cout << "\n----- STACK MENU -----\n";
        cout << "1. Push\n2. Pop\n3. isEmpty\n4. isFull\n5. Display\n6. Peek\n";
        cout << "7. Reverse String\n8. Check Balanced Parentheses\n";
        cout << "9. Infix to Postfix\n10. Evaluate Postfix\n0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {

            case 1:
                cout << "Enter value: ";
                cin >> val;
                s.push(val);
                break;

            case 2:
                cout << "Popped: " << s.pop() << endl;
                break;

            case 3:
                cout << (s.isEmpty() ? "Stack is Empty\n" : "Not Empty\n");
                break;

            case 4:
                cout << (s.isFull() ? "Stack is Full\n" : "Not Full\n");
                break;

            case 5:
                s.display();
                break;

            case 6:
                cout << "Top Element: " << s.peek() << endl;
                break;

            case 7:
                reverseString();
                break;

            case 8:
                checkBalanced();
                break;

            case 9:
                infixToPostfix();
                break;

            case 10:
                cout << "Result: " << evaluatePostfix() << endl;
                break;

            case 0:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid Choice!\n";
        }

    } while (choice != 0);

    return 0;
}
