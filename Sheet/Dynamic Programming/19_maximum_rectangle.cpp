#include <bits/stdc++.h>
using namespace std;

int largest_hist_area(vector<int> arr) {
        int n = arr.size();
        vector<int> right(n);
        vector<int> left(n);
        stack<int> Stack;
        for(int i = n - 1; i >= 0; i--) {
            while(!Stack.empty() && arr[i] <= arr[Stack.top()]) {
                Stack.pop();
            }
            if(Stack.empty()) {
                right[i] = n;
            } else {
                right[i] = Stack.top();
            }
            Stack.push(i);
        }
        Stack = stack<int>();
        for(int i = 0; i < n; i++) {
            while(!Stack.empty() && arr[i] <= arr[Stack.top()]) {
                Stack.pop();
            }
            if(Stack.empty()) {
                left[i] = -1;
            } else {
                left[i] = Stack.top();
            }
            Stack.push(i);
        }
        
        int res = 0;
        for(int i = 0; i < n; i++) {
            res = max(res, (right[i] - left[i] - 1) * arr[i]);
        }
        return res;
        
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> dp(m);
        for(int i = 0; i < m; i++) {
            dp[i] = matrix[0][i] == '1';
        }
        int res = largest_hist_area(dp);
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(matrix[i][j] == '1') {
                    dp[j] += 1;
                } else {
                    dp[j] = 0;
                }
            }
            res = max(res, largest_hist_area(dp));
        }
        return res;
    }