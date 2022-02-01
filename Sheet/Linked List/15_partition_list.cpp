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

ListNode *partition(ListNode *head, int x)
{
    ListNode *before = new ListNode(-1);
    ListNode *before_t = before;
    ListNode *after = new ListNode(-1);
    ListNode *after_t = after;
    ListNode *curr = head;

    while (curr)
    {
        ListNode *next = curr->next;
        curr->next = NULL;

        if (curr->val < x)
        {
            before_t->next = curr;
            before_t = curr;
        }
        else
        {
            after_t->next = curr;
            after_t = curr;
        }

        curr = next;
    }
    before_t->next = after->next;
    return before->next;
}