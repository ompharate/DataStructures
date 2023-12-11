#include <stack>
#include <iostream>
using namespace std;

bool Check(string str)
{
    stack<char> temp;

    for (int i = 0; i < str.size(); i++)
    {
        char ch = str[i];

        if (ch == '{' || ch == '(' || ch == '[')
        {
            temp.push(ch);
        }
        else if (ch == '}' || ch == ')' || ch == ']')
        {
            if (temp.empty())
            {
                cout << "Expression not valid" << endl;
                return false;
            }

            char top = temp.top();
            temp.pop();

            if ((ch == '}' && top != '{') || (ch == ')' && top != '(') || (ch == ']' && top != '['))
            {
                cout << "Expression not valid" << endl;
                return false;
            }
        }
    }

    if (temp.empty())
    {
        cout << "Expression is valid" << endl;
        return true;
    }
    else
    {
        cout << "Expression not valid" << endl;
        return false;
    }
}

int main()
{
    string str;
    cout << "Enter the expression: ";
    cin >> str;

    Check(str);

    return 0;
}
