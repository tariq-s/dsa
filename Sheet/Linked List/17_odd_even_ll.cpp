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

ListNode *oddEvenList(ListNode *head)
{
    ListNode *odd = new ListNode(-1);
    ListNode *odd_tail = odd;

    ListNode *even = new ListNode(-1);
    ListNode *even_tail = even;

    ListNode *curr = head;
    bool is_odd = true;
    while (curr)
    {
        ListNode *next = curr->next;
        curr->next = NULL;

        if (is_odd)
        {
            odd_tail->next = curr;
            odd_tail = curr;
        }
        else
        {
            even_tail->next = curr;
            even_tail = curr;
        }
        is_odd = !is_odd;
        curr = next;
    }

    odd_tail->next = even->next;
    return odd->next;
}