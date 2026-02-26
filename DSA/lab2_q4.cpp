/******************************************************************************
- String Related Programs
(a) Write a program to concatenate one string to another string.
(b) Write a program to reverse a string.
(c) Write a program to delete all the vowels from the string.
(d) Write a program to sort the strings in alphabetical order.
(e) Write a program to convert a character from uppercase to lowercase.

*******************************************************************************/

#include <iostream>
#include <cstring>
using namespace std;

// concatenate strings
void concatenate(char s1[], char s2[]) {
    strcat(s1, s2);
    cout << s1 << endl;
}

// reverse string
void reverseString(char s[]) {
    int n = strlen(s);
    for (int i = 0; i < n / 2; i++) {
        char temp = s[i];
        s[i] = s[n - i - 1];
        s[n - i - 1] = temp;
    }
    cout << s << endl;
}

// remove vowels
void removeVowels(char s[]) {
    char result[100];
    int k = 0;
    for (int i = 0; s[i]; i++) {
        char c = s[i];
        if (!(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||
              c=='A'||c=='E'||c=='I'||c=='O'||c=='U')) {
            result[k++] = c;
        }
    }
    result[k] = '\0';
    cout << result << endl;
}

// sort strings
void sortStrings(char s[][20], int n) {
    char temp[20];
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (strcmp(s[i], s[j]) > 0) {
                strcpy(temp, s[i]);
                strcpy(s[i], s[j]);
                strcpy(s[j], temp);
            }
        }
    }

    for (int i = 0; i < n; i++)
        cout << s[i] << endl;
}

// uppercase to lowercase
char toLower(char c) {
    if (c >= 'A' && c <= 'Z')
        return c + 32;
    return c;
}

int main() {
    char s1[50] = "Hello";
    char s2[] = "World";
    concatenate(s1, s2);

    char s3[] = "Programming";
    reverseString(s3);

    char s4[] = "Education";
    removeVowels(s4);

    char words[3][20] = {"banana", "apple", "cherry"};
    sortStrings(words, 3);

    cout << toLower('A');

    return 0;
}
