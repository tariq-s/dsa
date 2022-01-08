#include <bits/stdc++.h>
using namespace std;

class RandomizedSet
{
private:
    unordered_map<int, int> hash;
    vector<int> list;

public:
    bool insert(int val)
    {
        if (hash.find(val) != hash.end())
            return false;
        hash[val] = list.size();
        list.push_back(val);
        return true;
    }

    bool remove(int val)
    {
        if (hash.find(val) == hash.end())
            return false;
        int last = list.back();
        hash[last] = hash[val];
        list[hash[val]] = last;
        list.pop_back();
        hash.erase(val);
        return true;
    }

    int getRandom()
    {
        return list[rand() % list.size()];
    }
};