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

ListNode *swapPairs(ListNode *head)
{
    if (!head || !head->next)
        return head;
    ListNode *curr = head;
    ListNode *prev = NULL;
    head = curr->next;
    while (curr && curr->next)
    {
        ListNode *next = curr->next->next;
        ListNode *curr2 = curr->next;

        curr->next = next;
        curr2->next = curr;
        if (prev)
            prev->next = curr2;

        prev = curr;
        curr = next;
    }
    return head;
}