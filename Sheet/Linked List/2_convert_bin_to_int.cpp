#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

int getDecimalValue(ListNode *head)
{
    ListNode *curr = head;
    int res = 0;
    while (curr)
    {
        res = res * 2 + curr->val;
        curr = curr->next;
    }
    return res;
}