#include <bits/stdc++.h>
using namespace std;

void longestConsecutive(vector<int> &num)
{

    int n = num.size();

    map<int, bool> hashmap;
    for (auto ele : num)
    {
        hashmap[ele] = true;
    }

    int count, ans = INT_MIN, ans_begin;
    for (int ele : num)
    {
        if (hashmap.find(ele - 1) == hashmap.end())
        {
            count = 0;
            while (hashmap.find(ele + count) != hashmap.end())
            {
                count++;
            }
            if (count > ans)
            {
                ans = count;
                ans_begin = ele;
            }
        }
    }

    for (int i = 0; i < ans; i++)
    {
        cout << ans_begin + i << endl;
    }
}

int main()
{
    vector<int> arr;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int data;
        cin >> data;
        arr.push_back(data);
    }
    longestConsecutive(arr);

    return 0;
}