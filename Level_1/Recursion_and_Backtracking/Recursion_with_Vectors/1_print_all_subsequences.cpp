#include <iostream>
#include <vector>
using namespace std;

vector<string> gss(string s)
{
    if (s.size() == 0)
    {
        vector<string> ans = {""};
        return ans;
    }
    vector<string> ans1 = gss(s.substr(1));
    vector<string> ans(ans1);
    for (int i = 0; i < ans1.size(); i++)
        ans.push_back(s[0] + ans1[i]);
    return ans;
}

int main()
{
    string s;
    cin >> s;
    vector<string> ans = gss(s);
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