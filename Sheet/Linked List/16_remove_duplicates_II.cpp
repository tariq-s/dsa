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

ListNode *deleteDuplicates(ListNode *head)
{
    ListNode *d = new ListNode(-1);
    d->next = head;
    ListNode *curr = head;
    ListNode *prev = d;

    while (curr && curr->next)
    {
        if (curr->val != curr->next->val)
        {
            prev = curr;
            curr = curr->next;
            continue;
        }
        while (curr && curr->next && curr->val == curr->next->val)
        {
            curr = curr->next;
        }
        prev->next = curr->next;
        curr = curr->next;
    }
    return d->next;
}