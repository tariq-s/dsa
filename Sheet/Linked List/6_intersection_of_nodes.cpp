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

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    ListNode *A = headA;
    ListNode *B = headB;

    while (A && B && A != B)
    {
        A = A->next;
        B = B->next;
        if (A == B)
            return A;
        if (A == NULL)
            A = headB;

        if (B == NULL)
            B = headA;
    }
    return A;
}