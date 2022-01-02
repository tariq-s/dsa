#include <bits/stdc++.h>
using namespace std;

string check_duplicate_brackets(string s)
{
    stack<char> Stack;

    for (char c : s)
    {
        if (c != ')')
        {
            Stack.push(c);
        }
        else
        {
            int count = 0;
            while (Stack.top() != '(')
            {
                Stack.pop();
                count++;
            }
            if (count <= 1)
            {
                return "true";
            }
            Stack.pop();
        }
    }
    return "false";
}

int main(int argc, char **argv)
{
    string s;
    getline(cin, s);

    cout << check_duplicate_brackets(s);
    return 0;
}