#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *mergeNodes(ListNode *head)
    {
        if (head == nullptr)
            return nullptr;
        if (!head->next->val)
        {
            ListNode *node = new ListNode(head->val);
            node->next = mergeNodes(head->next->next);
            return node;
        }

        ListNode *next = mergeNodes(head->next);
        next->val += head->val;
        return next;
    }
};