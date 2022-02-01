#include <bits/stdc++.h>
using namespace std;

struct comparator
{
    bool operator()(ListNode *p1, ListNode *p2)
    {
        return p1->val > p2->val;
    }
};

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *mergeKLists(vector<ListNode *> &lists)
{
    int n = lists.size();
    if (n == 0)
        return NULL;
    priority_queue<ListNode *, vector<ListNode *>, comparator> heap;

    for (int i = 0; i < n; i++)
    {
        if (lists[i])
            heap.push(lists[i]);
    }

    ListNode *head = new ListNode(-1);
    ListNode *tail = head;

    while (!heap.empty())
    {
        ListNode *x = heap.top();
        heap.pop();
        if (x->next)
            heap.push(x->next);
        x->next = NULL;

        tail->next = x;
        tail = x;
    }
    return head->next;
}