#include <iostream>
using namespace std;

// q1 WAP to display "Hello World" on console
void question1() {
    cout << "Hello World" << endl;
}

// q2 WAP to implement control characters
void question2() {
    cout << "New Line Example\n";
    cout << "Tab\tExample\n";
    cout << "Alarm\a\n";
    cout << "Carriage Return Test\rHello\n";
}

// q3 Implement namespace to illustrate same variable and function names
namespace First {
    int x = 10;
    void show() {
        cout << "First namespace x = " << x << endl;
    }
}

namespace Second {
    int x = 20;
    void show() {
        cout << "Second namespace x = " << x << endl;
    }
}

void question3() {
    First::show();
    Second::show();
}

// q4 Structure Student with data members and functions Input and output 3 student records
struct StudentStruct {
    char name[20];
    int roll;
    float marks;

    void setStudentData() {
        cin >> name >> roll >> marks;
    }

    void getStudentData() {
        cout << name << " " << roll << " " << marks << endl;
    }
};

void question4() {
    StudentStruct s[3];

    for (int i = 0; i < 3; i++) {
        s[i].setStudentData();
    }

    for (int i = 0; i < 3; i++) {
        s[i].getStudentData();
    }
}

// q5 Make data members private and functions public
struct StudentPrivate {
private:
    char name[20];
    int roll;
    float marks;

public:
    void setStudentData() {
        cin >> name >> roll >> marks;
    }

    void getStudentData() {
        cout << name << " " << roll << " " << marks << endl;
    }
};

void question5() {
    StudentPrivate s[3];

    for (int i = 0; i < 3; i++) {
        s[i].setStudentData();
    }

    for (int i = 0; i < 3; i++) {
        s[i].getStudentData();
    }
}

// q6 Convert structure program to class
class StudentClass {
private:
    char name[20];
    int roll;
    float marks;

public:
    void setStudentData() {
        cin >> name >> roll >> marks;
    }

    void getStudentData() {
        cout << name << " " << roll << " " << marks << endl;
    }
};

void question6() {
    StudentClass s[3];

    for (int i = 0; i < 3; i++) {
        s[i].setStudentData();
    }

    for (int i = 0; i < 3; i++) {
        s[i].getStudentData();
    }
}

int main() {
//accordingly when running we shall uncomment the required function below

    // question1();
    // question2();
    // question3();
    // question4();
    // question5();
    // question6();

    return 0;
}
