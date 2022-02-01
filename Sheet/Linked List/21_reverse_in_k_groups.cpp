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
        res++;
        head = head->next;
    }
    return res;
}
ListNode *reverseKGroup(ListNode *head, int k)
{
    int n = length(head);
    int N = n - n % k;

    ListNode *dummy = new ListNode(-1);
    ListNode *tail = dummy;

    ListNode *curr = new ListNode(-1);
    ListNode *curr_t = curr;

    ListNode *prev = NULL;
    ListNode *p = head;
    ListNode *next;

    int i = 0;
    while (i < N)
    {
        for (int j = 0; j < k; j++)
        {
            next = p->next;
            p->next = NULL;

            if (!curr->next)
            {
                curr->next = p;
                curr_t = p;
            }
            else
            {
                p->next = curr->next;
                curr->next = p;
            }

            i++;
            p = next;
        }

        if (!prev)
        {
            dummy->next = curr->next;
        }
        else
        {
            prev->next = curr->next;
        }
        prev = curr_t;
        curr->next = NULL;
    }
    prev->next = p;
    return dummy->next;
}