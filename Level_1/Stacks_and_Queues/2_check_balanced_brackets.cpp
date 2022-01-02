#include <bits/stdc++.h>
using namespace std;

string check_balanced_brackets(string s)
{
    stack<char> Stack;

    for (char c : s)
    {
        if (c != ')' && c != '}' && c != ']')
        {
            Stack.push(c);
        }
        else
        {
            if (Stack.size() == 0)
                return "false";
            if (c == ')')
            {
                while (Stack.top() != '(')
                {
                    Stack.pop();
                }
            }
            else if (c == '}')
            {
                while (Stack.top() != '{')
                {
                    Stack.pop();
                }
            }
            else if (c == ']')
            {
                while (Stack.top() != '[')
                {
                    Stack.pop();
                }
            }
            Stack.pop();
        }
    }
    return Stack.size() == 0 ? "true" : "false";
}

int main(int argc, char **argv)
{
    string s;
    getline(cin, s);

    cout << check_balanced_brackets(s);
    return 0;
}