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
    ListNode *doubleIt(ListNode *head)
    {
        if (getCarry(head) == 1)
            return new ListNode(1, head);
        return head;
    }

private:
    int getCarry(ListNode *node)
    {
        int val = node->val * 2;
        if (node->next != nullptr)
            val += getCarry(node->next);

        node->val = val % 10;
        return val / 10;
    }
};