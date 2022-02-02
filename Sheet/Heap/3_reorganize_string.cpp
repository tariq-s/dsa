#include <bits/stdc++.h>
using namespace std;

string reorganizeString(string s)
{
    unordered_map<char, int> map;
    for (char c : s)
        map[c]++;

    priority_queue<pair<int, char>> heap;
    for (auto entry : map)
    {
        heap.push({entry.second, entry.first});
    }
    string output = "";
    while (heap.size() > 1)
    {
        pair<int, char> char1 = heap.top();
        heap.pop();
        pair<int, char> char2 = heap.top();
        heap.pop();

        output += char1.second;
        char1.first -= 1;

        output += char2.second;
        char2.first -= 1;

        if (char1.first != 0)
            heap.push(char1);

        if (char2.first != 0)
            heap.push(char2);
    }
    if (heap.size() == 1 && heap.top().first != 1)
    {
        return "";
    }
    else if (heap.size() == 1 && heap.top().first == 1)
    {
        output += heap.top().second;
    }
    return output;
}