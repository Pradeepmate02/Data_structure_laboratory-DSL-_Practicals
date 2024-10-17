#include <iostream>
#include <string>
using namespace std;

class Stack
{
    int top;
    char arr[100];

public:
    Stack()
    {
        top = -1;
    }
    bool isFull()
    {
        return top == (sizeof(arr) / sizeof(arr[0])) - 1;
    }
    bool isEmpty()
    {
        return top == -1;
    }
    void push(char data)
    {
        if (isFull())
        {
            cout << "\nStack is full";
            return;
        }
        arr[++top] = data;
    }
    char pop()
    {
        if (isEmpty())
        {
            cout << "\nStack is empty";
            return '\0';
        }
        return arr[top--];
    }
    char peek()
    {
        if (isEmpty())
        {
            cout << "\nStack is empty";
            return '\0';
        }
        return arr[top];
    }
};

bool isWellP(string str)
{
    Stack s;
    for (char ch : str)
    {
        if (ch == '(' || ch == '{' || ch == '[')
        {
            s.push(ch);
        }
        else if (ch == ')')
        {
            if (s.peek() == '(')
            {
                s.pop();
            }
            else
            {
                return false;
            }
        }
        else if (ch == '}')
        {
            if (s.peek() == '{')
            {
                s.pop();
            }
            else
            {
                return false;
            }
        }
        else if (ch == ']')
        {
            if (s.peek() == '[')
            {
                s.pop();
            }
            else
            {
                return false;
            }
        }
    }
    return s.isEmpty();
}

int main()
{

    string str;

    cout << " Check if the string is well-parenthesized\n";

    cout << "Enter an expression: ";
    cin >> str;
    if (isWellP(str))
    {
        cout << "The expression is well-parenthesized.\n";
    }
    else
    {
        cout << "The expression is not well-parenthesized.\n";
    }

    return 0;
}
