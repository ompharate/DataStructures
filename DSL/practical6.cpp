#include <iostream>
#include <string>
#include <cctype>
using namespace std;

#define MAX_SIZE 100

class Stack
{
private:
    char data[MAX_SIZE];
    int top;

public:
    Stack()
    {
        top = -1;
    }

    void push(char value)
    {
        if (top < MAX_SIZE - 1)
        {
            cout << value << ": is pushed into the stack" << endl;
            top++;
            data[top] = value;
        }
        else
        {
            cout << "Stack Full" << endl;
        }
    }

    char pop()
    {
        if (top >= 0)
        {
            char poppedValue = data[top];
            top--;
            return poppedValue;
        }
        else
        {
            cerr << "Stack Empty" << endl;
            return '\0';
        }
    }

    bool isEmpty() { return top == -1; }
};

bool isPalindrome(string str)
{
    Stack charStack;

    string processedStr;
    for (char c : str)
    {
        if (isalpha(c))
        {
            processedStr += tolower(c);
        }
    }

    for (char c : processedStr)
    {
        charStack.push(c);
    }

    string reversed;
    while (!charStack.isEmpty())
    {
        reversed += charStack.pop();
    }

    return processedStr == reversed;
}

int main()
{
    string input;

    cout << "Enter a string: ";
    getline(cin, input);

    if (isPalindrome(input))
    {
        cout << "The string is a palindrome." << endl;
    }
    else
    {
        cout << "The string is not a palindrome." << endl;
    }

    return 0;
}
