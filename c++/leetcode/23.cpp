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
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        auto cmp = [](ListNode *a, ListNode *b)
        {
            return a->val > b->val;
        };
        priority_queue<ListNode *, vector<ListNode *>, decltype(cmp)> pq(cmp);
        for (auto list : lists)
        {
            if (list)
                pq.push(list);
        }
        ListNode dummy(0);
        ListNode *curr = &dummy;
        while (!pq.empty())
        {
            auto node = pq.top();
            pq.pop();
            curr->next = node;
            curr = curr->next;
            if (node->next)
                pq.push(node->next);
        }
        return dummy.next;
    }
};