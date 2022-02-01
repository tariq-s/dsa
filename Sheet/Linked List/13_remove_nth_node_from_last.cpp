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

int length(ListNode *head)
{
    int res = 0;
    while (head)
    {
        head = head->next;
        res++;
    }
    return res;
}
ListNode *removeNthFromEnd(ListNode *head, int n)
{
    if (!head || !head->next)
        return NULL;
    if (length(head) == n)
        return head->next;
    ListNode *curr = head;
    ListNode *forward = head;
    for (int i = 0; i <= n; i++)
        forward = forward->next;

    while (forward)
    {
        forward = forward->next;
        curr = curr->next;
    }
    curr->next = curr->next->next;
    return head;
}