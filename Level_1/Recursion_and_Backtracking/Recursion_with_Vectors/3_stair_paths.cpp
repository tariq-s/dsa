#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> get_stair_paths(int n)
{
    if (n < 0)
    {
        vector<string> ans;
        return ans;
    }
    if (n == 0)
    {
        vector<string> ans = {""};
        return ans;
    }
    vector<string> a1 = get_stair_paths(n - 1);
    vector<string> a2 = get_stair_paths(n - 2);
    vector<string> a3 = get_stair_paths(n - 3);

    vector<string> ans;
    for (int i = 0; i < a1.size(); i++)
    {
        ans.push_back("1" + a1[i]);
    }
    for (int i = 0; i < a2.size(); i++)
    {
        ans.push_back("2" + a2[i]);
    }
    for (int i = 0; i < a3.size(); i++)
    {
        ans.push_back("3" + a3[i]);
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<string> ans = get_stair_paths(n);
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