#include <iostream>
#include <string>
#include <vector>
using namespace std;

string keypad[10] = {".;", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tu", "vwx", "yz"};

vector<string> getKPC(string s)
{
    if (s.size() == 0)
    {
        vector<string> ans = {""};
        return ans;
    }
    vector<string> ans1 = getKPC(s.substr(1));
    int curr_key = s[0] - '0';
    string chars = keypad[curr_key];
    vector<string> ans;
    for (char c : chars)
    {
        for (string a : ans1)
        {
            ans.push_back(c + a);
        }
    }
    return ans;
}

int main()
{
    string s;
    cin >> s;
    vector<string> ans = getKPC(s);
    int cnt = 0;

    cout << '[';
    for (string str : ans)
    {
        if (cnt != ans.size() - 1)
            cout << str << ", ";
        else
            cout << str;
        cnt++;
    }
    cout << ']';
}