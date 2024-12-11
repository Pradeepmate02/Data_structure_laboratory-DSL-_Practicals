#include <iostream>
#include <string>
using namespace std;

class Stack {
    int top;
    char arr[100];
public:
    Stack() {
        top = -1;
    }
    bool isFull() {
        return top == (sizeof(arr) / sizeof(arr[0])) - 1;
    }
    bool isEmpty() {
        return top == -1;
    }
    void push(char data) {
        if (isFull()) {
            cout << "\nStack is full";
            return;
        }
        arr[++top] = data;
    }
    char pop() {
        if (isEmpty()) {
            cout << "\nStack is empty";
            return '\0';
        }
        return arr[top--];
    }
    char peek() {
        if (isEmpty()) {
            cout << "\nStack is empty";
            return '\0';
        }
        return arr[top];
    }
};

bool isPalin(string str) {
    Stack s;
    for (char ch : str) {
        s.push(ch);
    }
    string reversed;
    int i = 0;
    while (!s.isEmpty()) {
        char ch = s.pop();
        reversed += ch;
        while (i < str.length() && str[i] == ' ') {
            i++;
        }
        if (ch != str[i++]) {
            return false;
        }
    }
    cout << "Reversed string: " << reversed << endl;  
    return true;
}



int main() {
    string str;
        cout << " Check if the string is a palindrome\n";
        
                cout << "Enter a string: ";
                getline(cin, str);
                if (isPalin(str)) {
                    cout << "Yes, it's a palindrome.\n";
                } else {
                    cout << "No, it's not a palindrome.\n";
                }
              
    return 0;
}
