#include <bits/stdc++.h>
using namespace std;

int sum_squares(int x) {
       int n = log10(x) + 1;
        int res = 0;
        while(n) {
            int d = (int)(x / pow(10, n - 1)) % 10;
            res += d * d;
            n--;
        }
        return res;
    }
    bool isHappy(int n) {
        if(n == 0) return false;
        if(n == 1) return true;
        int x = n;
        unordered_map<int, bool> map;
        map[x] = true;
        while(true) {
            x = sum_squares(x);
            if(x == 1)
                return true;
            if(map.find(x) != map.end())
                return false;
            map[x] = true;
        }
    }