#include <bits/stdc++.h>
using namespace std;

int numPairsDivisibleBy60(vector<int> &time)
{
    unordered_map<int, int> hash;
    for (int t : time)
    {
        hash[t % 60]++;
    }
    int count = 0;
    for (auto it : hash)
    {
        if (it.first != 0 && it.first != 30)
        {
            if (hash.find(60 - it.first) != hash.end())
            {
                count += hash[it.first] * hash[60 - it.first];
                hash[it.first] = 0;
                hash[60 - it.first] = 0;
            }
        }
    }
    if (hash.find(0) != hash.end() && hash[0] > 1)
    {
        count += (hash[0] * (hash[0] - 1)) / 2;
    }
    if (hash.find(30) != hash.end() && hash[30] > 1)
    {
        count += (hash[30] * (hash[30] - 1)) / 2;
    }

    return count;
}